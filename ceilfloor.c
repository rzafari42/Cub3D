/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilfloor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:48:54 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/06 02:38:07 by rzafari42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_ceil(t_deflibx *mlx, int x)
{
	int i;
	int (*pix_array)[mlx->parse.width][1];

	i = 0;
	while (i <= mlx->raycast.drawstart)
	{
		pix_array = (void *)mlx->img_data;
		*pix_array[i][x] = mlx->color.effectccolor;
		i++;
	}
}

void	ft_draw_floor(t_deflibx *mlx, int x)
{
	int i;
	int (*pix_array)[mlx->parse.width][1];

	i = mlx->raycast.drawend;
	while (i <= mlx->parse.height)
	{
		pix_array = (void *)mlx->img_data;
		*pix_array[i][x] = mlx->color.effectfcolor;
		i++;
	}
}
