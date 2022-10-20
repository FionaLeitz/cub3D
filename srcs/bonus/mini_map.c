#include "../../cub3d.h"
/*
void	mini_map(char **map, double p_pos[2], t_image img)
{
	(void)map;
	(void)p_pos;
	char	*pixel;
	int		x;
	int		y;

	x = 10;
	while (x <= 140)
	{
		y = 10;
		while (y <= 140)
		{
			if (x == 10 || x == 140 || y == 10 || y == 140)
			{
				pixel = img.str + (y * img.size_line + x * (img.bpp / 8));
				*(int *)pixel = 0xFF006600;
			}
			else if (map[p_pos[0]][p_pos[1]] == 1)
			{
				pixel = img.str + (y * img.size_line + x * (img.bpp / 8));
				*(int *)pixel = 0xFF000000;
			}
			y += 2;
		}
		x += 2;
	}
}*/