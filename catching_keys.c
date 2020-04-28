/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catching_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:43:23 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/29 01:13:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keypresstwo(int key, t_deflibx *mlx)
{
	if (key == 101)
	{
		if (mlx->move.mode == 0)
			mlx->move.mode = 1;
		else if (mlx->move.mode == 1)
			mlx->move.mode = 2;
		else
			mlx->move.mode = 0;
	}
	if (key == 65307)
		mlx->move.killwindow = 1;
}

int		keypress(int key, t_deflibx *mlx)
{
	if (key == 122)
		mlx->move.keyup = 1;
	if (key == 115)
		mlx->move.keydown = 1;
	if (key == 100)
		mlx->move.keyright = 1;
	if (key == 113)
		mlx->move.keyleft = 1;
	if (key == 65363)
		mlx->move.keyturnright = 1;
	if (key == 65361)
		mlx->move.keyturnleft = 1;
	if (key == 97)
	{
		mlx->speed.movespeed = (mlx->speed.movespeed < 0.18) ?
			(mlx->speed.movespeed * 1.5) : mlx->speed.movespeed;
	}
	if (key == 119)
	{
		mlx->speed.movespeed = (mlx->speed.movespeed > 0.08) ?
			(mlx->speed.movespeed / 1.5) : mlx->speed.movespeed;
	}
	keypresstwo(key, mlx);
	return (0);
}

int		keyrelease(int key, t_deflibx *mlx)
{
	if (key == 122)
		mlx->move.keyup = 0;
	if (key == 115)
		mlx->move.keydown = 0;
	if (key == 100)
		mlx->move.keyright = 0;
	if (key == 113)
		mlx->move.keyleft = 0;
	if (key == 65363)
		mlx->move.keyturnright = 0;
	if (key == 65361)
		mlx->move.keyturnleft = 0;
	if (key == 65307)
		mlx->move.killwindow = 0;
	return (0);
}
