
#include "cub3d.h"

void	ft_check_mapfournext(t_deflibx *mlx, int j)
{
    while (mlx->parse.map[i][j] != '1')
    {
        if ((mlx->parse.map[i][j] != ' ') ||
        (mlx->parse.map[i - 1][j] == '0' ||
        mlx->parse.map[i + 1][j] == '0'))
        {
            ft_free_map(mlx);
            ft_return("Map not closed", mlx);
        }
        j--;
    }
}

void	ft_check_mapfour(t_deflibx *mlx)
{
	int i;
	int j;

	i = 1;
	while (i < mlx->parse.mapnbline - 1)
	{
		j = mlx->parse.mapbiggerline - 1;
		while (mlx->parse.map[i][j] == '\0')
		{
			if (mlx->parse.map[i - 1][j] == '0' ||
			mlx->parse.map[i + 1][j] == '0')
			{
				ft_free_map(mlx);
				ft_return("Map not closed", mlx);
			}
			j--;
		}
		ft_check_mapfournext(mlx, j)
		i++;
	}
}

void	ft_check_mapthree(t_deflibx *mlx)
{
	int i;
	int j;

	i = 1;
	while (i < mlx->parse.mapnbline - 1)
	{
		j = 0;
		while (mlx->parse.map[i][j] != '1' && mlx->parse.map[i][j] != '\0')
		{
			if ((mlx->parse.map[i][j] != ' ' &&
			mlx->parse.map[i][j] != '\0') || (mlx->parse.map[i - 1][j] == '0' ||
			mlx->parse.map[i + 1][j] == '0'))
			{
				ft_free_map(mlx);
				ft_return("Map not closed", mlx);
			}
			j++;
		}
		i++;
	}
}