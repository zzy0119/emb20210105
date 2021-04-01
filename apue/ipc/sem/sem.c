/*
 调用进程将0写入"/tmp/out"文件，创建20进程，子进程
 读出文件中的数值+1再写回文件,文件中最终的值为多少
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <errno.h>

#define FLNAME	"/tmp/out"
#define PROCNR	20
#define BUFSIZE	10

static int semid;
static int V(void);
static int P(void);
int main(void)
{
	int fd;
	int cnt;
	pid_t pid;
	int ret;

	fd = open(FLNAME, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1) {
		perror("open()");
		exit(1);
	}
	write(fd, "0", 1);

	// 集合中有一个元素
	semid = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL | 0600);
	if (semid == -1) {
		perror("semget()");
		close(fd);
		exit(1);
	}
	semctl(semid, 0, SETVAL, 1); // 设置一个信号

	for (int i = 0; i < PROCNR; i++) {
		pid = fork();
		// if error
		if (pid == 0) {
			char buf[BUFSIZE] = {};
			ret = P(); // 取信号
			if (ret < 0) {
				fprintf(stderr, "P():%s\n", strerror(-ret));
				exit(1);
			}
			lseek(fd, 0, SEEK_SET);
			cnt = read(fd, buf, BUFSIZE);
			// if error;
			snprintf(buf, BUFSIZE, "%d", atoi(buf)+1);
			lseek(fd, 0, SEEK_SET);
			write(fd, buf, strlen(buf));
			// 还信号
			V();
			close(fd);
			exit(0);
		}
	}

	for (int i = 0; i < PROCNR; i++)
		wait(NULL);

	close(fd);

	exit(0);
}

static int P(void)
{
	struct sembuf buf;

	buf.sem_num = 0;
	buf.sem_op = -1;
	buf.sem_flg = 0;

	if (semop(semid, &buf, 1) == -1) {
		return -errno;	
	}
	return 0;
}

static int V(void)
{
	struct sembuf buf;

	buf.sem_num = 0;
	buf.sem_op = 1;
	buf.sem_flg = 0;

	if (semop(semid, &buf, 1) == -1) {
		return -errno;	
	}
	return 0;
}

