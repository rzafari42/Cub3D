/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_to_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:44:48 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/27 00:08:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_deal(t_deflibx *mlx)
{
  if(mlx->move.keyUp == 1)
    move_up(mlx);
  if(mlx->move.keyDown == 1)
    move_down(mlx);
  if(mlx->move.keyRight == 1)
    move_right(mlx);
  if(mlx->move.keyLeft == 1)
    move_left(mlx);
  if(mlx->move.keyTurnRight == 1)
    turn_right(mlx);
  if(mlx->move.keyTurnLeft == 1)
    turn_left(mlx);
  if (mlx->move.killWindow ==1)
    KillWindow(mlx);
  raycasting(mlx);  
  return(0);
}
