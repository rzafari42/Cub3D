/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:06:43 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/15 01:02:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*cc -I /usr/local/include cub3d.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit*/
//cc -lmlx -framework OpenGL -framework AppKit cub3d_sprites.c utils.c cub3d.h catching_keys.c initializations0*.c key_to_functions.c move0*.c raycasting.c sprites.c textures.c Ceil_Floor.c game_modes.c parsing.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=2 libft.a

int main(int argc, char **argv)
{
  t_deflibx mlx;
  mlx.parse.files = "./map.cub";
  ft_parse_initialization(&mlx);
  ft_parsing(&mlx);
  initialization(&mlx);
  while (1)
  {
    mlx_hook(mlx.win_ptr, 2, 1 ,keyPress, &mlx);
    mlx_hook(mlx.win_ptr, 3, 1 ,keyRelease, &mlx);
    mlx_hook(mlx.win_ptr, 17, 1 ,KillWindow, &mlx);
    mlx_loop_hook(mlx.mlx_ptr, key_deal, &mlx);
    mlx_loop(mlx.mlx_ptr);
  }
  ft_free_map(&mlx);
  ft_free(&mlx);
  return (0);
}
