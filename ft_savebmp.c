/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:42:04 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/06 18:52:37 by rzafari42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bmpinit(t_deflibx *mlx)
{
	if ((mlx->bmp.fd = open("bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC)) < 0)
		ft_return("Fd error while saving in .bmp", mlx);
	mlx->bmp.signature = 19778;
	mlx->bmp.size = 54 + 3 * mlx->parse.width * mlx->parse.height;
	mlx->bmp.reservedid = 0;
	mlx->bmp.offset = 54;
	mlx->bmpdib.dibsizeheader = 40;
	mlx->bmpdib.dibmpwidth = mlx->parse.width;
	mlx->bmpdib.dibbmpheight = mlx->parse.height;
	mlx->bmpdib.dibcolorplanes = 1;
	mlx->bmpdib.dibbpp = 32;
}

void	ft_savebmpheader(t_deflibx *mlx)
{
	write(mlx->bmp.fd, &mlx->bmp.signature, 2);
	write(mlx->bmp.fd, &mlx->bmp.size, 4);
	write(mlx->bmp.fd, &mlx->bmp.reservedid, 4);
	write(mlx->bmp.fd, &mlx->bmp.offset, 4);
	write(mlx->bmp.fd, &mlx->bmpdib.dibsizeheader, 4);
	write(mlx->bmp.fd, &mlx->bmpdib.dibmpwidth, 4);
	write(mlx->bmp.fd, &mlx->bmpdib.dibbmpheight, 4);
	write(mlx->bmp.fd, &mlx->bmpdib.dibcolorplanes, 2);
	write(mlx->bmp.fd, &mlx->bmpdib.dibbpp, 2);
	write(mlx->bmp.fd, &mlx->bmp.reservedid, 4);
	write(mlx->bmp.fd, &mlx->bmp.reservedid, 4);
	write(mlx->bmp.fd, &mlx->bmp.reservedid, 4);
	write(mlx->bmp.fd, &mlx->bmp.reservedid, 4);
	write(mlx->bmp.fd, &mlx->bmp.reservedid, 4);
	write(mlx->bmp.fd, &mlx->bmp.reservedid, 4);
}

void	ft_savepixelarray(t_deflibx *mlx)
{
	int	i;
	int	j;
	int	pos;

	j = 0;
	while (j < mlx->parse.height)
	{
		i = mlx->parse.width;
		pos = mlx->parse.width * (mlx->parse.height - j);
		while (i > 0)
		{
			write(mlx->bmp.fd, &mlx->img_data[4 * pos], 4);
			i--;
			pos++;
		}
		j++;
	}
}

void	ft_savebmp(t_deflibx *mlx)
{
	raycasting(mlx);
	ft_bmpinit(mlx);
	ft_savebmpheader(mlx);
	ft_savepixelarray(mlx);
	close(mlx->bmp.fd);
	killwindow(mlx);
}
