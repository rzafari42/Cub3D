/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtwo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:33:51 by marvin            #+#    #+#             */
/*   Updated: 2020/04/28 00:00:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_set(t_deflibx *mlx)
{
	if (mlx->parse.northset == 0)
		ft_return("North texture not declared", mlx);
	if (mlx->parse.southset == 0)
		ft_return("South texture not declared", mlx);
	if (mlx->parse.eastset == 0)
		ft_return("East texture not declared", mlx);
	if (mlx->parse.westset == 0)
		ft_return("West texture not declared", mlx);
	if (mlx->parse.resolutionset == 0)
		ft_return("Resolution not declared", mlx);
	if (mlx->parse.spriteset == 0)
		ft_return("Sprite not declared", mlx);
	if (mlx->parse.Ccolorset == 0)
		ft_return("Ceil color not declared", mlx);
	if (mlx->parse.Fcolorset == 0)
		ft_return("Floor color not declared", mlx);
} 

void	ft_openpath(t_deflibx *mlx)
{
	ft_check_set(mlx);
	if ((mlx->parse.fd[0] = open(mlx->parse.northtext, O_RDONLY)) < 0)
		ft_return("North text open problem", mlx);
	if ((mlx->parse.fd[1] = open(mlx->parse.southtext, O_RDONLY)) < 0)
		ft_return("South text open problem", mlx);
	if ((mlx->parse.fd[2] = open(mlx->parse.easttext, O_RDONLY)) < 0)
		ft_return("East text open problem", mlx);
	if ((mlx->parse.fd[3] = open(mlx->parse.westtext, O_RDONLY)) < 0)
		ft_return("West text open problem", mlx);
	if ((mlx->parse.fd[4] = open(mlx->parse.sprite, O_RDONLY)) < 0)
		ft_return("Sprite open problem", mlx);
}
