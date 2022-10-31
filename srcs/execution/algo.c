/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:31:33 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/31 14:59:58 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// on check ici si les coordonnées de v_pos tapent un mur, et dans ce cas on return 1
// si non, on return 0 et on incrémente la distance par rapport au point de depart
// en ligne droite 
int		check_v_pos(t_gbl *gbl)
{
	t_map_lst	*map;
	double	y;

	y = 0;
	map = gbl->file.first;
	if (gbl->v_pos[0] >= 0  && gbl->v_pos[1] >= 0)
	{
		while (map)
		{
			if ((int)round(gbl->v_pos[0]) <= map->string_size
					&& map->map_line[(int)round(gbl->v_pos[0])]
					&& map->map_line[(int)round(gbl->v_pos[0])] == '1' )
				return (1);
			map = map->next;
		}
	}
	return (0);
}

// v_pos --> etabli les coordonnées de position du mur de face 
// au départ du programme --> distance du vecteur / point d'origine etc
// on incrémente petit a petit de 1 case
void	start_pos_to_check(t_gbl *gbl, char **map, double incr)
{
	if (map[(int)round(gbl->p_pos[1])][(int)round(gbl->p_pos[0])] == 'N')
	{
		gbl->v_pos[0] = gbl->p_pos[0];
		gbl->v_pos[1] = gbl->p_pos[1] - incr;
	}
	else if (map[(int)round(gbl->p_pos[1])][(int)round(gbl->p_pos[0])] == 'E')
	{
		gbl->v_pos[0] = gbl->p_pos[0] + incr;
		gbl->v_pos[1] = gbl->p_pos[1];
	}
	else if (map[(int)round(gbl->p_pos[1])][(int)round(gbl->p_pos[0])] == 'S')
	{
		gbl->v_pos[0] = gbl->p_pos[0];
		gbl->v_pos[1] = gbl->p_pos[1] + incr;
	}
	else if (map[(int)round(gbl->p_pos[1])][(int)round(gbl->p_pos[0])] == 'W')
	{
		gbl->v_pos[0] = gbl->p_pos[0] - incr;
		gbl->v_pos[1] = gbl->p_pos[1];
	}
}

// fonction lancée a chaque déplacement
// au début --> un check si on est au départ ou non
void	display_wall(t_gbl *gbl, char **map)
{
	double	i;
	double	check;
	t_wall	wall;

	i = -1;
	check = 0;
	if (gbl->start == 0)
	{
		while (++i && check_v_pos(gbl) == 0)
			start_pos_to_check(gbl, map, i);
		gbl->start = 1;
		gbl->vector = i;
		wall.x_window = -1;
		wall.x_wall = -1;
		wall.ratio = 0;
		while (check <= 5.399999)
		{
			++wall.x_window;
			wall.ratio = check_left(gbl, map) * 0.1;
			wall_col(wall, gbl, &gbl->file.texture.west);
			check += 0.05;
		}
		wall.x_window = WIDTH_MAX;
		wall.x_wall = -1;
		wall.ratio = 0;
		check = 0;
		while (check < 30)
		{
			--wall.x_window;
			wall.ratio = check_right(gbl, map) * 0.1;
			wall_col(wall, gbl, &gbl->file.texture.north);
			check += 0.05;
		}
	}
}
