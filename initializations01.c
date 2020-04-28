/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:47:48 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/29 00:35:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_initialization(t_deflibx *mlx)
{
	mlx->move.mode = 0;
	mlx->move.keydown = 0;
	mlx->move.keyup = 0;
	mlx->move.keyright = 0;
	mlx->move.keyleft = 0;
	mlx->move.keyturnleft = 0;
	mlx->move.keyturnright = 0;
	mlx->move.killwindow = 0;
	mlx->speed.movespeed = 0.08;
	mlx->speed.rotspeed = 0.02;
}

void	window_initialization(t_deflibx *mlx)
{
	int	sizex;
	int	sizey;

	mlx->mlx_ptr = mlx_init();
	mlx_get_screen_size(mlx->mlx_ptr, &sizex, &sizey);
	if (mlx->parse.width > sizex)
		mlx->parse.width = sizex;
	if (mlx->parse.height > sizey)
		mlx->parse.height = sizey;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->parse.width,
			mlx->parse.height, "cub3d");
}

void	position_initialization(t_deflibx *mlx)
{
	mlx->raycast.posx = mlx->parse.positionx + 0.5;
	mlx->raycast.posy = mlx->parse.positiony + 0.5;
}

void	color_initializatin(t_deflibx *mlx)
{
	mlx->color.r = 255;
	mlx->color.g = 0;
	mlx->color.b = 0;
}
