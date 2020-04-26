/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:42:04 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/23 14:42:04 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void   ft_bmpinit(t_deflibx *mlx)
{
    mlx->bmp.size = 0;
    mlx->bmp.reservedid = 0;
    mlx->bmp.offset = 0;
    mlx->bmp.dibsizeheader = 0;
    mlx->bmp.dibbmpheight = 0;
    mlx->bmp.dibbmpheight = 0;
    mlx->bmp.dibcolorplanes = 0;
    mlx->bmp.dibbpp = 0;
   // mlx->bmp.diboffset[24] = NULL;
}

void ft_savebmpheader(t_deflibx *mlx, int fd)
{
     mlx->bmp.size = 54 + 4 * mlx->parse.Width * mlx->parse.Height;
     mlx->bmp.reservedid = 0; 
     mlx->bmp.offset = 54;
     write(fd, "BM", 2);
     write(fd, &mlx->bmp.size, 4);
     write(fd, &mlx->bmp.reservedid, 4);
     write(fd, &mlx->bmp.offset, 4);
}

void ft_savedibheader(t_deflibx *mlx, int fd)
{
    mlx->bmp.dibsizeheader = 40;
    mlx->bmp.dibmpwidth = mlx->parse.Width;
    mlx->bmp.dibbmpheight = mlx->parse.Height;
    mlx->bmp.dibcolorplanes = 1;
    mlx->bmp.dibbpp = 24;
    write(fd, &mlx->bmp.dibsizeheader, 4);
    write(fd, &mlx->bmp.dibmpwidth, 4);
    write(fd, &mlx->bmp.dibbmpheight, 4);
    write(fd, &mlx->bmp.dibcolorplanes, 2);
    write(fd, &mlx->bmp.dibbpp, 2);
    
     write(fd, &mlx->bmp.reservedid, 4);
    write(fd, &mlx->bmp.reservedid, 4);
    write(fd, &mlx->bmp.reservedid, 4);
    write(fd, &mlx->bmp.reservedid, 4);
    write(fd, &mlx->bmp.reservedid, 4);
    write(fd, &mlx->bmp.reservedid, 4);
//     write(fd, &mlx->bmp.diboffset,24);
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
	while (y < mlx->parse.Height)
	{
		x = 0;
		line = mlx->parse.Width * (mlx->parse.Height - y);
		while (x < mlx->parse.Width)
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

    //ft_bmpinit(mlx);
    if ((fd = open("bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) < 0)
        ft_return ("Fd error while saving in .bmp", mlx);
    ft_savebmpheader(mlx, fd);
    ft_savedibheader(mlx, fd);
    ft_savepixelarray(mlx, fd);
    KillWindow(mlx);
}

