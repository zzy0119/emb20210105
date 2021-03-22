#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
	struct option opts[] = {
		{"help", no_argument, NULL, 'p'},
		{"test", optional_argument, NULL, 't'},
		{0, 0, 0, 0}
	};
	int c;

	while (1) {
		c = getopt_long(argc, argv, "hl", opts, NULL);
		if (-1 == c)
			break;
		switch (c) {
			case 'h':
				printf("get -h\n");
				break;
			case 'l':
				printf("get -l\n");
				break;
			case 'p':
				printf("get help\n");
				break;
			case 't':
				printf("get test\n");
				if (optarg != NULL)
					puts(optarg);
				break;
			case '?':
				printf("don't know\n");
				break;
			default:
				break;
		}
	}	


	return 0;
}

