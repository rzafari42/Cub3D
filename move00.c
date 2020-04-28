/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:32:55 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/29 00:38:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_deflibx *mlx)
{
	if (mlx->parse.map[(int)(mlx->raycast.posx + mlx->raycast.dirX *
			mlx->speed.movespeed)][(int)(mlx->raycast.posy)] == '0')
		mlx->raycast.posx += mlx->raycast.dirX * mlx->speed.movespeed;
	if (mlx->parse.map[(int)(mlx->raycast.posx)][(int)(mlx->raycast.posy +
			mlx->raycast.dirY * mlx->speed.movespeed)] == '0')
		mlx->raycast.posy += mlx->raycast.dirY * mlx->speed.movespeed;
}

void	move_down(t_deflibx *mlx)
{
	if (mlx->parse.map[(int)(mlx->raycast.posx - mlx->raycast.dirX *
			mlx->speed.movespeed)][(int)(mlx->raycast.posy)] == '0')
		mlx->raycast.posx -= mlx->raycast.dirX * mlx->speed.movespeed;
	if (mlx->parse.map[(int)(mlx->raycast.posx)][(int)(mlx->raycast.posy -
			mlx->raycast.dirY * mlx->speed.movespeed)] == '0')
		mlx->raycast.posy -= mlx->raycast.dirY * mlx->speed.movespeed;
}

void	move_right(t_deflibx *mlx)
{
	if (mlx->parse.map[(int)(mlx->raycast.posx + mlx->raycast.planeX *
			mlx->speed.movespeed)][(int)(mlx->raycast.posy)] == '0')
		mlx->raycast.posx += mlx->raycast.planeX * mlx->speed.movespeed;
	if (mlx->parse.map[(int)(mlx->raycast.posx)][(int)(mlx->raycast.posy +
			mlx->raycast.planeY * mlx->speed.movespeed)] == '0')
		mlx->raycast.posy += mlx->raycast.planeY * mlx->speed.movespeed;
}
