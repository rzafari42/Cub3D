/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingtwo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 19:02:42 by rzafari42         #+#    #+#             */
/*   Updated: 2020/04/29 01:19:08 by rzafari42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycastingtextures(t_deflibx *mlx, int x)
{
	int	(*pix_array)[mlx->parse.width][1];
	int	startmem;
	int	xmem;

	xmem = x;
	startmem = mlx->raycast.drawstart;
	if (mlx->move.mode == 0)
		ft_drawtexturedwall(mlx, x);
	if (mlx->move.mode == 2 || mlx->move.mode == 1)
	{
		while (startmem < mlx->raycast.drawend)
		{
			pix_array = (void *)mlx->img_data;
			*pix_array[startmem][xmem] = mlx->color.color;
			startmem++;
		}
	}
}

int		raycastingsprites(t_deflibx *mlx, int x)
{
	if (!(mlx->sprites.zbuffer = malloc(sizeof(double) * mlx->parse.width)))
		return (0);
	mlx->sprites.zbuffer[x] = mlx->raycast.perpwalldist;
	if (!(mlx->sprites_tab = malloc(sizeof(t_sprite) * mlx->parse.numsprites)))
		return (0);
	if (!(mlx->sprites.spritedistance = malloc(sizeof(double) *
					mlx->parse.numsprites)))
		return (0);
	if (!(mlx->sprites.spriteorder = malloc(sizeof(int) *
					mlx->parse.numsprites)))
		return (0);
	ft_locate_sprites(mlx);
	ft_order_sprites(mlx);
	ft_sort_sprites(mlx->sprites.spriteorder, mlx->sprites.spritedistance,
			mlx->parse.numsprites);
	ft_project_sprites(mlx);
	return (1);
}
