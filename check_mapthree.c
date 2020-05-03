/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapthree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 19:30:50 by marvin            #+#    #+#             */
/*   Updated: 2020/05/03 19:30:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_check_mapsidethree(t_deflibx *mlx, int i, int j)
{
    int z;
    
    z = i - 1;
    if (mlx->parse.map[i - 1][j] == ' ')
    {
        while (mlx->parse.map[z][j] != '1' && z > 0)
        {
            if (mlx->parse.map[z][j] == '0' || mlx->parse.map[z][j - 1] == '0' || mlx->parse.map[z][j + 1] == '0')
                ft_return("NOT CLOSED SIDE 0", mlx);
            z--;
        }
    }
}