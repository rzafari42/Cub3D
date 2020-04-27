/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfillspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:08:00 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 18:08:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_fillspacethree(t_deflibx *mlx)
{
    int i;
    int j;

    i = 1;
    while (i < mlx->parse.mapnbline - 1)
    {
        j = 0;
        while (mlx->parse.map[i][j] != '\0')
        {
            if (mlx->parse.map[i][j] == '1')
            {
                j++;
                while(mlx->parse.map[i][j] != '\0')
                {
                    if (mlx->parse.map[i][j] == ' ')
                        mlx->parse.map[i][j] = '0';
                    j++;
                }
            }
            if (mlx->parse.map[i][j] == '\0')
                break;
            j++;
        }
        i++;
    }
}

void    ft_fillspacetwo(t_deflibx *mlx)
{
    int i;
    int j;

    i = mlx->parse.mapnbline - 1;
    j = 0;
    while(mlx->parse.map[i][j] != '\0')
    {
        if (mlx->parse.map[i][j] == '1')
        {
            j++;
            while(mlx->parse.map[i][j] != '\0')
                {
                    if (mlx->parse.map[i][j] == ' ')
                        mlx->parse.map[i][j] = '1';
                    j++;
                }
        }
        if (mlx->parse.map[i][j] == '\0')
                break;
        j++;
    }
    ft_fillspacethree(mlx);
}


void ft_fillspace(t_deflibx *mlx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(mlx->parse.map[i][j] != '\0')
    {
        if (mlx->parse.map[i][j] == '1')
        {
            j++;
            while(mlx->parse.map[i][j] != '\0')
                {
                    if (mlx->parse.map[i][j] == ' ')
                        mlx->parse.map[i][j] = '1';
                    j++;
                }
        }
        if (mlx->parse.map[i][j] == '\0')
                break;
        j++;
    }
    ft_fillspacetwo(mlx);
}