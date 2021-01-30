/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:02:12 by kdoi              #+#    #+#             */
/*   Updated: 2021/01/30 20:36:17 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBASM_H
# define LIBASM_H

# include <sys/types.h>
# include <errno.h>

# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define BOLDBLACK		"\033[1m\033[30m"
# define BOLDRED		"\033[1m\033[31m"
# define BOLDGREEN		"\033[1m\033[32m"
# define BOLDYELLOW		"\033[1m\033[33m"
# define BOLDBLUE		"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define BOLDCYAN		"\033[1m\033[36m"
# define BOLDWHITE		"\033[1m\033[37m"

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);

ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbytes);
char		*ft_strdup(const char *s1);

#endif