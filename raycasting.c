/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:34:38 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/28 00:04:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_DDA(t_deflibx *mlx)
{
	mlx->color.color = convertrgbtoint(mlx->color.r, mlx->color.g, mlx->color.b);
	while (mlx->raycast.hit == 0)
	{
		//3 differents modes: 0 = texture, 1 = electron, 2 = color walls
		if (mlx->move.mode == 0 || mlx->move.mode == 2)
			ft_normal_mode(mlx);
		if (mlx->move.mode == 1)
			ft_electro_mode(mlx);
		//Check if ray has hit a wall
		if(mlx->parse.map[mlx->raycast.mapX][mlx->raycast.mapY] == '1')
			mlx->raycast.hit = 1;
	}
}

int		raycasting(t_deflibx *mlx)
{
	int x; 
	int (*pix_array)[mlx->parse.Width][1];
	int width;
	int height;
	unsigned int  color;
    
	x = 0;
    mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->parse.Width, mlx->parse.Height);
    mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_line, &mlx->endian);
    ft_launch_text(mlx);
    ft_launch_sprites(mlx);
    while (x < mlx->parse.Width)
    { 
      color_initializatin(mlx);
      //mlx->img_color = mlx_get_color_value(mlx->mlx_ptr, mlx->color);
      //calculate ray position and direction
      mlx->raycast.cameraX = 2 * x / (double)mlx->parse.Width - 1; //x-coordinate in camera space
      mlx->raycast.rayDirX = mlx->raycast.dirX + mlx->raycast.planeX * mlx->raycast.cameraX;
      mlx->raycast.rayDirY = mlx->raycast.dirY + mlx->raycast.planeY * mlx->raycast.cameraX;
      //which box of the map are we in ?
      mlx->raycast.mapX = (int)mlx->raycast.posX;
      mlx->raycast.mapY = (int)mlx->raycast.posY;
      //length of ray from one x or y-side to the next x or y-side
      mlx->raycast.deltaDistX = fabs(1 / mlx->raycast.rayDirX);
      mlx->raycast.deltaDistY = fabs(1 / mlx->raycast.rayDirY);
      

      mlx->raycast.hit = 0; //was there a wall hit?
      //calculate step and initial sideDist
      if(mlx->raycast.rayDirX < 0)
      {
        mlx->raycast.stepX = -1;
        mlx->raycast.sideDistX = (mlx->raycast.posX - mlx->raycast.mapX) * mlx->raycast.deltaDistX;
      }
      else
      {
        mlx->raycast.stepX = 1;
        mlx->raycast.sideDistX = (mlx->raycast.mapX + 1.0 - mlx->raycast.posX) * mlx->raycast.deltaDistX;
      }
      if(mlx->raycast.rayDirY < 0)
      {
        mlx->raycast.stepY = -1;
        mlx->raycast.sideDistY = (mlx->raycast.posY - mlx->raycast.mapY) * mlx->raycast.deltaDistY;
      }
      else
      {
        mlx->raycast.stepY = 1;
        mlx->raycast.sideDistY = (mlx->raycast.mapY + 1.0 - mlx->raycast.posY) * mlx->raycast.deltaDistY;
      }
      //Perform DDA
      ft_DDA(mlx);
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if(mlx->raycast.side == 0 || mlx->raycast.side == 1)
        mlx->raycast.perpWallDist = (mlx->raycast.mapX - mlx->raycast.posX + (1 - mlx->raycast.stepX) / 2) / mlx->raycast.rayDirX;
      else
        mlx->raycast.perpWallDist = (mlx->raycast.mapY - mlx->raycast.posY + (1 - mlx->raycast.stepY) / 2) / mlx->raycast.rayDirY;
      if (mlx->raycast.perpWallDist <= 0)
	      mlx->raycast.perpWallDist *= -1;
      //Calculate height of line to draw on screen
      mlx->raycast.lineHeight = (int)(mlx->parse.Height / mlx->raycast.perpWallDist);
      //calculate lowest and highest pixel to fill in current stripe
      mlx->raycast.drawStart = -mlx->raycast.lineHeight / 2 + mlx->parse.Height / 2;
      if(mlx->raycast.drawStart < 0)
        mlx->raycast.drawStart = 0;
      mlx->raycast.drawEnd = mlx->raycast.lineHeight / 2 + mlx->parse.Height / 2;
      if(mlx->raycast.drawEnd >= mlx->parse.Height)
        mlx->raycast.drawEnd = mlx->parse.Height - 1;
      //TEXTURES
      ft_draw_ceil(mlx, x);
      if (mlx->move.mode == 0)
        ft_drawtexturedwall(mlx, x);
      if (mlx->move.mode == 2 || mlx->move.mode == 1)
      {
        int startMem = mlx->raycast.drawStart;
        int xMem = x;
        while (startMem < mlx->raycast.drawEnd)
        {
          pix_array = (void *)mlx->img_data;
          *pix_array[startMem][xMem] = mlx->color.color;  
          startMem++;
        }
      }
      ft_draw_floor(mlx, x);

      //SPRITES
      if (!(mlx->sprites.Zbuffer = malloc(sizeof(double) * mlx->parse.Width)))
        return (0);
      mlx->sprites.Zbuffer[x] = mlx->raycast.perpWallDist;
      if (!(mlx->sprites_tab = malloc(sizeof(t_sprite) * mlx->parse.numsprites)))
        return (0);
      if (!(mlx->sprites.spriteDistance = malloc(sizeof(double) * mlx->parse.numsprites)))
        return (0);
      if (!(mlx->sprites.spriteOrder = malloc(sizeof(int) * mlx->parse.numsprites)))
        return (0);
      ft_locate_sprites(mlx);
      ft_order_sprites(mlx);
      ft_sort_sprites(mlx->sprites.spriteOrder, mlx->sprites.spriteDistance, mlx->parse.numsprites);
      ft_project_sprites(mlx);
      x++;
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
    mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
    ft_destroy_text(mlx);
    ft_destroy_sprites(mlx);
    //ft_free(mlx);
    return (0);
}
