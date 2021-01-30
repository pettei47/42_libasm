#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#include "libasm.h"

#define BUF_SIZE (15)

void	test_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
	{
		fprintf(stderr, BOLDRED);
		fprintf(stderr, "libc :when the arg is NULL\n");
		fprintf(stderr, RESET);
		strcmp(s1, s2);
	}
	printf("--strcmp("BOLD"\"%s\", \"%s\""RESET")--\n", s1, s2);
	int ret_asm = ft_strcmp(s1, s2);
	int	ret_libc = strcmp(s1, s2);
	printf((ret_libc == ret_asm) ? GREEN : RED);
	printf("libasm: %d\n", ret_asm);
	printf("libc  : %d\n", ret_libc);
	printf(RESET);
}

int	ret_0(void)
{
	return 0;
}

int	main(int argc, char **argv)
{
	printf("\n==============\n=== strcmp ===\n==============\n");
	if (argc == 3)
	{
		if (!strcmp("NULL", argv[1]))
			test_strcmp(NULL, argv[2]);
		if (!strcmp("NULL", argv[2]))
			test_strcmp(argv[1], NULL);
		test_strcmp(argv[1], argv[2]);
	}
	test_strcmp("test", "test");
	test_strcmp("a", "a");
	test_strcmp("", "");
	test_strcmp("test0'", "test0");
	test_strcmp("test0", "test0'");
	test_strcmp("test0", "test1");
	test_strcmp("test", "Test");
	test_strcmp("Test", "test");
	test_strcmp("test", "");
	test_strcmp("", "test");
	test_strcmp("\xff\xff", "\xff");
}

