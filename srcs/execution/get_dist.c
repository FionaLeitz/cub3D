/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:13:14 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/12 15:39:01 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


/*
	dist between position and first wall on the north side
*/

double	get_vector(char **map, double *pos)
{
	int		x;
	int		y;
	double	j;

	x = (int)pos[0];
	y = (int)pos[1];
	j = 0;
	while (map && map[y] && map[y][x])
	{
	//	printf("coord(%d, %d) --> %c\n", x, y, map[y][x]);
		if (map[y][x] == '1')
			return (j);
		j++;
		y--;
	}
	return (0);
}

int	check_coord(int x, int y, double DE, char **map)
{
	(void)DE;
//	printf("in check_coord : x = %d	y = %d\n", x, y);
//	printf("map[y][x] = %c\n", map[y][x]);
	if (map[y] && map[y][x] && map[y][x] == '1')
		return (1);
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
	AD = AB - (incr + 1);
//	printf("AB (vector) = %f , BC = %f, AD = %f\n", AB, BC, AD);
	if (AD > 0)
		DE = (AD / AB) * BC;
	else
		return (0);
//	printf("donc DE = %f, pos[0] ok = %f\n", DE, pos[0]);
	coord_x = (int)(pos[0] - DE + 1);
	coord_y = (int)(pos[1] - (RAD_FOV / rad));
	if (check_coord(coord_x, coord_y, DE, map) == 1)
		return (DE);
	else
		return (get_left_dist(AB, pos, map, rad, incr + 1));
}
