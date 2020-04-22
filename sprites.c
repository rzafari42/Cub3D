/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:36:46 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/15 01:01:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap4[mapHeight][mapWidth]=
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

void ft_launch_sprites(t_deflibx *mlx)
{
    mlx->sprites.img_spriteptr0 = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->parse.sprite , &mlx->sprites.width , &mlx->sprites.height);
    //mlx->sprites.img_spriteptr1 = mlx_xpm_file_to_image(mlx->mlx_ptr, "./02.xpm" , &mlx->text.width, &mlx->text.height);
    //mlx->sprites.img_spriteptr2 = mlx_xpm_file_to_image(mlx->mlx_ptr, "./greystone.xpm" , &mlx->text.width, &mlx->text.height);
    //mlx->sprites.img_spriteptr3 = mlx_xpm_file_to_image(mlx->mlx_ptr, "./04.xpm" , &mlx->text.width, &mlx->text.height);

    mlx->sprites.img_spritedata0 = mlx_get_data_addr(mlx->sprites.img_spriteptr0, &mlx->sprites.bpp, &mlx->sprites.size_line, &mlx->sprites.endian);
    //mlx->sprites.img_spritedata1 = mlx_get_data_addr(mlx->sprites.img_spriteptr1, &mlx->text.bpp, &mlx->text.size_line, &mlx->text.endian);
    //mlx->sprites.img_spritedata2 = mlx_get_data_addr(mlx->sprites.img_spriteptr2, &mlx->text.bpp, &mlx->text.size_line, &mlx->text.endian);
    //mlx->sprites.img_spritedata3 = mlx_get_data_addr(mlx->sprites.img_spriteptr3, &mlx->text.bpp, &mlx->text.size_line, &mlx->text.endian);
}

void ft_destroy_sprites(t_deflibx *mlx)
{
    mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.img_spriteptr0);
   // mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.img_spriteptr1);
    //mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.img_spriteptr2);
    //mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.img_spriteptr3);
}

//sorting sprites based on distance
void  ft_sort_sprites(int *Order, double *Distance, int num)
{
  int i;
  int tmp;
  double tmp2;

  i = 0;
  while (i < num - 1)
  {
    if (Distance[i] < Distance[i + 1])
    {
        //sort every distance from furthest away to closest to the camera
        tmp2 = Distance[i + 1];
        Distance[i + 1] = Distance[i];
        Distance[i] = tmp2;
        //sort the sprite's order fron furthest away to closest to the camera
        tmp = Order[i + 1];
        Order[i + 1] = Order[i];
        Order[i] = tmp;
        i = 0;
    }
    else
      i++;
  }
}

void  ft_locate_sprites(t_deflibx *mlx)
{
    int x;
    int y;
    int i;
    
    i = 0;
    y = 0;
    while (y < mlx->parse.mapnbline)
    {
        x = 0;
        while (x < mlx->parse.mapbiggerline)
        {
          if (mlx->parse.map[y][x] == '2')
          {
            mlx->sprites_tab[i].x = y + 0.5;
            mlx->sprites_tab[i].y = x + 0.5;
            i++;
          }
          x++;
        }
        y++;
    }
}

void ft_Order_sprites(t_deflibx *mlx)
{
    int i;

    i = 0;
    while (i < numsprites)
    {
      mlx->sprites.spriteOrder[i] = i;
      mlx->sprites.spriteDistance[i] = ((mlx->raycast.posX - mlx->sprites_tab[i].x) * (mlx->raycast.posX - mlx->sprites_tab[i].x) + (mlx->raycast.posY - mlx->sprites_tab[i].y) * (mlx->raycast.posY - mlx->sprites_tab[i].y));
      i++;
    }
}

