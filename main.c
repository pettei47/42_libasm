/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:33:02 by event             #+#    #+#             */
/*   Updated: 2021/02/04 00:12:57 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/libasm.h"
#include <string.h>

int main(void)
{
printf("==============ft_strlen==============\n\n");
printf("empty_string   -> %zd\n", ft_strlen(""));
printf("long_string    -> %zd\n", ft_strlen(LONG_STR));
//printf("null_string   -> %zd\n\n\n", ft_strlen(0));

char dest[2000];
printf("==============ft_strcpy==============\n\n");
printf("adress -> %p\n\n", dest);
printf("empty_string   -> %s\n", ft_strcpy(dest, ""));
printf("long_string    -> %s\n\n", ft_strcpy(dest, LONG_STR));
printf("adress -> %p\n\n\n", dest);
//printf("null_string   -> %s\n\n\n", ft_strcpy(0,"3232"));

printf("==============ft_strcmp==============\n\n");
printf("empty_str_both   -> %d\n", ft_strcmp("", ""));
printf("empty_str_first  -> %d\n", ft_strcmp("", "42tokyp"));
printf("empty_str_second -> %d\n", ft_strcmp("42tokyp", ""));
printf("same_str         -> %d\n", ft_strcmp("42", "42"));
//printf("ft_null_string   -> %d\n\n\n", ft_strcmp(0,0));

int	fd;
errno = 0;
fd = open("test.txt", O_RDWR);
printf("\n\n==============ft_write==============\n\n");
printf("stdout   -> %zd\n", ft_write(1, LONG_STR, ft_strlen(LONG_STR)));
printf("test.txt -> %zd\n", ft_write(fd, LONG_STR, ft_strlen(LONG_STR)));
printf("wrong_fd -> %zd\n", ft_write(42, LONG_STR, 1));
printf("error_message -> %s\n\n\n", strerror(errno));
close(fd);

printf("\n\n==============ft_read==============\n\n");
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

printf("\n\n==============ft_strdup==============\n\n");
char *dup;
dup = "before";
printf("empty_string   -> %s\n", ft_strdup(""));
printf("long_string    -> %s\n\n", ft_strdup(LONG_STR));
printf("\nadress_before   -> %p\n %s\n", dup, dup);
dup = ft_strdup("after");
printf("\nadress_after    -> %p\n %s\n", dup, dup);
printf("wrong_str   -> %s\n", ft_strdup(NULL));
printf("error_message -> %s\n\n\n", strerror(errno));

return (0);
}
