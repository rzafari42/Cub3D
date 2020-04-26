/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:49:25 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/24 01:46:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp_cub(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft_memcpy_cub(void *dst, const void *src, int n)
{
	int					i;
	unsigned char		*ptr_dst;
	unsigned char		*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!ptr_dst && !ptr_src)
		return (ptr_dst);
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (ptr_dst);
}

void	ft_putstr_cub(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
    write(1, "\n", 1);
}

size_t	ft_strlen_cub(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi_cub(const char *str)
{
	int sign;
	int ans;

	ans = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
				|| *str == '\v' || *str == '\f'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		ans = ans * 10 + (*str - 48);
		str++;
	}
	return (ans * sign);
}

int	ft_isdigit_cub(int c)
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

char	*ft_strdup_cub(const char *s1)
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

unsigned long convertrgbtoint(unsigned int r, unsigned int g, unsigned int b)
{
  unsigned long color;

  color = (r * pow(256,2)) + (g * 256) + b;
  return (color);
}

void    ft_free(t_deflibx *mlx)
{
	int i;

	i = 0;
/*	if (mlx->sprites.Zbufferset == 1)
		free (mlx->sprites.Zbuffer);
	if (mlx->sprites.sprites_tabset == 1)
		free(mlx->sprites_tab);
	if (mlx->sprites.spriteDistanceset == 1)
		free(mlx->sprites.spriteDistance);
	if (mlx->sprites.spriteOrderset == 1)
		free(mlx->sprites.spriteOrder);
*/    if (mlx->parse.resolutionset == 1)
	   free(mlx->parse.resolution);
	/*if (mlx->parse.pathset == 1)
        free (mlx->parse.path);*/
    if (mlx->parse.widthset == 1)
        free(mlx->parse.Widthcatch);
    if (mlx->parse.heightset == 1)
        free(mlx->parse.Heightcatch);
    if (mlx->parse.northset == 1)
        free(mlx->parse.northtext);
    if (mlx->parse.southset == 1)
        free(mlx->parse.southtext);
    if (mlx->parse.westset == 1)
		free(mlx->parse.westtext);
	if (mlx->parse.eastset == 1)
        free (mlx->parse.easttext);
	if (mlx->parse.spriteset == 1)
		free (mlx->parse.sprite);
	i = 0;
	while (i <= 5)
	{
		close(mlx->parse.fd[i]);
		i++;
	}
}

int KillWindow(t_deflibx *mlx)
{
	ft_free_map(mlx);
	ft_free(mlx);
  //////////////////////////////////////////////////////////////////////////////
  //FAIRE DES FREE AVANT////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
	exit (0);
}
