/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:10:27 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/29 01:21:49 by rzafari42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
int			ft_check(char *str);
char		*ft_strnew_gnl(size_t size);
char		*ft_read(int fd, char *buffer, char **str);
char		*ft_newline(char **str);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
char		*ft_strdup_gnl(const char *s1);
char		*ft_strndup_gnl(const char *s1, size_t n);
char		*ft_strchr_gnl(const char *s, int c);
size_t		ft_strlen_gnl(const char *s);

#endif
