/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:49:25 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/28 00:28:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_if_space(t_deflibx *mlx)
{
	int i;

	i = 0;
	while (mlx->parse.resolution[i] != '\0')
	{
		if (mlx->parse.resolution[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_wall(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] == ' ')
		i++;
	if (s[i] == '1')
		return (1);
	return (0);
}
