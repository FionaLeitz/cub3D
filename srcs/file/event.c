#include "../../cub3d.h"

int	deal_key(int key, t_gbl *gbl)
{
	if (key == 119 || key == 65362)
	{
		ft_printf("haut\n");
	}
	else if (key == 115 || key == 65364)
	{
		ft_printf("bas\n");
	}
	else if (key == 97 || key == 65361)
	{
		ft_printf("gauche\n");
	}
	else if (key == 100 || key == 65363)
	{
		ft_printf("droite\n");
	}
	else if (key == 65307)
		mlx_loop_end(gbl->mlx);
	return (0);
}

int	deal_cross(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}
