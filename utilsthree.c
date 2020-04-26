/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsthree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:03:06 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/27 00:03:06 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_free(t_deflibx *mlx)
{
	int i;

    if (mlx->parse.resolutionset == 1)
	   free(mlx->parse.resolution);
    if (mlx->parse.widthset == 1)
        free(mlx->parse.Widthcatch);
    if (mlx->parse.heightset == 1)
        free(mlx->parse.Heightcatch);
    if (mlx->parse.northset == 1)
        free(mlx->parse.northtext);
    if (mlx->parse.southset == 1)
        free(mlx->parse.southtext);
    if (mlx->parse.westset == 1)
		free(mlx->parse.westtext);
	if (mlx->parse.eastset == 1)
        free (mlx->parse.easttext);
	if (mlx->parse.spriteset == 1)
		free (mlx->parse.sprite);
	i = 0;
	while (i <= 5)
	{
		close(mlx->parse.fd[i]);
		i++;
	}
}

int KillWindow(t_deflibx *mlx)
{
	ft_free_map(mlx);
	ft_free(mlx);
	exit (0);
}
