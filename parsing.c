/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:03:44 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/29 01:12:20 by marvin           ###   ########.fr       */
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
			if (j != 0)
			{
				if (line[j] != ' ' && line[j] != '0' &&
				line[j] != '1' && line[j] != '2' &&
				line[j] != 'N' && line[j] != 'S' &&
				line[j] != 'E' && line[j] != 'W')
					ft_return("Error in Map declaration", mlx);
			}
			j++;
		}
		if (j > mlx->parse.mapbiggerline)
			mlx->parse.mapbiggerline = j;
		mlx->parse.mapnbline++;
	}
}

void	ft_check_firstandlast_line(t_deflibx *mlx, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '1' && s[i] != '\0')
		{
			if (s[i] != ' ')
			{
				ft_free_map(mlx);
				ft_return("Map not closed: first line or last", mlx);
			}
			i++;
		}
		i++;
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
	ft_fillspace(mlx);
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
/*
** int main(int argc, char **argv)
** {
**    t_deflibx mlx;
**
**    mlx.parse.files = "./map.cu";
**    ft_parse_initialization(&mlx);
**    ft_parse_arguments(&mlx, argc, argv);
**    ft_parsing(&mlx);
**    printf("resolution = [%d %d]\n", mlx.parse.width, mlx.parse.height);
**    printf("Floor color = %d\n", mlx.color.floorcolor);
**    printf("Ceil color = %d\n", mlx.color.ceilcolor);
**    printf("north = %s\n", mlx.parse.northtext);
**    printf("south = %s\n", mlx.parse.southtext);
**    printf("east = %s\n", mlx.parse.easttext);
**    printf("west = %s\n", mlx.parse.westtext);
**    printf("sprite = %s\n", mlx.parse.sprite);
**    printf("WIDTH = %d\n", mlx.parse.width);
**    printf("HEIGHT = %d\n", mlx.parse.height);
**    printf("nortset = %d\n", mlx.parse.northset);
**    printf("southset = %d\n", mlx.parse.southset);
**    printf("westset = %d\n", mlx.parse.westset);
**    printf("eastset = %d\n", mlx.parse.eastset);
**    printf("spriteset = %d\n", mlx.parse.spriteset);
**    printf("numsprites = %d\n", mlx.parse.numsprites);
**    printf("biggerline = %d\n", mlx.parse.mapbiggerline);
**    ft_free(&mlx);
**
**    printf("sizeof unsined int = %ld\n", sizeof(unsigned int));
**    printf("sizeof unsigned short int = %ld\n", sizeof(unsigned short int));
**    printf("sizeof singed int = %ld\n", sizeof(int));
**    printf("sizeof unsigned char = %ld\n", sizeof(unsigned char));
** }
*/
