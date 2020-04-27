/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:47:48 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/27 02:35:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_initialization(t_deflibx *mlx)
{
	mlx->move.mode = 0;
	mlx->move.keyDown = 0;
	mlx->move.keyUp = 0;
	mlx->move.keyRight = 0;
	mlx->move.keyLeft = 0;
	mlx->move.keyTurnLeft = 0;
	mlx->move.keyTurnRight = 0;
	mlx->move.killwindow = 0;
	mlx->speed.moveSpeed = 0.08;
	mlx->speed.rotSpeed = 0.02;
}

void	window_initialization(t_deflibx *mlx)
{
	int	sizex;
	int	sizey;

	mlx->mlx_ptr = mlx_init();
	mlx_get_screen_size(mlx->mlx_ptr, &sizex, &sizey);
	if (mlx->parse.Width > sizex)
		mlx->parse.Width = sizex;
	if (mlx->parse.Height > sizey)
		mlx->parse.Height = sizey;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->parse.Width,
			mlx->parse.Height, "cub3d");
}

void	position_initialization(t_deflibx *mlx)
{
	mlx->raycast.posX = mlx->parse.positionx + 0.5;
	mlx->raycast.posY = mlx->parse.positiony + 0.5;
}

void	color_initializatin(t_deflibx *mlx)
{
	mlx->color.r = 255;
	mlx->color.g = 0;
	mlx->color.b = 0;
}
