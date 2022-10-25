#include "../../cub3d.h"

int	mini_map(char **map, double p_pos[2], t_gbl *gbl)
{
	(void)map;
	(void)p_pos;
	t_image	mini_map;
	int		x;
	int		y;
	char	*pixel;

	mini_map.ptr = mlx_new_image(gbl->mlx, 30, 30);
	if (mini_map.ptr == NULL || create_string(&mini_map) == 0)
		return (error_return("Error creating mini_map\n", 0));
	x = -1;
	while (++x <= 30)
	{
		y = -1;
		while (++y <= 30)
		{
			pixel = mini_map.str + (y * mini_map.size_line
					+ x * (mini_map.bpp / 8));
			*(int *)pixel = 0x0006600;
		}
	}
	mlx_put_image_to_window(gbl->mlx, gbl->window, mini_map.ptr, 10, 10);
	return (0);
}