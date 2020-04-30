/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_to_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:44:48 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/01 00:48:56 by rzafari42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_deal(t_deflibx *mlx)
{
	if (mlx->move.keyup == 1)
		move_up(mlx);
	if (mlx->move.keydown == 1)
		move_down(mlx);
	if (mlx->move.keyright == 1)
		move_right(mlx);
	if (mlx->move.keyleft == 1)
		move_left(mlx);
	if (mlx->move.keyturnright == 1)
		turn_right(mlx);
	if (mlx->move.keyturnleft == 1)
		turn_left(mlx);
	if (mlx->move.killwindow == 1)
		killwindow(mlx);
	raycasting(mlx);	
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	ft_helpingbox(mlx);
	return (0);
}
