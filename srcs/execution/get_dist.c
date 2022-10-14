/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:13:14 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/14 17:52:21 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


/*
	dist between position and first wall on the north side
*/

double	get_real_vector_north(double *pos, double old_vector)
{
	double	tmp;
	double	diff;
	double	good_vector;

/*
	pour les 0,6 et plus il faut pas add + 1 mais garder juste pos[1] en int
	donc pour determiner la ce qu'on a apres la virgule 
	--> bitshift = decalade binaire sur les double (voir si c possible etc)
	fonctions magnifiques, qui s'appellent ceil (renvoie le nombre entier superieur)
	et floor (renvoie le nombre entier inferieur)
*/
	tmp = ceil(pos[1]);
	diff = pos[1] - tmp;
	printf("diff ?? %f\n", diff);
	if (diff > -1)
		good_vector = old_vector - diff;
	else 
		good_vector = -1;
	printf("good vector ?? %f\n", good_vector);
	return (good_vector);
}

double	get_int_vector_north(t_map_lst *map_lst, double *pos, int y_max)
{
	int		x;
	int		y;
	double	j;
	t_map_lst	*tmp = map_lst;

	x = (int)pos[0];
	y = (int)pos[1];
	j = 0;
	if (y < 0 || x < 0 || y > y_max)
		return (-1);
	y = -1;
	while (++y < (int)pos[1])
		tmp = tmp->next;
	if (tmp->string_size < x)
		return (-1);
	while (y >= 0)
	{
		if (tmp->map_line[x] == '1')
			return (j);
		j++;
		y--;
		tmp = tmp->prev;
	}
	return (0);
	/*
		passer en liste chainee + en gros quand on depasse le y max ou le x max 
		c'est des valeurs enregistrées dans la structure du maillon de la liste 
		du coup bah c plus simple a checker ici
	*/
/*	while (map && map[y] && map[y][x])
	{
	//	printf("coord(%d, %d) --> %c\n", x, y, map[y][x]);
		if (map[y][x] == '1')
			return (j);
		j++;
		y--;
	}
	return (0);*/
}

int	check_coord(int x, int y, double DE, char **map)
{
	(void)DE;
//	printf("in check_coord : x = %d	y = %d\n", x, y);
//	printf("map[y][x] = %c\n", map[y][x]);
	if (map[y] && map[y][x] && map[y][x] == '1')
	{
		// c ici fo afficher lol et ratio distance par DE
		return (1);
	}
	return (0);
}

double	get_left_dist(double AB, double *pos, char **map, double rad, double incr)
{
	double	BC;
	double	DE;
	double	AD;
	int		coord_x;
	int		coord_y;

	BC = AB / sin(HALF_FULL_RAD - (rad + RAD_PERP));
//	printf("AB (vector) = %f , BC = %f\n", AB, BC);
	AD = AB - (incr);
//	printf("AB (vector) = %f , BC = %f, AD = %f\n", AB, BC, AD);
	if (AD > 0)
		DE = (AD / AB) * BC;
	else
		return (0);
//	printf("donc DE = %f, pos[0] ok = %f\n", DE, pos[0]);
	coord_x = (int)ceil(pos[0] - DE);
	coord_y = (int)ceil(pos[1] - (RAD_FOV / rad));
// printf("BEFORE coord closest wall = (%d, %d)\n", coord_x, coord_y);
	if (check_coord(coord_x, coord_y, DE, map) == 1)
	{
//		affichage en fonction de DE
		printf("coord closest wall = (%d, %d)\n", coord_x, coord_y);
		return (DE);
	}
	else
		return (get_left_dist(AB, pos, map, rad, incr + 1));
}
