/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:37:50 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/29 00:40:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_launch_text(t_deflibx *mlx)
{
	mlx->text.img_textptr0 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->parse.northtext, &mlx->text.width, &mlx->text.height);
	mlx->text.img_textptr1 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->parse.southtext, &mlx->text.width, &mlx->text.height);
	mlx->text.img_textptr2 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->parse.easttext, &mlx->text.width, &mlx->text.height);
	mlx->text.img_textptr3 = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->parse.westtext, &mlx->text.width, &mlx->text.height);
	mlx->text.img_textdata0 = mlx_get_data_addr(mlx->text.img_textptr0,
			&mlx->bpp, &mlx->size_line, &mlx->endian);
	mlx->text.img_textdata1 = mlx_get_data_addr(mlx->text.img_textptr1,
			&mlx->text.bpp, &mlx->text.size_line, &mlx->text.endian);
	mlx->text.img_textdata2 = mlx_get_data_addr(mlx->text.img_textptr2,
			&mlx->text.bpp, &mlx->text.size_line, &mlx->text.endian);
	mlx->text.img_textdata3 = mlx_get_data_addr(mlx->text.img_textptr3,
			&mlx->text.bpp, &mlx->text.size_line, &mlx->text.endian);
}

void	ft_destroy_textandsprites(t_deflibx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->text.img_textptr0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->text.img_textptr1);
	mlx_destroy_image(mlx->mlx_ptr, mlx->text.img_textptr2);
	mlx_destroy_image(mlx->mlx_ptr, mlx->text.img_textptr3);
	mlx_destroy_image(mlx->mlx_ptr, mlx->sprites.img_spriteptr0);
}

void	ft_drawtexturedwall(t_deflibx *mlx, int x)
{
	int y;

	y = mlx->raycast.drawStart;
	if (mlx->raycast.side <= 1)
		mlx->text.wallx = mlx->raycast.posy + mlx->raycast.perpWallDist *
			mlx->raycast.rayDirY;
	else
		mlx->text.wallx = mlx->raycast.posx + mlx->raycast.perpWallDist *
			mlx->raycast.rayDirX;
	mlx->text.x = (int)(mlx->text.wallx * (double)(TEXTWIDTH));
	mlx->text.x = TEXTWIDTH - mlx->text.x - 1;
	mlx->text.x = abs(mlx->text.x);
	while (y <= mlx->raycast.drawEnd)
	{
		mlx->text.y = abs((((y * 256 - mlx->parse.height * 128 +
			mlx->raycast.lineHeight * 128) * 64) /
			mlx->raycast.lineHeight) / 256);
		ft_memcpy_cub(mlx->img_data + 4 * mlx->parse.width * y + 4 * x,
			&mlx->text.img_textdata_utils[mlx->text.y % 64 *
			mlx->text.size_line + mlx->text.x % 64 *
			mlx->text.bpp / 8], sizeof(int));
		y++;
	}
}
