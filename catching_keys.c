/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catching_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:43:23 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/15 01:03:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int keyPress(int key, t_deflibx *mlx)
{
  if (key == 13)
    mlx->move.keyUp = 1;
  if (key == 1)
    mlx->move.keyDown = 1;
  if (key == 2)
    mlx->move.keyRight = 1;
  if (key == 0)
    mlx->move.keyLeft= 1;
  if (key == 124)
    mlx->move.keyTurnRight = 1;
  if (key == 123)
    mlx->move.keyTurnLeft = 1;
  if (key == 12)
    mlx->speed.moveSpeed = (mlx->speed.moveSpeed < 0.18) ?  (mlx->speed.moveSpeed * 1.5) : mlx->speed.moveSpeed;
  if (key == 6)
    mlx->speed.moveSpeed = (mlx->speed.moveSpeed > 0.08) ?  (mlx->speed.moveSpeed / 1.5) : mlx->speed.moveSpeed; 
  if (key == 46)
  {   
    if (mlx->move.mode == 0)
      mlx->move.mode = 1;
    else if (mlx->move.mode == 1)
      mlx->move.mode = 2;
    else
      mlx->move.mode = 0;
  }
  if (key == 53)
    mlx->move.killWindow = 1;
  return (0);
}

int keyRelease(int key, t_deflibx *mlx)
{

  if (key == 13)
    mlx->move.keyUp = 0;
  if (key == 1)
    mlx->move.keyDown = 0;
  if (key == 2)
    mlx->move.keyRight = 0;
  if (key == 0)
    mlx->move.keyLeft= 0;
  if (key == 124)
    mlx->move.keyTurnRight = 0;
  if (key == 123)
    mlx->move.keyTurnLeft = 0;
  if (key == 53)
    mlx->move.killWindow = 0;
  return (0);
}