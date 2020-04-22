/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:47:48 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/15 01:01:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void Move_initialization(t_deflibx *mlx)
{
  /*Mode*/
  mlx->move.mode = 0;
  /*Key values*/
  mlx->move.keyDown = 0;
  mlx->move.keyUp = 0;
  mlx->move.keyRight = 0;
  mlx->move.keyLeft = 0;
  mlx->move.keyTurnLeft = 0;
  mlx->move.keyTurnRight = 0;
  mlx->move.killWindow = 0;
  /*speed modifiers*/
  mlx->speed.moveSpeed = 0.08;
  mlx->speed.rotSpeed = 0.02;
}

void Window_initialization(t_deflibx *mlx)
{
  int sizex;
  int sizey;

  mlx->mlx_ptr = mlx_init();
  mlx_get_screen_size(mlx->mlx_ptr, &sizex, &sizey);
  if (mlx->parse.Width > sizex)
	  mlx->parse.Width = sizex;
  if (mlx->parse.Height > sizey)
	  mlx->parse.Height = sizey;
  mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->parse.Width, mlx->parse.Height, "cub3d");
}

void position_initialization(t_deflibx *mlx)
{
  /*x and y start position*/
  mlx->raycast.posX = mlx->parse.positionx + 0.5;
  mlx->raycast.posY = mlx->parse.positiony + 0.5;
}

void Color_initializatin(t_deflibx *mlx)
{
  mlx->color.r = 255;
  mlx->color.g = 0;
  mlx->color.b = 0;
  //mlx->color.ceilcolor = 4341824;
  //mlx->color.floorcolor = 4341824;
}
