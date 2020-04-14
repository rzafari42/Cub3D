/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:32:55 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/15 01:01:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap1[mapHeight][mapWidth]=
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void move_up(t_deflibx *mlx)
{
  if(mlx->parse.map[(int)(mlx->raycast.posX + mlx->raycast.dirX * mlx->speed.moveSpeed)][(int)(mlx->raycast.posY)] == 0) 
     mlx->raycast.posX += mlx->raycast.dirX * mlx->speed.moveSpeed;
  if(mlx->parse.map[(int)(mlx->raycast.posX)][(int)(mlx->raycast.posY + mlx->raycast.dirY * mlx->speed.moveSpeed)] == 0)
    mlx->raycast.posY += mlx->raycast.dirY * mlx->speed.moveSpeed;
}

void move_down(t_deflibx *mlx)
{
  if(mlx->parse.map[(int)(mlx->raycast.posX - mlx->raycast.dirX * mlx->speed.moveSpeed)][(int)(mlx->raycast.posY)] == 0)
    mlx->raycast.posX -= mlx->raycast.dirX * mlx->speed.moveSpeed;
  if(mlx->parse.map[(int)(mlx->raycast.posX)][(int)(mlx->raycast.posY - mlx->raycast.dirY * mlx->speed.moveSpeed)] == 0)
    mlx->raycast.posY -= mlx->raycast.dirY * mlx->speed.moveSpeed;
}

void move_right(t_deflibx *mlx)
{
  if(mlx->parse.map[(int)(mlx->raycast.posX + mlx->raycast.planeX * mlx->speed.moveSpeed)][(int)(mlx->raycast.posY)] == 0) 
     mlx->raycast.posX += mlx->raycast.planeX * mlx->speed.moveSpeed;
  if(mlx->parse.map[(int)(mlx->raycast.posX)][(int)(mlx->raycast.posY + mlx->raycast.planeY * mlx->speed.moveSpeed)] == 0)
    mlx->raycast.posY += mlx->raycast.planeY * mlx->speed.moveSpeed;
}
