/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:32:55 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/29 01:18:37 by rzafari42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_deflibx *mlx)
{
	if (mlx->parse.map[(int)(mlx->raycast.posx + mlx->raycast.dirx *
			mlx->speed.movespeed)][(int)(mlx->raycast.posy)] == '0')
		mlx->raycast.posx += mlx->raycast.dirx * mlx->speed.movespeed;
	if (mlx->parse.map[(int)(mlx->raycast.posx)][(int)(mlx->raycast.posy +
			mlx->raycast.diry * mlx->speed.movespeed)] == '0')
		mlx->raycast.posy += mlx->raycast.diry * mlx->speed.movespeed;
}

void	move_down(t_deflibx *mlx)
{
	if (mlx->parse.map[(int)(mlx->raycast.posx - mlx->raycast.dirx *
			mlx->speed.movespeed)][(int)(mlx->raycast.posy)] == '0')
		mlx->raycast.posx -= mlx->raycast.dirx * mlx->speed.movespeed;
	if (mlx->parse.map[(int)(mlx->raycast.posx)][(int)(mlx->raycast.posy -
			mlx->raycast.diry * mlx->speed.movespeed)] == '0')
		mlx->raycast.posy -= mlx->raycast.diry * mlx->speed.movespeed;
}

void	move_right(t_deflibx *mlx)
{
	if (mlx->parse.map[(int)(mlx->raycast.posx + mlx->raycast.planex *
			mlx->speed.movespeed)][(int)(mlx->raycast.posy)] == '0')
		mlx->raycast.posx += mlx->raycast.planex * mlx->speed.movespeed;
	if (mlx->parse.map[(int)(mlx->raycast.posx)][(int)(mlx->raycast.posy +
			mlx->raycast.planey * mlx->speed.movespeed)] == '0')
		mlx->raycast.posy += mlx->raycast.planey * mlx->speed.movespeed;
}
