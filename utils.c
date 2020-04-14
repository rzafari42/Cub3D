/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:49:25 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/14 20:52:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memcpy(void *dst, const void *src, int n)
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

unsigned long convertrgbtoint(unsigned int r, unsigned int g, unsigned int b)
{
  unsigned long color;

  color = (r * pow(256,2)) + (g * 256) + b;
  return (color);
}

void    ft_free(t_deflibx *mlx)
{
	if (mlx->sprites.Zbufferset == 1)
		free(mlx->sprites.Zbuffer);
	if (mlx->sprites.sprites_tabset == 1)
		free(mlx->sprites_tab);
	if (mlx->sprites.spriteDistanceset == 1)
		free(mlx->sprites.spriteDistance);
	if (mlx->sprites.spriteOrderset == 1)
		free(mlx->sprites.spriteOrder);
    if (mlx->parse.resolutionset == 1)
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
}
/*
size_t	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}*/


int KillWindow(t_deflibx *mlx)
{
	ft_free_map(mlx);
	ft_free(mlx);
  //////////////////////////////////////////////////////////////////////////////
  //FAIRE DES FREE AVANT////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////
	exit (0);
}