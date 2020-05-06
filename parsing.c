/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:03:44 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/06 02:53:12 by rzafari42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_linesize(char *line, t_deflibx *mlx)
{
	int j;

	j = 0;
	if (line[0] != '\0')
	{
		while (line[j] != '\0')
		{
			if (line[0] != ' ' && line[0] != '1')
				ft_return("Error in Map declaration", mlx);
			if (line[j] != ' ' && line[j] != '0' &&
				line[j] != '1' && line[j] != '2' &&
				line[j] != 'N' && line[j] != 'S' &&
				line[j] != 'E' && line[j] != 'W')
				ft_return("Error in Map declaration", mlx);
			j++;
		}
		if (j > mlx->parse.mapbiggerline)
			mlx->parse.mapbiggerline = j;
		mlx->parse.mapnbline++;
	}
}

void	ft_map(t_deflibx *mlx, char *line, int fd)
{
	int j;
	int i;

	j = 0;
	i = 0;
	ft_line_map(mlx);
	if (!(mlx->parse.map = (char**)malloc(sizeof(char*) *
	(mlx->parse.mapnbline + 1))))
		ft_return("MALLOC ERROR :(", mlx);
	while (j <= mlx->parse.mapnbline)
	{
		if (!(mlx->parse.map[j] = (char*)malloc(sizeof(char) *
		(mlx->parse.mapbiggerline + 1))))
		{
			while (i < j)
			{
				free(mlx->parse.map[i]);
				i++;
			}
			free(mlx->parse.map);
			ft_return("MALLOC ERROR :(", mlx);
		}
		ft_bzero_cub(mlx->parse.map[j], mlx->parse.mapbiggerline);
		j++;
	}
}

int		ft_read0(int fd, t_deflibx *mlx)
{
	char	*line;
	int		ret;
	int		map;

	while ((ret = get_next_line(fd, &line)) > -1 &&
	!(map = ft_check_wall(line)))
	{
		if (!(ft_check_args(line, mlx)))
			return (0);
		free(line);
		if (ret == 0)
			break ;
	}
	ft_openpath(mlx);
	if (map == 0)
		ft_return("Map Missing", mlx);
	free(line);
	ft_map(mlx, line, fd);
	ft_copy_map(mlx);
	ft_check_map(mlx);
	ft_catch_positionandnumsprites(mlx);
	return (1);
}

int		ft_parsing(t_deflibx *mlx)
{
	int fd;

	if ((fd = open(mlx->parse.files, O_RDONLY)) < 0)
	{
		ft_return("File path incorect", mlx);
		return (0);
	}
	if (!(ft_read0(fd, mlx)))
		return (0);
	close(fd);
	return (1);
}
