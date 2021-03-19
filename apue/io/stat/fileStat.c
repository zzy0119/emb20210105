#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>

#define BUFSIZE	100

int main(int argc, char *argv[])
{
	struct stat res;

	if (argc < 2)
		return 1;

	if (stat(argv[1], &res) == -1) {
		perror("stat()");
		return 1;
	}

	// 类型
	if ((res.st_mode & S_IFMT) == S_IFREG)
		putchar('-');
	else if ((res.st_mode & S_IFMT) == S_IFDIR)
		putchar('d');

	// 权限
	if (res.st_mode & S_IRUSR)
		putchar('r');
	else
		putchar('-');
	if (res.st_mode & S_IWUSR)
		putchar('w');
	else
		putchar('-');
	if (res.st_mode & S_IXUSR) {
		if (res.st_mode & S_ISUID)
			putchar('s');
		else
			putchar('x');
	} else
		putchar('-');

	// 硬链接个数
	printf(" %ld ", res.st_nlink);

	// 拥有者和所属组
	struct passwd *p;
	p = getpwuid(res.st_uid);
	// p->pw_name
	struct group *g;
	g = getgrgid(res.st_gid);
	printf("%s %s ", p->pw_name, g->gr_name);

	// 字节大小
	printf("%ld ", res.st_size); // st_blocks磁盘空间大小

	// mtime
	struct tm *t;
	char buf[BUFSIZE] = {};
	t = localtime(&res.st_mtime/*time_t*/);
	// if error
	strftime(buf, BUFSIZE, "%m月 %d %H:%M", t);
	printf("%s ", buf);

	printf("%s", argv[1]);

	putchar('\n');

	return 0;
}

