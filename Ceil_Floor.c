/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ceil_Floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:48:54 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/15 01:03:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_draw_ceil(t_deflibx *mlx, int x)
{
    int i;
    int (*pix_array)[mlx->parse.Width][1];

    i = 0;
    while (i <= mlx->raycast.drawStart)
    {
    pix_array = (void *)mlx->img_data;
    *pix_array[i][x] = mlx->color.floorcolor;  
    i++;
    }
}

void ft_draw_floor(t_deflibx *mlx, int x)
{
    int i;
    int (*pix_array)[mlx->parse.Width][1];
                            
    i = mlx->raycast.drawEnd;
    while (i < mlx->parse.Height - 1)
    { 
	    pix_array = (void *)mlx->img_data;
	    *pix_array[i][x] = mlx->color.ceilcolor;  
    i++;                           
    }
}
