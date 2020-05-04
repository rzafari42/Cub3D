/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:51:36 by marvin            #+#    #+#             */
/*   Updated: 2020/05/04 16:29:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checksides(t_deflibx *mlx, int x, int y)
{
	int a;
	int b;
	int mem;

	a = 0;
	b = 0;
	mem = y;
	while (y >= 0)
	{
		if (mlx->parse.map[x][y] == '1' || mlx->parse.map[x][y] == ' ')
			a = 1;
		y--;
	}
	y = mem;
	while (y <= mlx->parse.mapbiggerline)
	{
		if (mlx->parse.map[x][y] == '1' || mlx->parse.map[x][y] == ' ')
			b = 1;
		y++;
	}
	return (a && b);
}

int	ft_checkupanddown(t_deflibx *mlx, int x, int y)
{
	int a;
	int b;
	int mem;

	a = 0;
	b = 0;
	mem = x;
	while (x >= 0)
	{
		if (mlx->parse.map[x][y] == '1' || mlx->parse.map[x][y] == ' ')
			a = 1;
		x--;
	}
	x = mem;
	while (x <= mlx->parse.mapnbline)
	{
		if (mlx->parse.map[x][y] == '1' || mlx->parse.map[x][y] == ' ')
			b = 1;
		x++;	
	}
	return (a && b);
}

int	ft_checkspaces(t_deflibx *mlx, int x, int y)
{
	int a;
	int b;
	int c;
	int d;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	if (mlx->parse.map[x][y] != ' ')
		return (1);
	if (!y || mlx->parse.map[x][y - 1] == '1' || mlx->parse.map[x][y - 1] == ' ')
		b = 1;
	if (!x || mlx->parse.map[x - 1][y] == '1' || mlx->parse.map[x - 1][y] == ' ')
		d = 1;
	if (!mlx->parse.map[x][y + 1] || mlx->parse.map[x][y + 1] == '1'
	|| mlx->parse.map[x][y + 1] == ' ')
		a = 1;
	if (x < mlx->parse.mapnbline - 1)
	{
		if (!mlx->parse.map[x + 1] || mlx->parse.map[x + 1][y] == '1'
		|| mlx->parse.map[x + 1][y] == ' ')
			c = 1;
	}
	else
		c = 1;
	return (a && b && c && d);
}

int			ft_checkcase(t_deflibx *mlx, int x, int y)
{
	int a;
	int b;
	int c;

	a = ft_checkupanddown(mlx, x, y);
	b = ft_checksides(mlx, x, y);
	c = ft_checkspaces(mlx, x, y);
	return (a && b && c);
}

void	ft_check_map(t_deflibx *mlx)
{
	int i;
	int j;

	i = -1;
	while (mlx->parse.map[++i] && i <= mlx->parse.mapnbline)
	{
		j = -1;
		while (mlx->parse.map[i][++j])
		{
			if ((!ft_checkcase(mlx, i, j)))
				ft_return("Map isn't closed\n", mlx);
		}
	}
}