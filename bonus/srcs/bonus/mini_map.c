#include "../../cub3d.h"

typedef struct s_mini
{
	int	x;
	int	y;
}		t_mini;

void	put_pos(t_image *mini_map, t_gbl *gbl)
{
	char	*pixel;
	int		x;
	int		y;
	(void)gbl;

	y = 52;
	while (++y < 57)
	{
		x = 52;
		while (++x < 57)
		{
			pixel = mini_map->str + (y * mini_map->size_line + x * (mini_map->bpp / 8));
			*(int *)pixel = 0x00ff0000;
		}
	}
}

void	ft_square(t_mini *coord, t_image *mini_map)
{
	char	*pixel;
	t_mini	save;
	int	x;
	int	y;

	save.x = coord->x;
	save.y = coord->y;
	y = -1;
	while (++y < 10)
	{
		coord->x = save.x;
		x = -1;
		while (++x < 10)
		{
			if (coord->x >= 0 && coord->y >= 0 && coord->x < 110 && coord->y < 110)
			{
				pixel = mini_map->str + (coord->y * mini_map->size_line
						+ coord->x * (mini_map->bpp / 8));
				if (x == 0 || x == 9 || y == 0 || y == 9)
					*(int *)pixel = 0x00000000;
				else
					*(int *)pixel = 0x00006600;
			}
			coord->x++;
		}
		coord->y++;
	}
	coord->y = save.y;
}

int	mini_map(char **map, double p_pos[2], t_gbl *gbl)
{
	(void)map;
	t_image	mini_map;
	t_mini	coord;
	int		x_map;
	int		y_map;

	mini_map.ptr = mlx_new_image(gbl->mlx, 110, 110);
	if (mini_map.ptr == NULL || create_string(&mini_map) == 0)
		return (error_return("Error creating mini_map\n", 0));
	coord.x = ((int)round(p_pos[0] * 10) % 10) - 10;
	coord.y = ((int)round(p_pos[1] * 10) % 10) - 10;
	while (coord.y < 110)
	{
		while (coord.x < 110)
		{
			x_map = (int)(ceil(p_pos[0] - 5 + (coord.x / 10)));
			y_map = (int)(ceil(p_pos[1] - 5 + (coord.y / 10)));
			if (x_map >= 0 && y_map >= 0 && y_map <= gbl->y_max && x_map <= (int)ft_strlen(map[y_map]) && map[y_map][x_map] == '1')
			{
				printf("coord.x = %d	coord.y = %d\n", coord.x, coord.y);
				ft_square(&coord, &mini_map);
			}
			else
				coord.x += 10;
			if (coord.x >= 110)
				coord.y += 10;
		}
		coord.x = ((int)round(p_pos[0] * 10) % 10) - 10;
	}
	put_pos(&mini_map, gbl);
	mlx_put_image_to_window(gbl->mlx, gbl->window, mini_map.ptr, 680, 480);
	return (0);
}