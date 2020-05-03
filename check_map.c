/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:51:36 by marvin            #+#    #+#             */
/*   Updated: 2020/05/03 23:36:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	ft_check_mapone(t_deflibx *mlx)
{
	int i;
	int j;

	j = 0;
	while (j < mlx->parse.mapbiggerline)
	{
		i = 0;
		while (mlx->parse.map[i][j] != '1')
		{
			if ((mlx->parse.map[i][j] != ' ' &&
			mlx->parse.map[i][j] != '\0') ||
			(mlx->parse.map[i][j - 1] == '0' ||
			mlx->parse.map[i][j + 1] == '0'))
			{
				ft_free_map(mlx);
				ft_return("Map not closed", mlx);
			}
			i++;
		}
		j++;
	}
}

void	ft_check_maptwo(t_deflibx *mlx)
{
	int i;
	int j;

	j = 0;
	while (j < mlx->parse.mapbiggerline)
	{
		i = mlx->parse.mapnbline - 1;
		while (mlx->parse.map[i][j] != '1' && i > 0)
		{
			if ((mlx->parse.map[i][j] != ' ' &&
			mlx->parse.map[i][j] != '\0') || (mlx->parse.map[i][j - 1] == '0'
			|| mlx->parse.map[i][j + 1] == '0'))
			{
				ft_free_map(mlx);
				ft_return("Map not closed", mlx);
			}
			i--;
		}
		j++;
	}
}

void	ft_check_map(t_deflibx *mlx)
{
	int i;
	int j;

	ft_check_firstandlast_line(mlx, mlx->parse.map[0]);
	ft_check_firstandlast_line(mlx, mlx->parse.map[mlx->parse.mapnbline - 1]);
	ft_check_mapone(mlx);
	ft_check_maptwo(mlx);
	ft_check_mapthree(mlx);
	ft_check_mapfour(mlx);
}
*/
static int	check_left_right(t_deflibx *cub, int x, int y)
{
	int n;
	int l;
	int r;

	r = 0;
	l = 0;
	n = y;
	while (y >= 0)
	{
		if (cub->parse.map[x][y] == '1' || cub->parse.map[x][y] == ' ')
			l = 1;
		y--;
	}
	y = n;
	while (cub->parse.map[x][y])
	{
		if (cub->parse.map[x][y] == '1' || cub->parse.map[x][y] == ' ')
			r = 1;
		y++;
	}
	return (l && r);
}

static int	check_top_bottom(t_deflibx *cub, int x, int y)
{
	int n;
	int b;
	int t;

	b = 0;
	t = 0;
	n = x;
	while (x >= 0 && y < (int)ft_strlen_cub(cub->parse.map[x]))
	{
		if (cub->parse.map[x][y] == '1' || cub->parse.map[x][y] == ' ')
			t = 1;
		x--;
	}
	x = n;
	while (cub->parse.map[x] && y < (int)ft_strlen_cub(cub->parse.map[x]))
	{
		if (cub->parse.map[x][y] == '1' || cub->parse.map[x][y] == ' ')
			b = 1;
		x++;
	}
	return (b && t);
}

static int	check_spaces(t_deflibx *cub, int x, int y)
{
	int t;
	int b;
	int r;
	int l;

	if (cub->parse.map[x][y] != ' ')
		return (1);
	t = 0;
	b = 0;
	r = 0;
	l = 0;
	if (!y || cub->parse.map[x][y - 1] == '1' || cub->parse.map[x][y - 1] == ' ')
		l = 1;
	if (!x || cub->parse.map[x - 1][y] == '1' || cub->parse.map[x - 1][y] == ' ')
		t = 1;
	if (!cub->parse.map[x][y + 1]
		|| cub->parse.map[x][y + 1] == '1' || cub->parse.map[x][y + 1] == ' ')
		r = 1;
	if (!cub->parse.map[x + 1]
		|| cub->parse.map[x + 1][y] == '1' || cub->parse.map[x + 1][y] == ' ')
		b = 1;
	return (t && b && l && r);
}

int			check_case(t_deflibx *cub, int x, int y)
{
	int a;
	int b;
	int c;

	a = check_top_bottom(cub, x, y);
	b = check_left_right(cub, x, y);
	c = check_spaces(cub, x, y);
	return (a && b && c);
}

void	ft_check_map(t_deflibx *cub)
{
	int i;
	int j;

	i = -1;
	while (++i < cub->parse.mapnbline)
	{
		j = -1;
		while (cub->parse.map[i][++j])
		{
			if ((!check_case(cub, i, j)))
				ft_return("Map isn't closed\n", cub);
		}
	}
}