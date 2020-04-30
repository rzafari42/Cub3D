/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:42:04 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/30 19:50:46 by rzafari42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void   ft_bmpinit(t_deflibx *mlx)
{
    mlx->bmp.signature = 0;
    mlx->bmp.size = 0;
    mlx->bmp.reservedid = 0;
    mlx->bmp.offset = 0;
    mlx->bmpdib.dibsizeheader = 0;
    mlx->bmpdib.dibmpwidth = 0;
    mlx->bmpdib.dibbmpheight = 0;
    mlx->bmpdib.dibcolorplanes = 0;
    mlx->bmpdib.dibbpp = 0;
   // mlx->bmp.diboffset[24] = NULL;
}

void ft_savebmpheader(t_deflibx *mlx, int fd)
{
     mlx->bmp.signature = 19778;
     mlx->bmp.size = 54 + 3 * mlx->parse.width * mlx->parse.height;
     mlx->bmp.reservedid = 0;
     mlx->bmp.offset = 54;
    mlx->bmpdib.dibsizeheader =  40;//sizeof(t_dibheader);
    mlx->bmpdib.dibmpwidth = mlx->parse.width;
    mlx->bmpdib.dibbmpheight = mlx->parse.height;
    mlx->bmpdib.dibcolorplanes = 1;
    mlx->bmpdib.dibbpp = 24;
     write(fd, &mlx->bmp.signature, 2);
     write(fd, &mlx->bmp.size, 4);
     write(fd, &mlx->bmp.reservedid, 4);
     write(fd, &mlx->bmp.offset, 4);
    write(fd, &mlx->bmpdib.dibsizeheader, 4);
    write(fd, &mlx->bmpdib.dibmpwidth, 4);
    write(fd, &mlx->bmpdib.dibbmpheight, 4);
    write(fd, &mlx->bmpdib.dibcolorplanes, 2);
    write(fd, &mlx->bmpdib.dibbpp, 2);
    write(fd, &mlx->bmp.reservedid, 4);
    write(fd, &mlx->bmp.reservedid, 4);
    write(fd, &mlx->bmp.reservedid, 4);
    write(fd, &mlx->bmp.reservedid, 4);
    write(fd, &mlx->bmp.reservedid, 4);
    write(fd, &mlx->bmp.reservedid, 4);
    //write(fd, &mlx->bmpdib.diboffset, 24);
    ft_savepixelarray(mlx, fd);
}

void ft_savedibheader(t_deflibx *mlx, int fd)
{


    //write(fd, &mlx->bmpdib.diboffset,24);
}

void ft_savepixelarray(t_deflibx *mlx, int fd)
{
    unsigned int    i;
    unsigned int    x;
    unsigned int    y;
    unsigned int   *tab;

    /*if (!(tab = ft_calloc_cub(3 * mlx->parse.width * mlx->parse.height, 1)))
        ft_return("Calloc error while saving in .bmp", mlx);*/
    if (!(tab = malloc(3 * mlx->parse.width * mlx->parse.height)))
	    ft_return("null", mlx);
    i = 0;
    y = mlx->parse.height;
    while (--y > 0)
    {
        x = 0;
        while ((int)x < mlx->parse.width)
        {
		tab[0] = mlx->img_data[0];
    	    printf("helo\n");
	    tab[i * 3] =  mlx->img_data[0];
            tab[i * 3 + 1] = mlx->img_data[0];
	    tab[i * 3 + 2] = mlx->img_data[0];
            i++;
            x++;
        }
    }
    write(fd, tab, 3 * mlx->parse.height * mlx->parse.width);
    free(tab);
	/*int	x;
	int	y;
	int 	line;
	
	y = mlx->parse.height;
	while (y > 0)
	{
		x = 0;
		while (x < mlx->parse.width)
		{
			write(fd, &mlx->img_data[y + 4 * x], 4);
			x++;
		}
		y--;
	}*/
}

void    ft_savebmp(t_deflibx *mlx)
{
    int fd;

    if ((fd = open("bmp", O_RDWR | O_CREAT , S_IRWXU | O_TRUNC)) < 0)
          ("Fd error while saving in .bmp", mlx);
    ft_savebmpheader(mlx, fd);
   // ft_savedibheader(mlx, fd);
    //ft_savepixelarray(mlx, fd);
    killwindow(mlx);
}

