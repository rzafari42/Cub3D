
#include "cub3d.h"

void	ft_spritesHeight(t_deflibx *mlx)
{
	mlx->sprites.spriteHeight = abs((int)(mlx->parse.Height /
				mlx->sprites.transformY));
	mlx->sprites.drawStart_spriteY = (-mlx->sprites.spriteHeight / 2) +
		(mlx->parse.Height / 2);
	if (mlx->sprites.drawStart_spriteY < 0)
		mlx->sprites.drawStart_spriteY = 0;
	mlx->sprites.drawEnd_spriteY = (mlx->sprites.spriteHeight / 2) +
		(mlx->parse.Height / 2);
	if (mlx->sprites.drawEnd_spriteY >= mlx->parse.Height)
		mlx->sprites.drawEnd_spriteY = mlx->parse.Height - 1;
}

void	ft_spritesWidth(t_deflibx *mlx)
{
	mlx->sprites.spriteWidth = abs((int)(mlx->parse.Height /
				mlx->sprites.transformY));
	mlx->sprites.drawStart_spriteX = (-mlx->sprites.spriteWidth / 2) +
		mlx->sprites.sprite_screen;
	if (mlx->sprites.drawStart_spriteX < 0)
		mlx->sprites.drawStart_spriteX = 0;
	mlx->sprites.drawEnd_spriteX = (mlx->sprites.spriteWidth / 2) +
		mlx->sprites.sprite_screen;
	if (mlx->sprites.drawEnd_spriteX >= mlx->parse.Width)
		mlx->sprites.drawEnd_spriteX = mlx->parse.Width - 1;
}

void	ft_project_spritestwo(t_deflibx *mlx)
{
	int y;
	int d;

	while (mlx->sprites.stripe < mlx->sprites.drawEnd_spriteX)
	{
		mlx->sprites.stripeX = (int)((256 * (mlx->sprites.stripe -
			(-mlx->sprites.spriteWidth / 2 +
			 mlx->sprites.sprite_screen)) * textwidth /
			mlx->sprites.spriteWidth) / 256);
		y = mlx->sprites.drawStart_spriteY;
		if (mlx->sprites.transformY > 0 && mlx->sprites.stripe > 0 &&
		mlx->sprites.stripe < mlx->parse.Width && mlx->sprites.transformY
		< mlx->sprites.Zbuffer[mlx->sprites.stripe])
		{
			while (y < mlx->sprites.drawEnd_spriteY)
			{
				d = y * 256 - mlx->parse.Height * 128 +
					mlx->sprites.spriteHeight * 128;
				mlx->sprites.stripeY = ((d * textheight) /
				mlx->sprites.spriteHeight) / 256;
				if (mlx->sprites.img_spritedata0[
				mlx->sprites.stripeY % 64 * mlx->sprites.size_line +
				mlx->sprites.stripeX % 64 * mlx->sprites.bpp / 8] != 0)
				ft_memcpy_cub(mlx->img_data + 4 * mlx->parse.Width * y +
				4 * mlx->sprites.stripe, &mlx->sprites.img_spritedata0[
				mlx->sprites.stripeY % 64 * mlx->sprites.size_line +
				mlx->sprites.stripeX % 64 * mlx->sprites.bpp / 8],
				sizeof(int));
				y++;
			}
		}
		mlx->sprites.stripe++;
	}
}

void	ft_freesprites(t_deflibx *mlx)
{
	free(&mlx->sprites.spriteOrder[0]);
	free(&mlx->sprites_tab[0]);
	free(&mlx->sprites.Zbuffer[0]);
	free(&mlx->sprites.spriteDistance[0]);
}

void	ft_project_sprites(t_deflibx *mlx)
{
	int i;

	i = -1;
	while (++i < mlx->parse.numsprites)
	{
		mlx->sprites.spriteX = mlx->sprites_tab[mlx->sprites.spriteOrder[i]].x
			- mlx->raycast.posX;
		mlx->sprites.spriteY = mlx->sprites_tab[mlx->sprites.spriteOrder[i]].y
			- mlx->raycast.posY;
		mlx->sprites.invert = 1.0 / (mlx->raycast.planeX * mlx->raycast.dirY
			- mlx->raycast.dirX * mlx->raycast.planeY);
		mlx->sprites.transfomrX = mlx->sprites.invert * (mlx->raycast.dirY *
			mlx->sprites.spriteX - mlx->raycast.dirX * mlx->sprites.spriteY);
		mlx->sprites.transformY = mlx->sprites.invert * (-mlx->raycast.planeY *
			mlx->sprites.spriteX + mlx->raycast.planeX * mlx->sprites.spriteY);
		mlx->sprites.sprite_screen = (int)(mlx->parse.Width / 2) * (1 +
				(mlx->sprites.transfomrX / mlx->sprites.transformY));
		ft_spritesHeight(mlx);
		ft_spritesWidth(mlx);
		mlx->sprites.stripe = mlx->sprites.drawStart_spriteX;
		ft_project_spritestwo(mlx);
	}
	ft_freesprites(mlx);
}
