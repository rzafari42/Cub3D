/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_modes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:47:42 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/15 01:02:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_normal_mode(t_deflibx *mlx)
{
    //jump to next map square, OR in x-direction, OR in y-direction
    if(mlx->raycast.sideDistX < mlx->raycast.sideDistY)
    {
    mlx->raycast.sideDistX += mlx->raycast.deltaDistX;
    mlx->raycast.mapX += mlx->raycast.stepX;
    if (mlx->raycast.rayDirX < 0)
        mlx->raycast.side = 0;
    if (mlx->raycast.rayDirX > 0)
        mlx->raycast.side = 1;
    }
    else
    {
    mlx->raycast.sideDistY += mlx->raycast.deltaDistY;
    mlx->raycast.mapY += mlx->raycast.stepY;
    if (mlx->raycast.rayDirY < 0)
        mlx->raycast.side = 2;
    if (mlx->raycast.rayDirY > 0)
        mlx->raycast.side = 3;
    }
    //gives every side of a cube, different colors upon the ray directon
    if(mlx->raycast.side == 0)
    {
    mlx->color.r = 255;
    mlx->color.g = 0;
    mlx->color.b = 0;
    mlx->text.img_textdata_utils = mlx->text.img_textdata0;
    }
    if(mlx->raycast.side == 1) 
    {
    mlx->color.r = 208;
    mlx->color.g = 58;
    mlx->color.b = 8;
    mlx->text.img_textdata_utils = mlx->text.img_textdata1;
    }
    if(mlx->raycast.side == 2) 
    {
    mlx->color.r = 123;
    mlx->color.g = 11;
    mlx->color.b = 8;
    mlx->text.img_textdata_utils = mlx->text.img_textdata2;
    }
    if(mlx->raycast.side == 3)
    {
    mlx->color.r = 123;
    mlx->color.g = 0;
    mlx->color.b = 54;
    mlx->text.img_textdata_utils = mlx->text.img_textdata3;
    }
    /*mlx->color.floorcolor = 4341824;
    mlx->color.ceilcolor = 4341824;*/
    mlx->color.color = convertrgbtoint(mlx->color.r, mlx->color.g, mlx->color.b);
}

void ft_electro_mode(t_deflibx *mlx)
{
    //jump to next map square, OR in x-direction, OR in y-direction
    if(mlx->raycast.sideDistX < mlx->raycast.sideDistY)
    {
    mlx->raycast.sideDistX += mlx->raycast.deltaDistX;
    mlx->raycast.mapX += mlx->raycast.stepX;
    if (mlx->raycast.rayDirX < 0)
    {
        mlx->raycast.side = 0;
        mlx->color.color = mlx->color.color / 2;
    }
    if (mlx->raycast.rayDirX > 0)
    {
        mlx->raycast.side = 1;
        mlx->color.color = mlx->color.color / 3;
    }
    }
    else
    {
    mlx->raycast.sideDistY += mlx->raycast.deltaDistY;
    mlx->raycast.mapY += mlx->raycast.stepY;
    if (mlx->raycast.rayDirY < 0)
    {
        mlx->raycast.side = 2;
        mlx->color.color = mlx->color.color / 4;
    }
    if (mlx->raycast.rayDirY > 0)
    {
        mlx->raycast.side = 3;
        mlx->color.color = mlx->color.color / 5;
    }
    }
    mlx->color.floorcolor = 0;
    mlx->color.ceilcolor = 0;
}