/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:42:04 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/30 05:15:27 by rzafari42        ###   ########.fr       */
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
     mlx->bmp.size = 54 + 4 * mlx->parse.width * mlx->parse.height;
     mlx->bmp.reservedid = 0;
     mlx->bmp.offset = 54;
     write(fd, &mlx->bmp.signature, 2);
     write(fd, &mlx->bmp.size, 4);
     write(fd, &mlx->bmp.reservedid, 4);
     write(fd, &mlx->bmp.offset, 4);
}

void ft_savedibheader(t_deflibx *mlx, int fd)
{
    mlx->bmpdib.dibsizeheader = sizeof(t_dibheader);
    mlx->bmpdib.dibmpwidth = mlx->parse.width;
    mlx->bmpdib.dibbmpheight = mlx->parse.height;
    mlx->bmpdib.dibcolorplanes = 1;
    mlx->bmpdib.dibbpp = 24;
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
    //write(fd, &mlx->bmpdib.diboffset,24);
    //write(fd, &mlx->bmpdib.diboffset,24);
    //write(fd, &mlx->bmpdib.diboffset,24);
    //write(fd, &mlx->bmpdib.diboffset,24);
    //write(fd, &mlx->bmpdib.diboffset,24);
}

void ft_savepixelarray(t_deflibx *mlx, int fd)
{
   /*unsigned int    i;
    unsigned int    x;
    unsigned int    y;
    unsigned char   *tab;

    if (!(tab = ft_calloc_cub(3 * mlx->parse.Height * mlx->parse.Height, 1)))
        ft_return("Calloc error while saving in .bmp", mlx);
    i = 0;
    y = mlx->parse.Height;
    while (y > 0)
    {
        x = 0;
        while (x < mlx->parse.Width)
        {
    	    tab[i * 3] =  mlx->img_data[x + y * mlx->parse.Width] >> 0;
            tab[i * 3 + 1] = mlx->img_data[x + y * mlx->parse.Width] >> 8;
	    tab[i * 3 + 2] = mlx->img_data[x + y * mlx->parse.Width] >> 16;
            i++;
            x++;
        }
        y--;
    }
    write(fd, tab, 3 * mlx->parse.Height * mlx->parse.Width);
    free(tab);*/
    int		y;
	int		x;
	int		line;

	y = 0;
	while (y < mlx->parse.height)
	{
		x = 0;
		line = mlx->parse.width * (mlx->parse.height - y);
		while (x < mlx->parse.width)
		{
			write(fd, &mlx->img_data[line * 4], 4);
			line++;
			x++;
		}
		y++;
	}
}

void    ft_savebmp(t_deflibx *mlx)
{
    int fd;

    if ((fd = open("bmp", O_RDWR | O_CREAT , S_IRWXU | O_TRUNC)) < 0)
          ("Fd error while saving in .bmp", mlx);
    ft_savebmpheader(mlx, fd);
    ft_savedibheader(mlx, fd);
    ft_savepixelarray(mlx, fd);
    killwindow(mlx);
}

