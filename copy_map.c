/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:30:32 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 20:25:59 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_copy_maptwo(t_deflibx *mlx, int fd, char *line)
{
	int i;
	int ret;
	char *temp;

	i = 0;
	temp = NULL;
	temp = mlx->parse.map[i];
	mlx->parse.map[i] = ft_strdup_zero(line, mlx);
	free(temp);
	free(line);
	i++;
	while ((ret = get_next_line(fd, &line)) > -1)
	{
		if (line[0] != '\0')
		{
			temp = mlx->parse.map[i];
			mlx->parse.map[i] = ft_strdup_zero(line, mlx);
			free (temp);
			i++;
		}
		free(line);
		if (ret == 0)
			break;
	}
	close(fd);
}

void	ft_copy_map(t_deflibx *mlx)
{
	int ret;
	int fd;
	char *line;

	ret = 0;
	if (!(line = (char*)malloc(sizeof(char))))
	{
		ft_free_map(mlx);
		ft_return("MALLOC ERROR :(", mlx);
	}
	line[0] = 1;
	if ((fd = open(mlx->parse.files, O_RDONLY)) < 0)
	{
		free(line);
		ft_free_map(mlx);
		ft_return("fd error in ft_copy_map", mlx);
	}
	while (!ft_check_wall(line))
	{
		free(line);
		ret = get_next_line(fd, &line);
	}
	ft_copy_maptwo(mlx, fd, line);
}
