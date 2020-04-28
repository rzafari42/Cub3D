/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:46:14 by marvin            #+#    #+#             */
/*   Updated: 2020/04/28 22:27:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_transform_res_in_int(t_deflibx *mlx)
{
	mlx->parse.Width = ft_atoi_cub(mlx->parse.Widthcatch);
	mlx->parse.Height = ft_atoi_cub(mlx->parse.Heightcatch);
	if (mlx->parse.Width < 640)
		mlx->parse.Width = 640;
	if (mlx->parse.Height < 480)
		mlx->parse.Height = 480;
}

int		ft_line_to_resolution(char *line, int i, int j, t_deflibx *mlx)
{
	int c;
	int j;
	int nspace;

	c = 0;
	nspace = 0;
	/*while (!(ft_isdigit_cub(line[i])))
		i++;
	j = ft_strlen_cub(line) - i;*/
	if (!(mlx->parse.resolution = (char *)malloc(sizeof(char) * (j + 1))))
		ft_return("MALLOC ERROR :(", mlx);
	mlx->parse.resolutionset = 1;
	while (c < j)
	{
		if (!(ft_isdigit_cub(line[i])) && line[i] != '\0' && line[i] != ' ')
			ft_return("Resolution Error: NOT A DIGIT", mlx);
		nspace = (line[i] == ' ') ? (++nspace) : nspace;
		if (nspace > 1)
			ft_return("Invalid resolution: format", mlx);
		else
			mlx->parse.resolution[c++] = line[i++];
	}
	mlx->parse.resolution[c] = '\0';
	if ((c = ft_strlen_cub(mlx->parse.resolution)) > 9 || c < 7)
		ft_return("Resolution Error: TOO BIG or TOO SMALL", mlx);
	return (i);
}

void	ft_getwidth_from_resolution(t_deflibx *mlx)
{
	int j;
	int c;

	j = 0;
	c = 0;
	while (mlx->parse.resolution[j] != ' ')
		j++;
	if (!(mlx->parse.Widthcatch = (char *)malloc(sizeof(char) * (j + 1))))
		ft_return("MALLOC ERROR :(", mlx);
	mlx->parse.widthset = 1;
	j = 0;
	while (mlx->parse.resolution[j] != ' ')
	{
		mlx->parse.Widthcatch[j] = mlx->parse.resolution[j];
		j++;
	}
	mlx->parse.Widthcatch[j] = '\0';
}

void	ft_getheight_from_resolution(t_deflibx *mlx)
{
	int j;
	int c;
	int l;

	j = 0;
	while (mlx->parse.resolution[j] != ' ')
		j++;
	j++;
	l = 0;
	c = j;
	while (mlx->parse.resolution[j] != '\0')
	{
		l++;
		j++;
	}
	if (!(mlx->parse.Heightcatch = (char *)malloc(sizeof(char) * (l + 1))))
		ft_return("MALLOC ERROR :(", mlx);
	mlx->parse.heightset = 1;
	l = 0;
	while (mlx->parse.resolution[c] != '\0')
		mlx->parse.Heightcatch[l++] = mlx->parse.resolution[c++];
	mlx->parse.Heightcatch[l] = '\0';
}

int		ft_get_resolution(char *line, int i, t_deflibx *mlx)
{
	int j;

	j = 0;
	if (mlx->parse.resolutionset == 1)
		ft_return("Resolution declared twice", mlx);
	while (!(ft_isdigit_cub(line[i])))
		i++;
	j = ft_strlen_cub(line) - i;
	i = ft_line_to_resolution(line, i, j, mlx);
	if (!ft_check_if_space(mlx))
		ft_return("Resolution Error: syntax error", mlx);
	ft_getwidth_from_resolution(mlx);
	ft_getheight_from_resolution(mlx);
	ft_transform_res_in_int(mlx);
	return (i);
}
