/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:46:08 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/27 02:30:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	north_south_initialization(t_deflibx *mlx)
{
	if (mlx->parse.position == 'N')
	{
		mlx->raycast.dirX = -1;
		mlx->raycast.dirY = 0;
		mlx->raycast.planeX = 0;
		mlx->raycast.planeY = 0.66;
	}
	if (mlx->parse.position == 'S')
	{
		mlx->raycast.dirX = 1;
		mlx->raycast.dirY = 0;
		mlx->raycast.planeX = 0;
		mlx->raycast.planeY = -0.66;
	}
}

void	east_west_initialization(t_deflibx *mlx)
{
	if (mlx->parse.position == 'W')
	{
		mlx->raycast.dirX = 0;
		mlx->raycast.dirY = -1;
		mlx->raycast.planeX = -0.66;
		mlx->raycast.planeY = 0;
	}
	if (mlx->parse.position == 'E')
	{
		mlx->raycast.dirX = 0;
		mlx->raycast.dirY = 1;
		mlx->raycast.planeX = 0.66;
		mlx->raycast.planeY = 0;
	}
}

void	initialization(t_deflibx *mlx)
{
	position_initialization(mlx);
	north_south_initialization(mlx);
	east_west_initialization(mlx);
	move_initialization(mlx);
	window_initialization(mlx);
}
