#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <shadow.h>


// getspnam(3)
// crypt(3)
// getpass(3)

int main(int argc, char *argv[])
{
	char *pass;
	struct spwd *sp;
	char *encrypt;

	if (argc < 2)
		return 1;

	// argv[1]--->username

	// 读密码
	pass = getpass("密码:");

	sp = getspnam(argv[1]);
	if (NULL == sp) {
		perror("getspnam()");
		return 1;
	}
	// 加密
	encrypt = crypt(pass, sp->sp_pwdp);
	if (NULL == encrypt)
		return 1;

	if (strcmp(sp->sp_pwdp, encrypt) == 0)
		printf("登录成功\n");
	else
		printf("密码错误\n");

	return 0;
}

