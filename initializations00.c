/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:46:08 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/15 01:02:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void North_South_initialization(t_deflibx *mlx)
{
    if (mlx->parse.position == 'N')
  {   
    /*initial direction vector*/
    mlx->raycast.dirX = -1;
    mlx->raycast.dirY = 0;
    /*the 2d raycaster version of camera plane*/
    mlx->raycast.planeX = 0;
    mlx->raycast.planeY = 0.66;
  }
  if (mlx->parse.position == 'S')
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
  if (mlx->parse.position ==  'W')
  {    
    //initial direction vector
    mlx->raycast.dirX = 0;
    mlx->raycast.dirY = -1;
    //the 2d raycaster version of camera plane
    mlx->raycast.planeX = -0.66;
    mlx->raycast.planeY = 0;
  }
  if (mlx->parse.position == 'E')
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
	printf("Hello\n");
    
	printf("mlx->parse.map[%d][%d] = %c\n", mlx->parse.positionx, mlx->parse.positiony, mlx->parse.map[mlx->parse.positionx][mlx->parse.positiony]);
	Window_initialization(mlx);
	printf("End\n");
	printf("mlx->parse.map[%d][%d] = %c\n", mlx->parse.positionx, mlx->parse.positiony, mlx->parse.map[mlx->parse.positionx][mlx->parse.positiony]);

	printf("dirX = %f && direY = %f && planeX = %f && planeY = %f\n", mlx->raycast.dirX, mlx->raycast.dirY, mlx->raycast.planeX, mlx->raycast.planeY);
}
