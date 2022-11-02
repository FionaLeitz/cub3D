#include "../../cub3d.h"

// structure pour coordonnees
typedef struct s_mini
{
	int	x;
	int	y;
}		t_mini;

// met le carre rouge du personnage au centre
static void	put_pos(t_image *mini_map, t_gbl *gbl)
{
	char	*pixel;
	int		x;
	int		y;
	(void)gbl;

	y = 52;
	// carre de 3 pixels sur 3 pixels
	while (++y < 57)
	{
		x = 52;
		while (++x < 57)
		{
			// on recupere l'adresse dans la string de la ou on veut mettre un pixel de couleur
			pixel = mini_map->str + (y * mini_map->size_line + x * (mini_map->bpp / 8));
			// et on y met la couleur
			*(int *)pixel = 0x00ff0000;
		}
	}
}

// met les gros carres verts
static void	ft_square(t_mini coord, t_image *mini_map, int color)
{
	char	*pixel;
	t_mini	save;
	int	x;
	int	y;

	//printf("y, %d, x, %d\n", coord.y, coord.x);

	save.x = coord.x;
	coord.y = coord.y;
	y = -1;
	while (++y < 10)
	{
		coord.x = save.x;
		x = -1;
		while (++x < 10)
		{
			if (0 <= coord.x && coord.x < 110 && 0 <= coord.y && coord.y < 110)
			{
				pixel = mini_map->str + (coord.y * mini_map->size_line
						+ coord.x * (mini_map->bpp / 8));
				if (x == 0 || x == 9 || y == 0 || y == 9 || color == 0)
					*(int *)pixel = 0x00000000;
				else
					*(int *)pixel = 0x00006600;
			}
			coord.x++;
		}
		coord.y++;
	}
}

// la mini_maaaaaaaaap !!! 
int	mini_map(char **map, double p_pos[2], t_gbl *gbl)
{
	(void)map;
	t_mini	coord;
	int		x_start;
	int		x_map;
	int		y_map;
	double	y_pos = p_pos[1];
	double	x_pos = p_pos[0];
	double	tmp;

	// fonction d'arrondi : round() floor() ceil() rint() nearbyint()
	x_start = (int)rint(-modf(p_pos[0] + 0.5, &tmp) * 10) % 10;
	coord.y = (int)rint(-modf(p_pos[1] + 0.5, &tmp) * 10) % 10;
	// image de 11 carres sur 11 carres (de 10 pixels) donc image de 110 pixels sur 110 pixels
	printf("pos0: %f, x_start: %d\n", p_pos[0], x_start);
	printf("pos1: %f, y_start: %d\n", p_pos[1], coord.y);
	printf("x_map0 no modif: %f, x_map: %d\n",   (x_start / 10 + p_pos[0] - 5.49999),
	(int)(floor(x_start / 10 + p_pos[0] - 5.49999)));
	printf("y_map0 no modif: %f, y_map: %d\n\n", (coord.y / 10 + p_pos[1] - 5.49999),
	(int)(floor(coord.y / 10 + p_pos[1] - 5.49999)));
	// if (x_start == 0)
	//  	x_pos -= 1;
	// else if (x_start == -5)
	// 	x_start = -15;
	//  if (coord.y == 0)
	//  	y_pos -= 1;
	// else if (coord.y == -5)
	// 	coord.y = -15;
	while (coord.y < 110)
	{
		coord.x = x_start;
		while (coord.x < 110)
		{
			x_map = (int)(floor(coord.x / 10 + x_pos - 5.49999));
			y_map = (int)(floor(coord.y / 10 + y_pos - 5.49999));
			//printf("x_map no modif: %f, x_map: %d\n", (coord.x / 10 + p_pos[0] - 5.49999), x_map);
			//printf("y_map no modif: %f, y_map: %d\n\n", (coord.y / 10 + p_pos[1] - 5.49999), y_map);

			if (0 <= y_map && y_map <= gbl->y_max && 0 <= x_map && x_map <= (int)ft_strlen(map[y_map]) && map[y_map][x_map] == '1')
				ft_square(coord, &gbl->mini_map, 1);
			else
				ft_square(coord, &gbl->mini_map, 0);
			coord.x += 10;
		}
		coord.y += 10;
	}
	// carre rouge
	put_pos(&gbl->mini_map, gbl);
	// poser la mini_map dans la fenetre
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->mini_map.ptr, 680, 480);
	return (0);
}