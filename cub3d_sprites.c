/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:06:43 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/05 17:01:35 by rzafari42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_deflibx	mlx;

	ft_parse_initialization(&mlx);
	ft_parse_arguments(&mlx, argc, argv);
	ft_parsing(&mlx);
	initialization(&mlx);
	if (mlx.parse.save == 1)
	{
		raycasting(&mlx);
		mlx_destroy_image(mlx.mlx_ptr, mlx.img_ptr);
		ft_savebmp(&mlx);
	}
	else
	{
		while (1)
		{
			mlx_hook(mlx.win_ptr, 2, 1L << 0, keypress, &mlx);
			mlx_hook(mlx.win_ptr, 3, 1L << 1, keyrelease, &mlx);
			mlx_hook(mlx.win_ptr, 17, 1L << 17, killwindow, &mlx);
			mlx_loop_hook(mlx.mlx_ptr, key_deal, &mlx);
			mlx_loop(mlx.mlx_ptr);
		}
	}
	ft_free_map(&mlx);
	ft_free(&mlx);
	return (0);
}
