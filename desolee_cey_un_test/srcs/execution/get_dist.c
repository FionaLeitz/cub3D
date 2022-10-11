/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:13:14 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/11 22:05:02 by mcouppe          ###   ########.fr       */
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

	x = pos[0];
	y = pos[1];
	while (map && map[y] && map[y][x])
	{
		if (map[y][x] == '1')
			return ((double)y);
		y--;
	}
	return (0);
}

int	check_coord(int x, int y, double DE, char **map)
{
	(void)DE;
	if (map[y] && map[y][x] && map[y][x] == '1')
		return (1);
	return (0);
}

double	get_left_dist(double AB, double *pos, char **map, double rad)
{
	double	BC;
	double	DE;
	double	AD;
	int		coord_x;
	int		coord_y;

	BC = AB / sin(HALF_FULL_RAD - (rad + RAD_PERP));
	AD = AB - 1;
	if (AD > 0)
		DE = (AD * BC) / (AB * BC);
	else
		return (0);
	coord_x = ((double)pos[0] - DE);
	coord_y = ((double)pos[1] - (RAD_FOV / rad));
	if (check_coord(coord_x, coord_y, DE, map) == 1)
		return (DE);
	else
		return (get_left_dist(AB - 1, pos, map, rad));
}
