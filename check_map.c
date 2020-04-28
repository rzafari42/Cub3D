/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:51:36 by marvin            #+#    #+#             */
/*   Updated: 2020/04/28 18:47:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_mapfour(t_deflibx *mlx)
{
	int i;
	int j;

	j = 0;
	while (j < mlx->parse.mapbiggerline)
	{
		i = mlx->parse.mapnbline - 1;
		while (mlx->parse.map[i][j] != '1' && i > 0)
		{
			if (mlx->parse.map[i][j] != ' ' &&
			mlx->parse.map[i][j] != '\0')
			{
				ft_free_map(mlx);
				ft_return("Map not closed 4", mlx);
			}
			i--;
		}
		j++;
	}
}

void	ft_check_mapthree(t_deflibx *mlx)
{
	int i;
	int j;

	j = 0;
	while (j < mlx->parse.mapbiggerline)
	{
		i = 0;
		while (mlx->parse.map[i][j] != '1' &&
		i < mlx->parse.mapnbline - 1 &&
		mlx->parse.map[i][j] != '\0')
		{
			if (mlx->parse.map[i][j] != ' ')
			{
				ft_free_map(mlx);
				ft_return("Map not closed 3", mlx);
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

	i = 0;
	while (i < mlx->parse.mapnbline - 1)
	{
		j = mlx->parse.mapbiggerline - 1;
		while (mlx->parse.map[i][j] == '\0')
			j--;
		while (mlx->parse.map[i][j] != '1')
		{
			if (mlx->parse.map[i][j] != ' ')
			{
				ft_free_map(mlx);
				ft_return("Map not closed 2", mlx);
			}
			j--;
		}
		i++;
	}
}

void	ft_check_map(t_deflibx *mlx)
{
	int i;
	int j;

	ft_check_firstandlast_line(mlx, mlx->parse.map[0]);
	ft_check_firstandlast_line(mlx, mlx->parse.map[mlx->parse.mapnbline - 1]);
	i = 1;
	while (i < mlx->parse.mapnbline - 1)
	{
		j = 0;
		while (mlx->parse.map[i][j] != '1' && mlx->parse.map[i][j] != '\0')
		{
			if ((mlx->parse.map[i][j] != ' ' &&
			mlx->parse.map[i][j] != '\0') ||(mlx->parse.map[i - 1][j] == '0' ||
			mlx->parse.map[i + 1][j] == '0')) 
			{
				ft_free_map(mlx);
				ft_return("Map not closed 1", mlx);
			}
			j++;
		}
		i++;
	}
	ft_check_maptwo(mlx);
	ft_check_mapthree(mlx);
	ft_check_mapfour(mlx);
}
