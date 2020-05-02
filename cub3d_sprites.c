/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:06:43 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/02 04:07:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** cc -I /usr/local/include cub3d.c -L /usr/local/lib -lmlx -framework OpenGL
** -framework AppKit
** cc -lmlx -framework OpenGL -framework AppKit cub3d_sprites.c utils.c cub3d.h
** catching_keys.c initializations0*.c key_to_functions.c move0*.c raycasting.c
** sprites.c textures.c Ceil_Floor.c game_modes.c parsing.c get_next_line.c
** get_next_line_utils.c -D BUFFER_SIZE=2 libft.a
*/

int	main(int argc, char **argv)
{
	t_deflibx	mlx;

	ft_parse_initialization(&mlx);
	ft_parse_arguments(&mlx, argc, argv);
	ft_parsing(&mlx);
	initialization(&mlx);
	if (!(mlx->sprites.zbuffer = malloc(sizeof(double) * mlx->parse.width)))
		return (0);
	/*if (mlx.parse.save == 1)
	{
		key_deal(&mlx);
		ft_savebmp(&mlx);
	}
	else
	{*/
		while (1)
		{
			mlx_hook(mlx.win_ptr, 2, 1L << 0, keypress, &mlx);
			mlx_hook(mlx.win_ptr, 3, 1L << 1, keyrelease, &mlx);
			mlx_hook(mlx.win_ptr, 17, 1L << 17, killwindow, &mlx);
			mlx_loop_hook(mlx.mlx_ptr, key_deal, &mlx);
			mlx_loop(mlx.mlx_ptr);
		}
	//}
	ft_free_map(&mlx);
	ft_free(&mlx);
	return (0);
}
