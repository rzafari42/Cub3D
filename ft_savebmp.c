/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:42:04 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/04 23:29:03 by marvin           ###   ########.fr       */
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
}*/
static void		set_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

unsigned char	*create_file_header(t_deflibx *mlx, int pad)
{
	int						file_size;
	int						bpp;
	static unsigned char	file_header[14] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	bpp = BYTES_PER_PIX;
	file_size = 54 + (bpp * ((int)mlx->parse.width + pad) *
		(int)mlx->parse.height);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	set_in_char(file_header + 2, file_size);
	set_in_char(file_header + 10, FILE_HEADER_SIZE + IMG_HEADER_SIZE);
	return (file_header);
}

unsigned char	*create_img_header(int height, int width)
{
	static unsigned char img_header[40] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	set_in_char(img_header, 40);
	set_in_char(img_header + 4, width);
	set_in_char(img_header + 8, height);
	img_header[12] = (unsigned char)(1);
	set_in_char(img_header + 14, COMPRESSION);
	return (img_header);
}

int				write_headers(t_deflibx *mlx)
{
	if ((write(mlx->bmp.fd, mlx->bmp.file_header, FILE_HEADER_SIZE)) < 0)
	{
		close(mlx->bmp.fd);
		return (WRITE_FAIL);
	}
	if ((write(mlx->bmp.fd, mlx->bmp.file_header, IMG_HEADER_SIZE)) < 0)
	{
		close(mlx->bmp.fd);
		return (WRITE_FAIL);
	}
	return (SUCCESS);
}


int				write_colors(t_deflibx *mlx, int fd, int height, int width)
{
	static unsigned char	rgb[3] = {
		0, 0, 0 };
	int						i;
	int						j;

	i = 0;
	while (i < (int)mlx->parse.height)
	{
		j = 0;
		while (j < (int)mlx->parse.width)
		{
			rgb[0] = ((mlx->img_data[(height - i) * width + j]) >> 16);
			rgb[1] = ((mlx->img_data[(height - i) * width + j]) >> 8);
			rgb[2] = (mlx->img_data[(height - i) * width + j]);
			if ((write(fd, rgb + 2, 1)) < 0)
				return (0);
			if ((write(fd, rgb + 1, 1)) < 0)
				return (0);
			if ((write(fd, rgb, 1)) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				ft_save(t_deflibx *mlx)
{
	mlx->bmpdib.dibbmpheight = mlx->parse.height - 1;
	mlx->bmpdib.dibmpwidth = mlx->parse.width;
	mlx->bmp.pad = (4 - ((int)mlx->parse.width * 3) % 4) % 4;
	mlx->bmp.file_header = create_file_header(mlx, mlx->bmp.pad);
	mlx->bmp.img_header = create_img_header(mlx->bmpdib.dibmpHeight, mlx->bmpdib.dibmpwidth);
	if ((mlx->bmp.fd = open(SCREEN_PATH, O_WRONLY | O_CREAT, RIGHTS)) < 0)
		return (OPEN_ERR);
	if ((env->error = write_headers(mlx)) != SUCCESS)
		return (env->error);
	if ((env->error = write_colors(env, mlx->bmp.fd, mlx->bmpdib.dibbmpheight, mlx->bmpdib.dibbmpwidth))
		!= SUCCESS)
	{
		close(mlx->bmp.fd);
		ft_return ("error", mlx);
	}
	close(mlx->bmp.fd);
	return (1);
}

void    ft_savebmp(t_deflibx *mlx)
{
	ft_disp_screen(mlx);
	ft_save(env);
    killwindow(mlx);
}