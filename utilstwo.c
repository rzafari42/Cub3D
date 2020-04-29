/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 23:57:38 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/29 14:54:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_isdigit_cub(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_bzero_cub(void *s, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

void	*ft_calloc_cub(size_t count, size_t size)
{
	void		*str;
	size_t		mult;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	mult = count * size;
	if (!(str = malloc(mult)))
		return (NULL);
	ft_bzero_cub(str, mult);
	return (str);
}

char		*ft_strdup_cub(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	if (!(s2 = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s1[j])
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

unsigned long		convertrgbtoint(unsigned int r, unsigned int g,
					unsigned int b)
{
	unsigned long color;

	color = (r * pow(256, 2)) + (g * 256) + b;
	return (color);
}
