/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritestwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 02:18:43 by user42            #+#    #+#             */
/*   Updated: 2020/04/29 00:43:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_spritesheight(t_deflibx *mlx)
{
	mlx->sprites.spriteHeight = abs((int)(mlx->parse.height /
				mlx->sprites.transformY));
	mlx->sprites.drawStart_spriteY = (-mlx->sprites.spriteHeight / 2) +
		(mlx->parse.height / 2);
	if (mlx->sprites.drawStart_spriteY < 0)
		mlx->sprites.drawStart_spriteY = 0;
	mlx->sprites.drawEnd_spriteY = (mlx->sprites.spriteHeight / 2) +
		(mlx->parse.height / 2);
	if (mlx->sprites.drawEnd_spriteY >= mlx->parse.height)
		mlx->sprites.drawEnd_spriteY = mlx->parse.height - 1;
}

void	ft_spriteswidth(t_deflibx *mlx)
{
	mlx->sprites.spriteWidth = abs((int)(mlx->parse.height /
				mlx->sprites.transformY));
	mlx->sprites.drawStart_spriteX = (-mlx->sprites.spriteWidth / 2) +
		mlx->sprites.sprite_screen;
	if (mlx->sprites.drawStart_spriteX < 0)
		mlx->sprites.drawStart_spriteX = 0;
	mlx->sprites.drawEnd_spriteX = (mlx->sprites.spriteWidth / 2) +
		mlx->sprites.sprite_screen;
	if (mlx->sprites.drawEnd_spriteX >= mlx->parse.width)
		mlx->sprites.drawEnd_spriteX = mlx->parse.width - 1;
}

void	ft_project_spritesthree(t_deflibx *mlx, int y)
{
	int d;

	while (y < mlx->sprites.drawEnd_spriteY)
	{
		d = y * 256 - mlx->parse.height * 128 +
			mlx->sprites.spriteHeight * 128;
		mlx->sprites.stripeY = ((d * TEXTHEIGHT) /
		mlx->sprites.spriteHeight) / 256;
		if (mlx->sprites.img_spritedata0[
		mlx->sprites.stripeY % 64 * mlx->sprites.size_line +
		mlx->sprites.stripeX % 64 * mlx->sprites.bpp / 8] != 0)
			ft_memcpy_cub(mlx->img_data + 4 * mlx->parse.width * y +
		4 * mlx->sprites.stripe, &mlx->sprites.img_spritedata0[
		mlx->sprites.stripeY % 64 * mlx->sprites.size_line +
		mlx->sprites.stripeX % 64 * mlx->sprites.bpp / 8],
		sizeof(int));
		y++;
	}
}

void	ft_project_spritestwo(t_deflibx *mlx)
{
	int y;

	while (mlx->sprites.stripe < mlx->sprites.drawEnd_spriteX)
	{
		mlx->sprites.stripeX = (int)((256 * (mlx->sprites.stripe -
			(-mlx->sprites.spriteWidth / 2 +
			mlx->sprites.sprite_screen)) * TEXTWIDTH /
			mlx->sprites.spriteWidth) / 256);
		y = mlx->sprites.drawStart_spriteY;
		if (mlx->sprites.transformY > 0 && mlx->sprites.stripe > 0 &&
		mlx->sprites.stripe < mlx->parse.width && mlx->sprites.transformY
		< mlx->sprites.Zbuffer[mlx->sprites.stripe])
			ft_project_spritesthree(mlx, y);
		mlx->sprites.stripe++;
	}
}

void	ft_project_sprites(t_deflibx *mlx)
{
	int i;

	i = -1;
	while (++i < mlx->parse.numsprites)
	{
		mlx->sprites.spriteX = mlx->sprites_tab[mlx->sprites.spriteOrder[i]].x
			- mlx->raycast.posx;
		mlx->sprites.spriteY = mlx->sprites_tab[mlx->sprites.spriteOrder[i]].y
			- mlx->raycast.posy;
		mlx->sprites.invert = 1.0 / (mlx->raycast.planeX * mlx->raycast.dirY
			- mlx->raycast.dirx * mlx->raycast.planeY);
		mlx->sprites.transfomrX = mlx->sprites.invert * (mlx->raycast.dirY *
			mlx->sprites.spriteX - mlx->raycast.dirx * mlx->sprites.spriteY);
		mlx->sprites.transformY = mlx->sprites.invert * (-mlx->raycast.planeY *
			mlx->sprites.spriteX + mlx->raycast.planeX * mlx->sprites.spriteY);
		mlx->sprites.sprite_screen = (int)(mlx->parse.width / 2) * (1 +
				(mlx->sprites.transfomrX / mlx->sprites.transformY));
		ft_spritesheight(mlx);
		ft_spriteswidth(mlx);
		mlx->sprites.stripe = mlx->sprites.drawStart_spriteX;
		ft_project_spritestwo(mlx);
	}
	ft_freesprites(mlx);
}
