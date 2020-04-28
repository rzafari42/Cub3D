/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingthree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:29:50 by marvin            #+#    #+#             */
/*   Updated: 2020/04/29 01:12:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_args(char *line, t_deflibx *mlx)
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
			i = ft_get_texturespath(line, i, mlx);
		else if (line[i] == 'F' || line[i] == 'C')
			i = ft_get_typecolor(line, i, mlx);
		else if (line[i] == 'R')
			i = ft_get_resolution(line, i, mlx);
		else if (ft_isdigit_cub(line[i]))
			return (2);
		else
			i++;
	}
	return (1);
}
