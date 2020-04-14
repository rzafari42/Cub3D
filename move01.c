/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:42:33 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/15 01:01:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
  
  int worldMap[mapHeight][mapWidth]=
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

void move_left(t_deflibx *mlx)
{
  if(mlx->parse.map[(int)(mlx->raycast.posX - mlx->raycast.planeX * mlx->speed.moveSpeed)][(int)(mlx->raycast.posY)] == 0)
    mlx->raycast.posX -= mlx->raycast.planeX * mlx->speed.moveSpeed;
  if(mlx->parse.map[(int)(mlx->raycast.posX)][(int)(mlx->raycast.posY - mlx->raycast.planeY * mlx->speed.moveSpeed)] == 0)
    mlx->raycast.posY -= mlx->raycast.planeY * mlx->speed.moveSpeed;
}

void turn_right(t_deflibx *mlx)
{
  //both camera direction and camera plane must be rotated
  mlx->raycast.oldDirX = mlx->raycast.dirX;
  mlx->raycast.dirX = mlx->raycast.dirX * cos(-mlx->speed.rotSpeed) - mlx->raycast.dirY * sin(-mlx->speed.rotSpeed);
  mlx->raycast.dirY = mlx->raycast.oldDirX * sin(-mlx->speed.rotSpeed) + mlx->raycast.dirY * cos(-mlx->speed.rotSpeed);
  mlx->raycast.oldPlaneX = mlx->raycast.planeX;
  mlx->raycast.planeX = mlx->raycast.planeX * cos(-mlx->speed.rotSpeed) - mlx->raycast.planeY * sin(-mlx->speed.rotSpeed);
  mlx->raycast.planeY = mlx->raycast.oldPlaneX * sin(-mlx->speed.rotSpeed) + mlx->raycast.planeY * cos(-mlx->speed.rotSpeed);
}

void turn_left(t_deflibx *mlx)
{
  //both camera direction and camera plane must be rotated
  mlx->raycast.oldDirX = mlx->raycast.dirX;
  mlx->raycast.dirX = mlx->raycast.dirX * cos(mlx->speed.rotSpeed) - mlx->raycast.dirY * sin(mlx->speed.rotSpeed);
  mlx->raycast.dirY = mlx->raycast.oldDirX * sin(mlx->speed.rotSpeed) + mlx->raycast.dirY * cos(mlx->speed.rotSpeed);
  mlx->raycast.oldPlaneX = mlx->raycast.planeX;
  mlx->raycast.planeX = mlx->raycast.planeX * cos(mlx->speed.rotSpeed) - mlx->raycast.planeY * sin(mlx->speed.rotSpeed);
  mlx->raycast.planeY = mlx->raycast.oldPlaneX * sin(mlx->speed.rotSpeed) + mlx->raycast.planeY * cos(mlx->speed.rotSpeed);
}