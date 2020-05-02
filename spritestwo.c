/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritestwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 02:18:43 by user42            #+#    #+#             */
/*   Updated: 2020/05/02 05:32:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_spritesheight(t_deflibx *mlx)
{
	mlx->sprites.spriteheight = abs((int)(mlx->parse.height /
				mlx->sprites.transformy));
	mlx->sprites.drawstart_spritey = (-mlx->sprites.spriteheight / 2) +
		(mlx->parse.height / 2);
	if (mlx->sprites.drawstart_spritey < 0)
		mlx->sprites.drawstart_spritey = 0;
	mlx->sprites.drawend_spritey = (mlx->sprites.spriteheight / 2) +
		(mlx->parse.height / 2);
	if (mlx->sprites.drawend_spritey >= mlx->parse.height)
		mlx->sprites.drawend_spritey = mlx->parse.height - 1;
}

void	ft_spriteswidth(t_deflibx *mlx)
{
	mlx->sprites.spritewidth = abs((int)(mlx->parse.height /
				mlx->sprites.transformy));
	mlx->sprites.drawstart_spritex = (-mlx->sprites.spritewidth / 2) +
		mlx->sprites.sprite_screen;
	if (mlx->sprites.drawstart_spritex < 0)
		mlx->sprites.drawstart_spritex = 0;
	mlx->sprites.drawend_spritex = (mlx->sprites.spritewidth / 2) +
		mlx->sprites.sprite_screen;
	if (mlx->sprites.drawend_spritex >= mlx->parse.width)
		mlx->sprites.drawend_spritex = mlx->parse.width - 1;
}

void	ft_project_spritesthree(t_deflibx *mlx, int y)
{
	int d;

	while (y < mlx->sprites.drawend_spritey)
	{
		d = y * 256 - mlx->parse.height * 128 +
			mlx->sprites.spriteheight * 128;
		mlx->sprites.stripey = ((d * TEXTHEIGHT) /
		mlx->sprites.spriteheight) / 256;
		if (mlx->sprites.img_spritedata0[
		mlx->sprites.stripey % 64 * mlx->sprites.size_line +
		mlx->sprites.stripex % 64 * mlx->sprites.bpp / 8] != 0)
			ft_memcpy_cub(mlx->img_data + 4 * mlx->parse.width * y +
		4 * mlx->sprites.stripe, &mlx->sprites.img_spritedata0[
		mlx->sprites.stripey % 64 * mlx->sprites.size_line +
		mlx->sprites.stripex % 64 * mlx->sprites.bpp / 8],
		sizeof(int));
		y++;
	}
}

void	ft_project_spritestwo(t_deflibx *mlx)
{
	int y;

	while (mlx->sprites.stripe < mlx->sprites.drawend_spritex)
	{
		mlx->sprites.stripex = (int)((256 * (mlx->sprites.stripe -
			(-mlx->sprites.spritewidth / 2 +
			mlx->sprites.sprite_screen)) * TEXTWIDTH /
			mlx->sprites.spritewidth) / 256);
		y = mlx->sprites.drawstart_spritey;
		if (mlx->sprites.transformy > 0 && mlx->sprites.stripe > 0 &&
		mlx->sprites.stripe < mlx->parse.width && mlx->sprites.transformy
		< mlx->sprites.zbuffer[mlx->sprites.stripe])
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
		mlx->sprites.spritex = mlx->sprites_tab[mlx->sprites.spriteorder[i]].x
			- mlx->raycast.posx;
		mlx->sprites.spritey = mlx->sprites_tab[mlx->sprites.spriteorder[i]].y
			- mlx->raycast.posy;
		mlx->sprites.invert = 1.0 / (mlx->raycast.planex * mlx->raycast.diry
			- mlx->raycast.dirx * mlx->raycast.planey);
		mlx->sprites.transformx = mlx->sprites.invert * (mlx->raycast.diry *
			mlx->sprites.spritex - mlx->raycast.dirx * mlx->sprites.spritey);
		mlx->sprites.transformy = mlx->sprites.invert * (-mlx->raycast.planey *
			mlx->sprites.spritex + mlx->raycast.planex * mlx->sprites.spritey);
		mlx->sprites.sprite_screen = (int)(mlx->parse.width / 2) * (1 +
				(mlx->sprites.transformx / mlx->sprites.transformy));
		ft_spritesheight(mlx);
		ft_spriteswidth(mlx);
		mlx->sprites.stripe = mlx->sprites.drawstart_spritex;
		ft_project_spritestwo(mlx);
	}
}
