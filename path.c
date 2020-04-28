/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:58:31 by marvin            #+#    #+#             */
/*   Updated: 2020/04/29 01:12:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_path_to_one(char *line, int i, t_deflibx *mlx)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
		mlx->parse.northset = 1;
	if (line[i] == 'S' && line[i + 1] == 'O')
		mlx->parse.southset = 1;
	if (line[i] == 'W' && line[i + 1] == 'E')
		mlx->parse.westset = 1;
	if (line[i] == 'E' && line[i + 1] == 'A')
		mlx->parse.eastset = 1;
	if (line[i] == 'S' && line[i + 1] == ' ' && line[i + 1] != 'O')
		mlx->parse.spriteset = 1;
}

int		ft_check_path_set(char *line, int i, t_deflibx *mlx)
{
	if ((line[i] == 'N' && line[i + 1] == 'O' && mlx->parse.northset == 1)
	|| (line[i] == 'S' && line[i + 1] == 'O' && mlx->parse.southset == 1)
	|| (line[i] == 'W' && line[i + 1] == 'E' && mlx->parse.westset == 1)
	|| (line[i] == 'E' && line[i + 1] == 'A' && mlx->parse.eastset == 1)
	|| (line[i] == 'S' && line[i + 1] == ' ' && line[i + 1] != 'O' &&
		mlx->parse.spriteset == 1))
		return (1);
	else
		return (0);
}

void	ft_put_to_right_path(char *line, int i, t_deflibx *mlx)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
		mlx->parse.northtext = ft_strdup_cub(mlx->parse.path);
	if (line[i] == 'S' && line[i + 1] == 'O')
		mlx->parse.southtext = ft_strdup_cub(mlx->parse.path);
	if (line[i] == 'W' && line[i + 1] == 'E')
		mlx->parse.westtext = ft_strdup_cub(mlx->parse.path);
	if (line[i] == 'E' && line[i + 1] == 'A')
		mlx->parse.easttext = ft_strdup_cub(mlx->parse.path);
	if (line[i] == 'S' && line[i + 1] == ' ' && line[i + 1] != 'O')
		mlx->parse.sprite = ft_strdup_cub(mlx->parse.path);
	ft_set_path_to_one(line, i, mlx);
}

void	ft_get_texturespath_two(char *line, int i, t_deflibx *mlx)
{
	int j;
	int z;
	int l;

	j = 0;
	z = 0;
	while (line[i] != '.')
		i++;
	if (line[i] == '.')
	{
		l = i;
		while (line[l] != '\0')
		{
			j++;
			l++;
		}
		if (line[l - 1] != 'm' && line[l - 2] != 'p' &&
			line[l - 3] != 'x' && line[l - 4] != '.')
			ft_return("Bad file extension: not .xpm", mlx);
		if (!(mlx->parse.path = (char*)malloc(sizeof(char) * (j + 2))))
			ft_return("MALLOC ERROR :(", mlx);
		while (z < j + 1)
			mlx->parse.path[z++] = line[i++];
		mlx->parse.path[z] = '\0';
	}
}

int		ft_get_texturespath(char *line, int i, t_deflibx *mlx)
{
	int ret;

	if (ft_check_path_set(line, i, mlx) == 1)
	{
		ft_return("Texture declared twice", mlx);
		while (line[i] != '\0')
			i++;
		return (i);
	}
	ft_get_texturespath_two(line, i, mlx);
	ft_put_to_right_path(line, i, mlx);
	while (line[i] != '\0')
		i++;
	free(mlx->parse.path);
	return (i);
}
