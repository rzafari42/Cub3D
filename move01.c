/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:42:33 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/29 00:41:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(t_deflibx *mlx)
{
	if (mlx->parse.map[(int)(mlx->raycast.posx - mlx->raycast.planeX *
			mlx->speed.movespeed)][(int)(mlx->raycast.posy)] == '0')
		mlx->raycast.posx -= mlx->raycast.planeX * mlx->speed.movespeed;
	if (mlx->parse.map[(int)(mlx->raycast.posx)][(int)(mlx->raycast.posy -
			mlx->raycast.planeY * mlx->speed.movespeed)] == '0')
		mlx->raycast.posy -= mlx->raycast.planeY * mlx->speed.movespeed;
}

void	turn_right(t_deflibx *mlx)
{
	mlx->raycast.oldDirX = mlx->raycast.dirx;
	mlx->raycast.dirx = mlx->raycast.dirx * cos(-mlx->speed.rotspeed) -
		mlx->raycast.dirY * sin(-mlx->speed.rotspeed);
	mlx->raycast.dirY = mlx->raycast.oldDirX * sin(-mlx->speed.rotspeed) +
		mlx->raycast.dirY * cos(-mlx->speed.rotspeed);
	mlx->raycast.oldPlaneX = mlx->raycast.planeX;
	mlx->raycast.planeX = mlx->raycast.planeX * cos(-mlx->speed.rotspeed) -
		mlx->raycast.planeY * sin(-mlx->speed.rotspeed);
	mlx->raycast.planeY = mlx->raycast.oldPlaneX * sin(-mlx->speed.rotspeed) +
		mlx->raycast.planeY * cos(-mlx->speed.rotspeed);
	mlx->raycast.oldDirX = mlx->raycast.dirx;
}

void	turn_left(t_deflibx *mlx)
{
	mlx->raycast.oldDirX = mlx->raycast.dirx;
	mlx->raycast.dirx = mlx->raycast.dirx * cos(mlx->speed.rotspeed) -
		mlx->raycast.dirY * sin(mlx->speed.rotspeed);
	mlx->raycast.dirY = mlx->raycast.oldDirX * sin(mlx->speed.rotspeed) +
		mlx->raycast.dirY * cos(mlx->speed.rotspeed);
	mlx->raycast.oldPlaneX = mlx->raycast.planeX;
	mlx->raycast.planeX = mlx->raycast.planeX * cos(mlx->speed.rotspeed) -
		mlx->raycast.planeY * sin(mlx->speed.rotspeed);
	mlx->raycast.planeY = mlx->raycast.oldPlaneX * sin(mlx->speed.rotspeed) +
		mlx->raycast.planeY * cos(mlx->speed.rotspeed);
}
