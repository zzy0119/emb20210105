#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ch;

	while (1) {
		ch = getopt(argc, argv, "-lahi:m::");
		if (-1 == ch)
			break;
		switch (ch) {
			case 'l':
				printf("get -l...\n");
				break;
			case 'a':
				printf("get -a...\n");
				break;
			case 'h':
				printf("get -h...\n");
				break;
			case 'i':
				printf("get -i...\n");
				if (optarg != NULL) {
					printf("arg:%s\n", optarg);	
				} else
					fprintf(stderr, "required arguments\n");
				break;
			case 'm':
				printf("get -m...\n");
				if (optarg != NULL)
					printf("arg:%s\n", optarg);
				break;
			case 1:
				printf("not option argument...\n");
				break;
			case '?':
				printf("i don't know\n");
				break;
			default:
				break;
		}
	}

	return 0;
}

