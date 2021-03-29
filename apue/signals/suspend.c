#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void handler1(int s)
{
	write(1, "!", 1);
}

static void handler2(int s)
{
	write(1, "#", 1);
}

int main(void)
{
	sigset_t set, oldset;
	struct sigaction act;

	act.sa_handler = handler1;
	act.sa_flags = 0;
	sigaction(SIGRTMIN+1, &act, NULL);

	signal(SIGINT, handler1);
	signal(SIGQUIT, handler2);

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);
	sigaddset(&set, SIGRTMIN+1);

	sigprocmask(SIG_BLOCK, &set, &oldset);

	for (int i = 0; i < 10; i++) {
		// 每一行期間不受SIGINT和SIGQUIT幹擾
		for (int j = 0; j < 5; j++) {
			write(1, "*", 1);
			sleep(1);
		}
		write(1, "\n", 1);
		sigsuspend(&oldset);
		/*
		 sigprocmask(SIG_BLOCK, &oldset, &set);
		 pause();
		 sigprocmask(SIG_SETMASK, &set, NULL);	 
		 */
	}


	exit(0);
}

