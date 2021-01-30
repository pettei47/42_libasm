#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#include "libasm.h"

#define BUF_SIZE (15)

void	test_strdup(char *str)
{
	if (!str)
	{
		fprintf(stderr, BOLDRED);
		fprintf(stderr, "libc :when the arg is NULL\n");
		fprintf(stderr, RESET);
		strdup(str);
		return ;
	}
	if (!strcmp("malloc", str))
	{
		fprintf(stderr, BOLDRED);
		fprintf(stderr, "libc :when malloc error\n");
		fprintf(stderr, RESET);
		char	s[8380599];
		int i = 0;
		while (i < 10)
			s[i++] = 'a';
		strdup(s);
		return ;
	}
	printf("--strdup(\""BOLD"%s"RESET"\")--\n", str);
	// libc
	char *ret_libc = strdup(str);
	// libasm
	char *ret_asm = ft_strdup(str);

	printf((strcmp(ret_libc, ret_asm) == 0) ? GREEN : RED);
	printf("str   : %p : %-*s\n", &str, (int)strlen(str) + 3, str);
	printf("libasm: %p : %-*s\n", &ret_asm, (int)strlen(str) + 3, ret_asm);
	printf("libc  : %p : %-*s\n", &ret_libc, (int)strlen(str) + 3, ret_libc);
	printf(RESET);

	free(ret_libc);
	free(ret_asm);
	exit(EXIT_SUCCESS);
}

int	ret_0(void)
{
	return 0;
}

int	main(int argc, char **argv)
{
	printf("\n==============\n=== strdup ===\n==============\n");
	if (argc == 2)
	{
		if (!strcmp("NULL", argv[1]))
			test_strdup(NULL);
		test_strdup(argv[1]);
		return 0;
	}
	test_strdup("test");
	test_strdup("");
	exit(EXIT_SUCCESS);
}

