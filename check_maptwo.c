#include "cub3d.h"

int	ft_checkspacesnext(t_deflibx *mlx, int x, int y)
{
    int c;

    c = 0;
    if (x < mlx->parse.mapnbline - 1)
	{
		if (!mlx->parse.map[x + 1] || mlx->parse.map[x + 1][y] == '1'
		|| mlx->parse.map[x + 1][y] == ' ')
			c = 1;
	}
	else
		c = 1;
    return(c);
}