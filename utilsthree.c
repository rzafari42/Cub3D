/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsthree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:03:06 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/05 15:28:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(t_deflibx *mlx)
{
	int i;

	if (mlx->sprites.zbufferset == 1)
		free(mlx->sprites.zbuffer);
	if (mlx->parse.resolutionset == 1)
		free(mlx->parse.resolution);
	if (mlx->parse.widthset == 1)
		free(mlx->parse.widthcatch);
	if (mlx->parse.heightset == 1)
		free(mlx->parse.heightcatch);
	if (mlx->parse.northset == 1)
		free(mlx->parse.northtext);
	if (mlx->parse.southset == 1)
		free(mlx->parse.southtext);
	if (mlx->parse.westset == 1)
		free(mlx->parse.westtext);
	if (mlx->parse.eastset == 1)
		free(mlx->parse.easttext);
	if (mlx->parse.spriteset == 1)
		free(mlx->parse.sprite);
	i = -1;
	while (++i <= 5)
		close(mlx->parse.fd[i]);
}

int		killwindow(t_deflibx *mlx)
{
	//mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_free_map(mlx);
	ft_free(mlx);
	exit(0);
}

char	*ft_strdup_zero(const char *s1, t_deflibx *mlx)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s2 = (char*)malloc(sizeof(char) * (mlx->parse.mapbiggerline + 1))))
		ft_return("MALLOC ERROR :(", mlx);
	while (s1[j] != '\0')
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	while (j <= mlx->parse.mapbiggerline)
		s2[j++] = '\0';
	return (s2);
}

void	ft_return(char *s, t_deflibx *mlx)
{
	ft_putstr_cub("Error");
	ft_putstr_cub(s);
	ft_free(mlx);
	exit(0);
}

void	ft_free_map(t_deflibx *mlx)
{
	int i;

	i = 0;
	while (i <= mlx->parse.mapnbline)
	{
		free(mlx->parse.map[i]);
		i++;
	}
	free(mlx->parse.map);
}
