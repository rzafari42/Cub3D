/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingtwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 19:17:11 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 23:44:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_catch_positionandnumsprites(t_deflibx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->parse.mapnbline - 1)
	{
		j = 0;
		while (mlx->parse.map[i][j] != '\0')
		{
			if (mlx->parse.map[i][j] == '2')
				mlx->parse.numsprites++;
			if (mlx->parse.map[i][j] == 'N' || mlx->parse.map[i][j] == 'S' ||
			mlx->parse.map[i][j] == 'E' || mlx->parse.map[i][j] == 'W')
			{
				if (mlx->parse.positionset == 1)
				{
					ft_return("More than one position declared", mlx);
					free(mlx);
				}
				mlx->parse.positionx = i;
				mlx->parse.positiony = j;
				mlx->parse.position = mlx->parse.map[i][j];
				mlx->parse.positionset = 1;
				mlx->parse.directionset = 1;
				mlx->parse.map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	ft_parse_arguments(t_deflibx *mlx, int argc, char **argv)
{
	if (argc < 2)
		ft_return("Missing arguments", mlx);
	if (argc > 3)
		ft_return("Too many arguments", mlx);
	mlx->parse.files = argv[1];
	if (argc == 3)
	{
		if (ft_strncmp_cub("--save", argv[2],
			ft_strlen_cub("--save")) == 0)
			mlx->parse.save = 1;
		else
			ft_return("error save", mlx);
	}
}

void	ft_line_maptwo(t_deflibx *mlx, int fd, char *line)
{
	int ret;

	ret = 0;
	while (!ft_check_wall(line))
	{
		free(line);
		ret = get_next_line(fd, &line);
	}
	ft_linesize(line, mlx);
	free(line);
	while ((ret = get_next_line(fd, &line)) > -1)
	{
		ft_linesize(line, mlx);
		free(line);
		if (ret == 0)
			break ;
	}
	close(fd);
}

void	ft_line_map(t_deflibx *mlx)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = 1;
	mlx->parse.mapnbline = 0;
	if (!(line = (char*)malloc(sizeof(char))))
		ft_return("MALLOC ERROR :(", mlx);
	line[0] = 1;
	if ((fd = open(mlx->parse.files, O_RDONLY)) < 0)
	{
		free(line);
		ft_return("fd error in ft_line_map", mlx);
	}
	ft_line_maptwo(mlx, fd, line);
}

int		ft_check_args(char *line, t_deflibx *mlx)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == 'N' && line[i + 1] == 'O')
				|| (line[i] == 'S' && line[i + 1] == 'O')
				|| (line[i] == 'W' && line[i + 1] == 'E')
				|| (line[i] == 'E' && line[i + 1] == 'A')
				|| (line[i] == 'S' && line[i + 1] == ' '
				&& line[i + 1] != 'O'))
			i = ft_get_Texturespath(line, i, mlx);
		else if (line[i] == 'F' || line[i] == 'C')
			i = ft_get_typecolor(line, i, mlx);
		else if (line[i] == 'R')
			i = ft_get_Resolution(line, i, mlx);
		else if (ft_isdigit_cub(line[i]))
			return (2);
		else
			i++;
	}
	return (1);
}
