/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:59:28 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/14 21:50:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_check(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char		*ft_newline(char **str)
{
	char	*buffer;
	char	*newline;
	char	*temp;

	buffer = ft_strchr_gnl(*str, '\n');
	temp = NULL;
	if (buffer)
	{
		if (!(newline = ft_strndup_gnl(*str, buffer - (*str))))
			return (NULL);
		temp = *str;
		if (!(*str = ft_strdup_gnl(buffer + 1)))
			return (NULL);
		free(temp);
	}
	else if (!(newline = ft_strdup_gnl(*str)))
		return (NULL);
	if (!(*str) || !temp)
	{
		free(*str);
		*str = NULL;
	}
	return (newline);
}

char		*ft_read(int fd, char *buffer, char **str)
{
	int		ret;
	char	*temp;

	ret = 1;
	temp = NULL;
	while ((ft_check(*str) == 0) && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		temp = *str;
		buffer[ret] = '\0';
		if (!(*str = ft_strjoin_gnl(*str, buffer)))
			return (NULL);
		free(temp);
	}
	free(buffer);
	return (*str);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[1024];
	char		*buffer;
	char		*end;

	if (fd < 0 || fd > 1023 || (str[fd] == NULL && !(str[fd] = ft_strnew(0)))
		|| !(buffer = ft_strnew(BUFFER_SIZE + 1)) || BUFFER_SIZE < 1
		|| read(fd, buffer, 0) == -1 || !(*line = ft_strnew(0))
		|| !(ft_read(fd, buffer, &str[fd])))
		return (-1);
	if (*str[fd])
	{
		end = ft_strchr_gnl(str[fd], '\n');
		free(*line);
		if (!(*line = ft_newline(&str[fd])))
			return (-1);
		if (!end)
		{
			free(str[fd]);
			str[fd] = NULL;
			return (0);
		}
		return (1);
	}
	return (0);
}

int			get_next_line1(const int fd, char **line)
{
	static char	*str1;
	char		*buffer;
	char		*end;

	if (fd < 0 || (str1 == NULL && !(str1 = ft_strnew(0)))
		|| !(buffer = ft_strnew(BUFFER_SIZE + 1)) || BUFFER_SIZE < 1
		|| read(fd, buffer, 0) == -1 || !(*line = ft_strnew(0))
		|| !(ft_read(fd, buffer, &str1)))
		return (-1);
	if (*str1)
	{
		end = ft_strchr_gnl(str1, '\n');
		free(*line);
		if (!(*line = ft_newline(&str1)))
			return (-1);
		if (!end)
		{
			free(str1);
			str1 = NULL;
			return (0);
		}
		return (1);
	}
	return (0);
}
