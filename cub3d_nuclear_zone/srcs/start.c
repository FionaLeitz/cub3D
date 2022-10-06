/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:14:26 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/06 14:59:51 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3disaster.h"

/*
	for now, it's set in a very arbitrary way but the idea is to recover and 
	implement the dist from position to wall
*/
int	get_dist(char **map, int *pos)
{
	(void)map;
	return (pos[1] * 20);
}

/*
	all display are launched from here, potentially it's also here we can 
	implement the put_image_to_window function
*/
void	make_things_visible(char **map, int *pos, t_gbl *gbl)
{
		int	i;
		int	x;
		int	dist;

		i = -1;
		dist = get_dist(map, pos);
		while (++i < ft_strlen(map[0]))
			display_front_wall(pos, gbl, (i + 1), dist);
/*
	si on approche du mur le 690 augmente (environ + 50 par case ?)
	en fait il faut prevoir un ratio avec la taille de la window
*/
		i = 0;
		x = 261;
		while (x >= 0)
		{
			display_left_wall(gbl, (690 + (5 * i)), x , (90 - (5 * i)));
			i++;
			x -= 10;
		}
		i = 0;
		x = 1340;
		while (x < 1600)
		{
			display_right_wall(gbl, (690 + (5 * i)), x, (90 - (5 * i)));
			i++;
			x += 10;
		}
}

t_gbl	start(char *path)
{
	t_gbl	gbl;

	gbl.mlx = mlx_init();
	gbl.win = mlx_new_window(gbl.mlx, 1600, 800, "Cub3d 'isaster");
	gbl.map = getmap(path);
	gbl.p_pos = get_player_pos(gbl.map);
	make_things_visible(gbl.map, gbl.p_pos, &gbl);
	return (gbl);
}
