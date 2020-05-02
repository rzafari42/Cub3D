/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:46:08 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/02 04:19:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	north_south_initialization(t_deflibx *mlx)
{
	if (mlx->parse.position == 'N')
	{
		mlx->raycast.dirx = -1;
		mlx->raycast.diry = 0;
		mlx->raycast.planex = 0;
		mlx->raycast.planey = 0.66;
	}
	if (mlx->parse.position == 'S')
	{
		mlx->raycast.dirx = 1;
		mlx->raycast.diry = 0;
		mlx->raycast.planex = 0;
		mlx->raycast.planey = -0.66;
	}
}

void	east_west_initialization(t_deflibx *mlx)
{
	if (mlx->parse.position == 'W')
	{
		mlx->raycast.dirx = 0;
		mlx->raycast.diry = -1;
		mlx->raycast.planex = -0.66;
		mlx->raycast.planey = 0;
	}
	if (mlx->parse.position == 'E')
	{
		mlx->raycast.dirx = 0;
		mlx->raycast.diry = 1;
		mlx->raycast.planex = 0.66;
		mlx->raycast.planey = 0;
	}
}

void	initialization(t_deflibx *mlx)
{
	if (!(mlx.sprites.zbuffer = malloc(sizeof(double) * mlx.parse.width)))
		return (0);
	position_initialization(mlx);
	north_south_initialization(mlx);
	east_west_initialization(mlx);
	move_initialization(mlx);
	window_initialization(mlx);
}
