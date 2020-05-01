/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:36:46 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/02 01:28:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_launch_sprites(t_deflibx *mlx)
{
	mlx->sprites.img_spriteptr0 = mlx_xpm_file_to_image(mlx->mlx_ptr,
		mlx->parse.sprite, &mlx->sprites.width, &mlx->sprites.height);
	mlx->sprites.img_spritedata0 =
		mlx_get_data_addr(mlx->sprites.img_spriteptr0, &mlx->sprites.bpp,
		&mlx->sprites.size_line, &mlx->sprites.endian);
}

void	ft_sort_sprites(t_deflibx *mlx)
{
	int		i;
	int		tmp;
	double	tmp2;

	i = 0;
	while (i < mlx->parse.numsprites - 1)
	{
		if (mlx->sprites.spritedistance[i] < mlx->sprites.spritedistance[i + 1])
		{
			tmp2 = mlx->sprites.spritedistance[i + 1];
			mlx->sprites.spritedistance[i + 1] = mlx->sprites.spritedistance[i];
			mlx->sprites.spritedistance[i] = tmp2;
			tmp = mlx->sprites.spriteorder[i + 1];
			mlx->sprites.spriteorder[i + 1] = mlx->sprites.spriteorder[i];
			mlx->sprites.spriteorder[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_locate_sprites(t_deflibx *mlx)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < mlx->parse.mapnbline)
	{
		x = 0;
		while (x < mlx->parse.mapbiggerline)
		{
			if (mlx->parse.map[y][x] == '2')
			{
				mlx->sprites_tab[i].x = y + 0.5;
				mlx->sprites_tab[i].y = x + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_order_sprites(t_deflibx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->parse.numsprites)
	{
		mlx->sprites.spriteorder[i] = i;
		mlx->sprites.spritedistance[i] = ((mlx->raycast.posx -
			mlx->sprites_tab[i].x) * (mlx->raycast.posx -
			mlx->sprites_tab[i].x) + (mlx->raycast.posy -
			mlx->sprites_tab[i].y) * (mlx->raycast.posy -
			mlx->sprites_tab[i].y));
		i++;
	}
}

void	ft_freesprites(t_deflibx *mlx)
{
	//free(&mlx->sprites.spriteorder);
	free(&mlx->sprites_tab);
	int x = 0;
	while (x < mlx->parse.width)
	{
		free(&mlx->sprites.zbuffer[x]);
		x++;
	}
	int i = 0;
	while (i < mlx->parse.numsprites)
	{
		free(&mlx->sprites.spritedistance[i]);
		free(&mlx->sprites.spriteorde[i]);
		i++;
	}
}
