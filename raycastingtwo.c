/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingtwo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 19:02:42 by rzafari42         #+#    #+#             */
/*   Updated: 2020/05/02 04:48:18 by marvin           ###   ########.fr       */
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
	//mlx->sprites.zbuffer[x] = mlx->raycast.perpwalldist;
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
	ft_sort_sprites(mlx);
	ft_project_sprites(mlx);
	if (mlx->sprites_tab)
		free(mlx->sprites_tab);
	if (mlx->sprites.spritedistance)
		free(mlx->sprites.spritedistance);
	if (mlx->sprites.spriteorder)
		free (mlx->sprites.spriteorder);
	return (1);
}

void	ft_helpingbox(t_deflibx *mlx)
{
	if (mlx->raycast.help == 0)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0x0901F9,
				"Press 'h' to display the helping box");
	if (mlx->raycast.help == 1)
	{
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0x0901F9, "Up = Z");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 25, 0x0901F9,
				"Down = S");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 40, 0x0901F9,
				"Left = Q");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 55, 0x0901F9,
				"Rotate Right = Right Arrow");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 70, 0x0901F9,
				"Rotate Left = Left Arrow");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 85, 0x0901F9,
				"Change mode = E");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 100, 0x0901F9,
				"Accelerate = A");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 115, 0x0901F9,
				"Decelerate = W");
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 130, 0x0901F9,
				"Quit = h");
	}
}
