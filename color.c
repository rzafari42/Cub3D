/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:48:54 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/27 22:54:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_Color(t_deflibx *mlx)
{
	if (mlx->parse.red > 255 || mlx->parse.blue > 255 || mlx->parse.green > 255)
		ft_return("Color is over than 255", mlx);
}

int	ft_get_Color(char *line, int i, char c, t_deflibx *mlx)
{
	int d;
	char res[4];

	d = 0;
	ft_bzero_cub(res, 4);
	while (line[i] != ',' && line[i] != '\0')
	{
		if (d >= 3)
			ft_return("Color is invalid", mlx);
		if (line[i] == ' ')
			ft_return("Space in the color declaration", mlx);
		if (ft_isdigit_cub(line[i]))
			res[d++] = line[i++];
		else
			ft_return("Color Invalid: not a digit", mlx);
	}
	if (c == 'r')
		mlx->parse.red = ft_atoi_cub(res);
	if (c == 'g')
		mlx->parse.green = ft_atoi_cub(res);
	if (c == 'b')
		mlx->parse.blue = ft_atoi_cub(res);
	ft_check_Color(mlx);
	return (i);
}

int		ft_get_floor_color(char *line, int i, t_deflibx *mlx)
{
	while (!(ft_isdigit_cub(line[i])))
		i++;
	i = ft_get_Color(line, i, 'r', mlx);
	i++;
	i = ft_get_Color(line, i, 'g', mlx);
	i++;
	i = ft_get_Color(line, i, 'b', mlx);
	mlx->color.floorcolor = convertrgbtoint(mlx->parse.red,
			mlx->parse.green, mlx->parse.blue);
	return (i);
} 

int		ft_get_ceil_color(char *line, int i, t_deflibx *mlx)
{
	while (!(ft_isdigit_cub(line[i])))
		i++;
	i = ft_get_Color(line, i, 'r', mlx);
	i++;
	i = ft_get_Color(line, i, 'g', mlx);
	i++;
	i = ft_get_Color(line, i, 'b', mlx);
	mlx->color.ceilcolor = convertrgbtoint(mlx->parse.red,
			mlx->parse.green, mlx->parse.blue);
	return (i);
}

int		ft_get_typecolor(char *line, int i, t_deflibx *mlx)
{
	mlx->parse.blue = 0;
	mlx->parse.green = 0;
	mlx->parse.red = 0;
	if (line[i] == 'F')
	{
		if (mlx->parse.Fcolorset == 1)
			ft_return("Floor color declared twice", mlx);
		i = ft_get_floor_color(line, i, mlx);
		mlx->parse.Fcolorset = 1;
	}
	else if (line[i] == 'C')
	{
		if (mlx->parse.Ccolorset == 1)
			ft_return("Ceil color declared twice", mlx);
		i = ft_get_ceil_color(line, i, mlx);
		mlx->parse.Ccolorset = 1;
	}
	return (i);
}
