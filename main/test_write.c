#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#include "libasm.h"

#define BUF_SIZE (15)

void	test_write(int fd, char *str, size_t len)
{
	printf("--wirte("BOLD"%d, \"%s\", %zu"RESET")--\n", fd, str, len);
	// run libasm
	printf("libasm: "YELLOW);
	fflush(stdout);
	errno = 0;
	ssize_t ret_asm = ft_write(fd, str, len);
	int errno_asm = errno;
	printf(RESET"\n");

	// run libc
	printf("libc  : "YELLOW);
	fflush(stdout);
	errno = 0;
	ssize_t ret_libc = write(fd, str, len);
	int	errno_libc = errno;
	printf(RESET"\n");

	// evaluate
	printf((ret_libc == ret_asm && errno_libc == errno_asm) ? GREEN : RED);
	printf("libasm: ret=%zd errno=%d\n", ret_asm, errno_asm);
	printf("libc  : ret=%zd errno=%d\n", ret_libc, errno_libc);
	printf(RESET);
	errno = 0;
}

int	ret_0(void)
{
	return 0;
}

int	main(int argc, char **argv)
{
	write(42, "abc\n", 4);
	ft_write(42, "abc\n", 4);
	printf("\n==============\n=== write ====\n==============\n");
	test_write(1, "test", 4);
	test_write(1, "  ", 2);
	test_write(1, "", 1);
	test_write(1, "test", 2);
	test_write(1, "123456789", 9);
	// test_write(1, "123456789", 1000);
	int fd = open("test_wirte.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	test_write(fd, argc == 3 ? argv[2] : "test\n", 5);

	printf("\n~~~ error case ~~~\n");
	test_write(42, "test", 4);
	test_write(42, "a", 1);
	test_write(42, "", 1);
	test_write(42, "123456789", 9);
	test_write(fd, NULL, 2);
	test_write(-1, "tt", 2);
	test_write(1, "123456789", -1);
	// test_write(1, "", 2); // crush

	close(fd);
}

