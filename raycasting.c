/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:34:38 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/02 00:51:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** 3 differents modes: 0 = texture, 1 = electron, 2 = color walls
*/

void	ft_dda(t_deflibx *mlx)
{
	mlx->color.color = convertrgbtoint(mlx->color.r, mlx->color.g,
			mlx->color.b);
	while (mlx->raycast.hit == 0)
	{
		if (mlx->move.mode == 0 || mlx->move.mode == 2)
		{
			ft_normal_mode(mlx);
			mlx->color.effectccolor = mlx->color.ceilcolor;
			mlx->color.effectfcolor = mlx->color.floorcolor;
		}
		if (mlx->move.mode == 1)
			ft_electro_mode(mlx);
		if (mlx->parse.map[mlx->raycast.mapx][mlx->raycast.mapy] == '1')
			mlx->raycast.hit = 1;
	}
}

void	raycastingprojectcalcul(t_deflibx *mlx)
{
	if (mlx->raycast.side == 0 || mlx->raycast.side == 1)
		mlx->raycast.perpwalldist = ((mlx->raycast.mapx - mlx->raycast.posx +
				(1 - mlx->raycast.stepx) / 2) / mlx->raycast.raydirx) + 0.5;
	else
		mlx->raycast.perpwalldist = ((mlx->raycast.mapy - mlx->raycast.posy +
				(1 - mlx->raycast.stepy) / 2) / mlx->raycast.raydiry) + 0.5;
	if (mlx->raycast.perpwalldist <= 0)
		mlx->raycast.perpwalldist *= -1;
	mlx->raycast.lineheight = (int)(mlx->parse.height /
			mlx->raycast.perpwalldist);
	mlx->raycast.drawstart = -mlx->raycast.lineheight / 2 +
		mlx->parse.height / 2;
	if (mlx->raycast.drawstart < 0)
		mlx->raycast.drawstart = 0;
	mlx->raycast.drawend = mlx->raycast.lineheight / 2 + mlx->parse.height / 2;
	if (mlx->raycast.drawend >= mlx->parse.height)
		mlx->raycast.drawend = mlx->parse.height - 1;
}

void	raycastingrayandstepcalcultwo(t_deflibx *mlx)
{
	if (mlx->raycast.raydirx < 0)
	{
		mlx->raycast.stepx = -1;
		mlx->raycast.sidedistx = (mlx->raycast.posx - mlx->raycast.mapx) *
			mlx->raycast.deltadistx;
	}
	else
	{
		mlx->raycast.stepx = 1;
		mlx->raycast.sidedistx = (mlx->raycast.mapx + 1.0 - mlx->raycast.posx) *
			mlx->raycast.deltadistx;
	}
	if (mlx->raycast.raydiry < 0)
	{
		mlx->raycast.stepy = -1;
		mlx->raycast.sidedisty = (mlx->raycast.posy - mlx->raycast.mapy) *
			mlx->raycast.deltadisty;
	}
	else
	{
		mlx->raycast.stepy = 1;
		mlx->raycast.sidedisty = (mlx->raycast.mapy + 1.0 - mlx->raycast.posy) *
			mlx->raycast.deltadisty;
	}
}

void	raycastingrayandstepcalcul(t_deflibx *mlx, int x)
{
	mlx->raycast.camerax = 2 * x / (double)mlx->parse.width - 1;
	mlx->raycast.raydirx = mlx->raycast.dirx + mlx->raycast.planex *
		mlx->raycast.camerax;
	mlx->raycast.raydiry = mlx->raycast.diry + mlx->raycast.planey *
		mlx->raycast.camerax;
	mlx->raycast.mapx = (int)mlx->raycast.posx;
	mlx->raycast.mapy = (int)mlx->raycast.posy;
	mlx->raycast.deltadistx = fabs(1 / mlx->raycast.raydirx);
	mlx->raycast.deltadisty = fabs(1 / mlx->raycast.raydiry);
	mlx->raycast.hit = 0;
	raycastingrayandstepcalcultwo(mlx);
}

int		raycasting(t_deflibx *mlx)
{
	int	x;

	x = -1;
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->parse.width,
			mlx->parse.height);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_line,
			&mlx->endian);
	ft_launch_text(mlx);
	ft_launch_sprites(mlx);
	while (++x < mlx->parse.width)
	{
		color_initializatin(mlx);
		raycastingrayandstepcalcul(mlx, x);
		ft_dda(mlx);
		raycastingprojectcalcul(mlx);
		ft_draw_ceil(mlx, x);
		raycastingtextures(mlx, x);
		ft_draw_floor(mlx, x);
		if (!raycastingsprites(mlx, x))
			return (0);
		ft_freesprites(mlx);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	ft_destroy_textandsprites(mlx);	
	if (mlx->parse.save == 1)
		ft_savebmp(mlx);
//	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	return (0);
}
