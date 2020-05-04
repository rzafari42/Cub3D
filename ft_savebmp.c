/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:42:04 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/05 00:25:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
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

//    if (!(tab = ft_calloc_cub(3 * mlx->parse.width * mlx->parse.height, 1)))
  //      ft_return("Calloc error while saving in .bmp", mlx);
    if (!(tab = malloc(3 * mlx->parse.width * mlx->parse.height)))
	    ft_return("null", mlx);
    i = 0;
    y = mlx->parse.height;
    while (--y > 0)
    {
        x = 0;
        while ((int)x < mlx->parse.width)
        {
	
	    tab[i * 3] =  mlx->img_data[x * 4 + y * mlx->parse.width * 4];
            tab[i * 3 + 1] = mlx->img_data[x * 4 + y * mlx->parse.width * 4 + 1];
	    tab[i * 3 + 2] = mlx->img_data[x * 4 + y * mlx->parse.width * 4 + 2];
            //i++;
            x++;
        }
	i++;
 	printf("hi[%d]\n",y);
    }
    write(fd, tab, 3 * mlx->parse.height * mlx->parse.width);
    free(tab);*/
	/*int	x;
	int	y;
	int 	line;
	
	y = 0;
	while (y < mlx->parse.height)
	{
		x = 0;
		line = mlx->parse.width * (mlx->parse.height - y);
		while (x < mlx->parse.width)
		{
			write(fd, &mlx->img_data[line* 4], 4);
			line++;
			x++;
		}
		y++;
	}*/
//}

/*void    ft_savebmp(t_deflibx *mlx)
{
    int fd;

    if ((fd = open("bmp", O_RDWR | O_CREAT , S_IRWXU | O_TRUNC)) < 0)
          ("Fd error while saving in .bmp", mlx);
    ft_savebmpheader(mlx, fd);
	//mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
    // ft_savedibheader(mlx, fd);
    //ft_savepixelarray(mlx, fd);
    close(fd);
    killwindow(mlx);
}
*/

void		ft_init_struct_save(t_deflibx *mlx)
{
	mlx->bmp.size = 54 + 4 * mlx->parse.height * mlx->parse.width;
	mlx->bmp.reservedid = 0;
	mlx->bmp.offset = 54;
	mlx->bmpdib.dibsizeheader = 40;
	mlx->bmpdib.dibcolorplanes = 1;
	mlx->bmpdib.dibbpp = 32;
	mlx->bmp.fd = open("img.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (mlx->bmp.fd == -1)
		ft_return("fd error", mlx);
}

void		ft_write_texture_bmp_file(t_deflibx *mlx)
{
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

void		ft_write_bmp_file(t_deflibx *mlx)
{
	ft_init_struct_save(mlx);
	write(mlx->bmp.fd, "BM", 2);
	write(mlx->bmp.fd, &mlx->bmp.size, sizeof(int));
	write(mlx->bmp.fd, &mlx->bmp.reservedid, sizeof(int));
	write(mlx->bmp.fd, &mlx->bmp.offset, sizeof(int));
	write(mlx->bmp.fd, &mlx->bmpdib.dibsizeheader, sizeof(int));
	write(mlx->bmp.fd, &mlx->parse.width, sizeof(int));
	write(mlx->bmp.fd, &mlx->parse.height, sizeof(int));
	write(mlx->bmp.fd, &mlx->bmpdib.dibcolorplanes, sizeof(short int));
	write(mlx->bmp.fd, &mlx->bmpdib.dibbpp, sizeof(short int));
	write(mlx->bmp.fd, &mlx->bmp.reservedid, sizeof(int));
	write(mlx->bmp.fd, &mlx->bmp.reservedid, sizeof(int));
	write(mlx->bmp.fd, &mlx->bmp.reservedid, sizeof(int));
	write(mlx->bmp.fd, &mlx->bmp.reservedid, sizeof(int));
	write(mlx->bmp.fd, &mlx->bmp.reservedid, sizeof(int));
	write(mlx->bmp.fd, &mlx->bmp.reservedid, sizeof(int));
	ft_write_texture_bmp_file(mlx);
	close(mlx->bmp.fd);
}
void    ft_savebmp(t_deflibx *mlx)
{
	ft_disp_screen(mlx);
	ft_write_bmp_file(mlx);
    killwindow(mlx);
}