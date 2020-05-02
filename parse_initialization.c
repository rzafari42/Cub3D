/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:54:28 by marvin            #+#    #+#             */
/*   Updated: 2020/05/02 05:47:28 by rzafari42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_initialization(t_deflibx *mlx)
{
	mlx->text.width = 64;
	mlx->text.height = 64;
	mlx->sprites.width = 64;
	mlx->sprites.height = 64;
	mlx->parse.fcolorset = 0;
	mlx->parse.ccolorset = 0;
	mlx->parse.resolutionset = 0;
	mlx->parse.widthset = 0;
	mlx->parse.heightset = 0;
	mlx->parse.northset = 0;
	mlx->parse.southset = 0;
	mlx->parse.westset = 0;
	mlx->parse.eastset = 0;
	mlx->parse.blue = 0;
	mlx->parse.green = 0;
	mlx->parse.red = 0;
	mlx->parse.spriteset = 0;
	mlx->parse.positionset = 0;
	mlx->parse.save = 0;
	mlx->parse.numsprites = 0;
	mlx->parse.mapnbline = 0;
	mlx->parse.mapbiggerline = 0;
	mlx->sprites.zbufferset = 0;
}
