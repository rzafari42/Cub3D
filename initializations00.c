/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:46:08 by rzafari           #+#    #+#             */
/*   Updated: 2020/03/12 07:43:39 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void North_South_initialization(t_deflibx *mlx)
{
    if (N == 1)
  {   
    /*initial direction vector*/
    mlx->raycast.dirX = -1;
    mlx->raycast.dirY = 0;
    /*the 2d raycaster version of camera plane*/
    mlx->raycast.planeX = 0;
    mlx->raycast.planeY = 0.66;
  }
  if (S == 1)
  {    
    /*initial direction vector*/
    mlx->raycast.dirX = 1;
    mlx->raycast.dirY = 0;
    /*the 2d raycaster version of camera plane*/
    mlx->raycast.planeX = 0;
    mlx->raycast.planeY = -0.66;
  }
}

void East_West_initialization(t_deflibx *mlx)
{
  if (W == 1)
  {    
    //initial direction vector
    mlx->raycast.dirX = 0;
    mlx->raycast.dirY = -1;
    //the 2d raycaster version of camera plane
    mlx->raycast.planeX = -0.66;
    mlx->raycast.planeY = 0;
  }
  if (E == 1)
  {    
    //initial direction vector
    mlx->raycast.dirX = 0;
    mlx->raycast.dirY = 1;
    //the 2d raycaster version of camera plane
    mlx->raycast.planeX = 0.66;
    mlx->raycast.planeY = 0;
  }
}

void initialization(t_deflibx *mlx)
{
  position_initialization(mlx);
  North_South_initialization(mlx);
  East_West_initialization(mlx); 
  Move_initialization(mlx);
  Window_initialization(mlx);
}