void ft_project_sprites(t_deflibx *mlx)
{
    int i;

    i = -1;
    while (++i < numsprites)
    {
      mlx->sprites.spriteX = mlx->sprites_tab[mlx->sprites.spriteOrder[i]].x - mlx->raycast.posX;
      mlx->sprites.spriteY = mlx->sprites_tab[mlx->sprites.spriteOrder[i]].y - mlx->raycast.posY;
      mlx->sprites.invert = 1.0 / (mlx->raycast.planeX * mlx->raycast.dirY - mlx->raycast.dirX * mlx->raycast.planeY);

      mlx->sprites.transfomrX = mlx->sprites.invert * (mlx->raycast.dirY * mlx->sprites.spriteX - mlx->raycast.dirX * mlx->sprites.spriteY);
      mlx->sprites.transformY = mlx->sprites.invert * (-mlx->raycast.planeY * mlx->sprites.spriteX + mlx->raycast.planeX * mlx->sprites.spriteY);
      mlx->sprites.sprite_screen = (int)(mlx->parse.Width / 2) * (1 + (mlx->sprites.transfomrX / mlx->sprites.transformY));

      //Sprite height calculs
      mlx->sprites.spriteHeight = abs((int)(mlx->parse.Height / mlx->sprites.transformY));
      mlx->sprites.drawStart_spriteY = (-mlx->sprites.spriteHeight / 2) + (mlx->parse.Height / 2);
      if (mlx->sprites.drawStart_spriteY < 0)
        mlx->sprites.drawStart_spriteY = 0;
      mlx->sprites.drawEnd_spriteY = (mlx->sprites.spriteHeight / 2) + (mlx->parse.Height / 2);
      if (mlx->sprites.drawEnd_spriteY >= mlx->parse.Height)
        mlx->sprites.drawEnd_spriteY = mlx->parse.Height - 1;

      //Sprite width calculs
      mlx->sprites.spriteWidth = abs((int)(mlx->parse.Height / mlx->sprites.transformY));
      mlx->sprites.drawStart_spriteX = (-mlx->sprites.spriteWidth / 2) +  mlx->sprites.sprite_screen;
      if(mlx->sprites.drawStart_spriteX < 0)
        mlx->sprites.drawStart_spriteX = 0;
      mlx->sprites.drawEnd_spriteX = (mlx->sprites.spriteWidth / 2) + mlx->sprites.sprite_screen;
      if(mlx->sprites.drawEnd_spriteX >= mlx->parse.Width)
        mlx->sprites.drawEnd_spriteX = mlx->parse.Width - 1;
      
      mlx->sprites.stripe = mlx->sprites.drawStart_spriteX;
      while (mlx->sprites.stripe < mlx->sprites.drawEnd_spriteX)
      {
        mlx->sprites.stripeX = (int)((256 * (mlx->sprites.stripe - (-mlx->sprites.spriteWidth / 2 + mlx->sprites.sprite_screen)) * textwidth / mlx->sprites.spriteWidth) / 256);

        int y;
        int d;
        y = mlx->sprites.drawStart_spriteY;
        if (mlx->sprites.transformY > 0 && mlx->sprites.stripe > 0 && mlx->sprites.stripe < mlx->parse.Width && mlx->sprites.transformY < mlx->sprites.Zbuffer[mlx->sprites.stripe])
        {           
            while (y < mlx->sprites.drawEnd_spriteY)
            {
              d = y * 256 - mlx->parse.Height * 128 + mlx->sprites.spriteHeight * 128;
              mlx->sprites.stripeY = ((d * textheight) / mlx->sprites.spriteHeight) / 256;
              if (mlx->sprites.img_spritedata0[mlx->sprites.stripeY % 64 * mlx->sprites.size_line + mlx->sprites.stripeX % 64 * mlx->sprites.bpp / 8] != 0)
                ft_memcpy_cub(mlx->img_data + 4 * mlx->parse.Width * y + 4 * mlx->sprites.stripe , &mlx->sprites.img_spritedata0[mlx->sprites.stripeY % 64 * mlx->sprites.size_line + mlx->sprites.stripeX % 64 * mlx->sprites.bpp / 8], sizeof(int));
              y++;
            }
        }
        mlx->sprites.stripe++;
      }
    }
}

void ft_sprites_init(t_deflibx *mlx)
{
	mlx->sprites.Zbufferset = 0;
	mlx->sprites.sprites_tabset = 0;
	mlx->sprites.spriteDistanceset = 0;
	mlx->sprites.spriteOrderset = 0;
}
