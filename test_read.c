#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#include "libasm.h"

#define BUF_SIZE (15)

void	test_read(char *filepath, int size)
{
	printf("--%s, size:%d--\n", filepath, size);
	// run libasm
	int fd_asm = open(filepath, O_RDONLY);
	char *buf_asm = calloc(sizeof(char), size + 1);
	errno = 0;
	ssize_t ret_asm = ft_read(fd_asm, buf_asm, size);
	if (ret_asm >= 0)
		buf_asm[ret_asm] = 0;
	int	errno_asm = errno;
	// run libc
	int fd_libc = open(filepath, O_RDONLY);
	char *buf_libc = calloc(sizeof(char), size + 1);
	errno = 0;
	ssize_t ret_libc = read(fd_libc, buf_libc, size);
	if (ret_libc >= 0)
		buf_libc[ret_libc] = 0;
	int	errno_libc = errno;

	// evaluate
	int isSuccess = (strcmp(buf_libc, buf_asm) == 0 && ret_libc == ret_asm && errno_libc == errno_asm) ? 1 : 0;
	printf(isSuccess ? GREEN : RED);
	printf("libc  : fd=%d, buf=["YELLOW"%s%s], ret=%zd, errno=%d\n", fd_libc, buf_libc, isSuccess ? GREEN : RED, ret_libc, errno_libc);
	printf("libasm: fd=%d, buf=["YELLOW"%s%s], ret=%zd, errno=%d\n", fd_asm, buf_asm, isSuccess ? GREEN : RED, ret_asm, errno_asm);
	printf(RESET);

	// destroy
	free(buf_libc);
	close(fd_libc);
	free(buf_asm);
	close(fd_asm);
	errno = 0;
}

void	test_read_ex(int fd, char *buf_libc, char *buf_asm, int size)
{
	printf("--fd:%d, size:%d--\n", fd, size);
	// run libasm
	errno = 0;
	ssize_t ret_asm = ft_read(fd, buf_asm, size);
	buf_asm[BUF_SIZE] = 0;
	int	errno_asm = errno;
	// run libc
	errno = 0;
	ssize_t ret_libc = read(fd, buf_libc, size);
	buf_libc[BUF_SIZE] = 0;
	int	errno_libc = errno;

	// evaluate
	int isSuccess = (strcmp(buf_libc, buf_asm) == 0 && ret_libc == ret_asm && errno_libc == errno_asm) ? 1 : 0;
	printf(isSuccess ? GREEN : RED);
	printf("libasm: fd=%d, buf=["YELLOW"%s%s], ret=%zd, errno=%d\n", fd, buf_asm, isSuccess ? GREEN : RED, ret_asm, errno_asm);
	printf("libc  : fd=%d, buf=["YELLOW"%s%s], ret=%zd, errno=%d\n", fd, buf_libc, isSuccess ? GREEN : RED, ret_libc, errno_libc);
	printf(RESET);
	errno = 0;
}

int	ret_0(void)
{
	return 0;
}

int	main(int argc, char **argv)
{
	printf("\n==============\n===  read  ===\n==============\n");
	test_read("test.txt", 10);
	test_read("test.txt", 5);
	test_read("test.txt", 0);
	test_read("test.txt", 100);

	printf("\n~~~ error case ~~~\n");
	test_read("nothing.txt", 10);
	char *buf_libc = calloc(BUF_SIZE + 1, 1);
	char *buf_asm = calloc(BUF_SIZE + 1, 1);
	test_read_ex(-1, buf_libc, buf_asm, BUF_SIZE);
	if (argc == 2 && strcmp(argv[1], "read") == 0)
		test_read_ex(0, buf_libc, buf_asm, BUF_SIZE);
	bzero(buf_libc, BUF_SIZE+1);
	bzero(buf_asm, BUF_SIZE+1);
	int fd = open("test.txt", O_RDONLY);
	test_read_ex(fd, buf_libc, buf_asm, -1);
	// test_read_ex(fd, NULL, NULL, 10); // crash
	free(buf_libc);
	free(buf_asm);
	close(fd);
}

