/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_to_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:44:48 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/26 18:15:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_deal(t_deflibx *mlx)
{
  /*move forward if no wall in front of you*/
  if(mlx->move.keyUp == 1)
    move_up(mlx);
  /*move backwards if no wall behind you*/
  if(mlx->move.keyDown == 1)
    move_down(mlx);
  /*move right if no wall*/
  if(mlx->move.keyRight == 1)
    move_right(mlx);
  /*move left if no wall*/ 
  if(mlx->move.keyLeft == 1)
    move_left(mlx);
  /*rotate to the right*/
  if(mlx->move.keyTurnRight == 1)
    turn_right(mlx);
  /*rotate to the left*/
  if(mlx->move.keyTurnLeft == 1)
    turn_left(mlx);
  if (mlx->move.killWindow ==1)
    KillWindow(mlx);
  raycasting(mlx);  
  return(0);
}
