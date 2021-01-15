/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 08:44:11 by teppei            #+#    #+#             */
/*   Updated: 2021/01/15 08:47:17 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>

int	main(void)
{
#ifdef LEN
	printf("==============ft_strlen==============\n\n");
	printf("empty_string   -> %zd\n", ft_strlen(""));
	printf("long_string    -> %zd\n", ft_strlen(LONG_STR));
	printf("null_string   -> %zd\n\n\n", ft_strlen(0));
#endif


#ifdef CPY
	char dest[2000];
	printf("==============ft_strcpy==============\n\n");
	printf("adress -> %p\n\n", dest);
	printf("empty_string   -> %s\n", ft_strcpy(dest, ""));
	printf("long_string    -> %s\n\n", ft_strcpy(dest, LONG_STR));
	printf("adress -> %p\n\n\n", dest);
	printf("null_string   -> %s\n\n\n", ft_strcpy(0,"3232"));
#endif

#ifdef CMP
	printf("==============ft_strcmp==============\n\n");
	printf("empty_str_both   -> %d\n", ft_strcmp("", ""));
	printf("empty_str_firt  -> %d\n", ft_strcmp("", "42tokyp"));
	printf("empty_str_second -> %d\n", ft_strcmp("42tokyp", ""));
	printf("same_str         -> %d\n", ft_strcmp("42", "42"));
	printf("ft_null_string   -> %d\n\n\n", ft_strcmp(0,0));
#endif

#ifdef WRITE
	// printf("\n\n**************system_calls***************\n\n");
	int	fd;
	//char	buf[1000];
	errno = 0;
	fd = open("test.txt", O_RDWR);
	printf("\n\n==============ft_write==============\n\n");
	printf("stdout   -> %zd\n", ft_write(1, LONG_STR, ft_strlen(LONG_STR)));
	printf("test.txt -> %zd\n", ft_write(fd, LONG_STR, ft_strlen(LONG_STR)));
	printf("wrong_fd -> %zd\n", ft_write(42, LONG_STR, 1));
	printf("error_message -> %s\n\n\n", strerror(errno));
	close(fd);
#endif

#ifdef READ
	printf("\n\n==============ft_read==============\n\n");
	int	fd;
	char	buf[1000];
	errno = 0;
	fd = open("test.txt", O_RDWR);
	ssize_t rv = ft_read(0, buf, 15);
	buf[rv] = '\0';
	printf("stdin   -> %zd\n", rv);
	printf("buf = %s\n", buf);
	rv = ft_read(fd, buf, 4);
	buf[rv] = '\0';
	printf("test.txt   -> %zd\n", rv);
	printf("buf = %s\n", buf);
	rv = ft_read(fd, buf, 0);
	printf("wrong_fd   -> %zd\n", rv);
	printf("error_message -> %s\n\n\n", strerror(errno));
	close(fd);
#endif

#ifdef DUP
	printf("\n\n==============ft_strdup==============\n\n");
	char *dup;
	dup = "42_dup";
	printf("empty_string   -> %s\n", ft_strdup(""));
	printf("long_string    -> %s\n\n", ft_strdup(LONG_STR));
	printf("\nadress_before   -> %p\n %s\n", dup, dup);
	dup = ft_strdup("42");
	printf("\nadress_after    -> %p\n %s\n", dup, dup);
	printf("wrong_str   -> %s\n", ft_strdup(NULL));
	printf("error_message -> %s\n\n\n", strerror(errno));
#endif

	return (0);
}
