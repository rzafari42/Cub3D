/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:42:33 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/29 01:13:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(t_deflibx *mlx)
{
	if (mlx->parse.map[(int)(mlx->raycast.posx - mlx->raycast.planex *
			mlx->speed.movespeed)][(int)(mlx->raycast.posy)] == '0')
		mlx->raycast.posx -= mlx->raycast.planex * mlx->speed.movespeed;
	if (mlx->parse.map[(int)(mlx->raycast.posx)][(int)(mlx->raycast.posy -
			mlx->raycast.planey * mlx->speed.movespeed)] == '0')
		mlx->raycast.posy -= mlx->raycast.planey * mlx->speed.movespeed;
}

void	turn_right(t_deflibx *mlx)
{
	mlx->raycast.olddirx = mlx->raycast.dirx;
	mlx->raycast.dirx = mlx->raycast.dirx * cos(-mlx->speed.rotspeed) -
		mlx->raycast.diry * sin(-mlx->speed.rotspeed);
	mlx->raycast.diry = mlx->raycast.olddirx * sin(-mlx->speed.rotspeed) +
		mlx->raycast.diry * cos(-mlx->speed.rotspeed);
	mlx->raycast.oldplanex = mlx->raycast.planex;
	mlx->raycast.planex = mlx->raycast.planex * cos(-mlx->speed.rotspeed) -
		mlx->raycast.planey * sin(-mlx->speed.rotspeed);
	mlx->raycast.planey = mlx->raycast.oldplanex * sin(-mlx->speed.rotspeed) +
		mlx->raycast.planey * cos(-mlx->speed.rotspeed);
	mlx->raycast.olddirx = mlx->raycast.dirx;
}

void	turn_left(t_deflibx *mlx)
{
	mlx->raycast.olddirx = mlx->raycast.dirx;
	mlx->raycast.dirx = mlx->raycast.dirx * cos(mlx->speed.rotspeed) -
		mlx->raycast.diry * sin(mlx->speed.rotspeed);
	mlx->raycast.diry = mlx->raycast.olddirx * sin(mlx->speed.rotspeed) +
		mlx->raycast.diry * cos(mlx->speed.rotspeed);
	mlx->raycast.oldplanex = mlx->raycast.planex;
	mlx->raycast.planex = mlx->raycast.planex * cos(mlx->speed.rotspeed) -
		mlx->raycast.planey * sin(mlx->speed.rotspeed);
	mlx->raycast.planey = mlx->raycast.oldplanex * sin(mlx->speed.rotspeed) +
		mlx->raycast.planey * cos(mlx->speed.rotspeed);
}
