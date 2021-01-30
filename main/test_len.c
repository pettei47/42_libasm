#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#include "libasm.h"

#define BUF_SIZE (15)

void	test_strlen(char *str)
{
	size_t ret_libc;
	size_t ret_libasm;

	if (!str)
	{
		fprintf(stderr, BOLDRED);
		fprintf(stderr, "libc :when the arg is NULL\n");
		fprintf(stderr, RESET);
		strlen(str);
	}
	ret_libasm = ft_strlen(str);
	ret_libc = strlen(str);
	printf("--\""BOLD"%s"RESET"\"--\n", str);
	printf((ret_libc == ret_libasm) ? GREEN : RED);
	printf("libasm: %zu\n", ret_libasm);
	printf("libc  : %zu\n", ret_libc);
	printf(RESET);
}

int	ret_0(void)
{
	return 0;
}

int	main(int argc, char **argv)
{
	printf("==============\n=== strlen ===\n==============\n");
	if (argc == 2)
	{
		if (!strcmp("NULL", argv[1]))
			test_strlen(NULL);
		test_strlen(argv[1]);
	}
	test_strlen("test");
	test_strlen("");
	test_strlen("あいうえお");
}

