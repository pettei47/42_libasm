#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#include "libasm.h"

#define BUF_SIZE (15)

void	test_strcpy(int destsize, char *src)
{
	// make test buffers
	char *dst4libc = malloc((destsize + 1) * sizeof(char));
	memset(dst4libc, 'a', destsize);
	dst4libc[destsize] = 0;
	char *dst4libasm = malloc((destsize + 1) * sizeof(char));
	dst4libasm[destsize] = 0;
	memset(dst4libc, 'a', destsize);

	//crash
	if (!src)
		strcpy(dst4libc, src);
	if ((int)strlen(src) > destsize)
		strcpy(dst4libc, src);
	// testing
	printf("--"BOLD"\"%s\" <= \"%s\""RESET"--\n", dst4libc, src);
	char *ret_libasm = ft_strcpy(dst4libc, src);
	char *ret_libc = strcpy(dst4libc, src);
	printf((strcmp(ret_libc, ret_libasm) == 0) ? GREEN : RED);
	printf("libasm: %s\n", ret_libasm);
	printf("libc  : %s\n", ret_libc);
	printf(RESET);

	// destroy test buffers
	free(dst4libasm);
	free(dst4libc);
}

int	ret_0(void)
{
	return 0;
}

int	main(int argc, char **argv)
{
		printf("\n==============\n=== strcpy ===\n==============\n");
		if (argc == 2)
		{
			if (!strcmp("NULL", argv[1]))
			{
				fprintf(stderr, BOLDRED);
				fprintf(stderr, "libc :when the src is NULL\n");
				fprintf(stderr, RESET);
				test_strcpy(4, NULL);
			}
			if (!strcmp("less", argv[1]))
			{
				fprintf(stderr, BOLDRED);
				fprintf(stderr, "libc :when the dest is too short\n");
				fprintf(stderr, RESET);
				test_strcpy(1, "test");
			}
			test_strcpy(strlen(argv[1]), argv[1]);
		}
		test_strcpy(4, "test");
		test_strcpy(4, "A");
		test_strcpy(4, "");
		test_strcpy(1, "A");
		test_strcpy(0, "");
}

