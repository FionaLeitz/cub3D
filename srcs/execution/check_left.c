/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:22:14 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/31 15:02:27 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	check_left(t_gbl *gbl, char **map)
{
	double	y;
	double	x;
	int		ret;
//	p_pos[x, y]

//	le incr_max ca va etre le x_max du FOV 
	x = gbl->p_pos[0];
	y = gbl->p_pos[1];
	x--;
	y--;
	ret = check_pos(x, y, map);
	while (ret == 0)
	{
		x--;
		y--;
		ret = check_pos(x, y, map);
	//	incr += add_incr;
	}
	if (ret == 1)
	{
//		printf("LEFTil y a un mur a %f,%f youhou\n", x,y);
		return (get_fov_left_dist(gbl, x, y));
	}
	else if (ret == -1)
	{
		printf("olala tres mysterieux on sort de la map sans mur ??\n");
		return (-1);
	}
/*	while (check_pos(map, x, y, gbl) == 0)
	{
		check
		y++;
	}*/
	return (0);
}

double	get_fov_left_dist(t_gbl *gbl, double x, double y)
{
	double	res;
	double	one;
	double	two;

	one = (gbl->p_pos[0] - x);
	two = (gbl->p_pos[1] - y);
//	printf("LEFTTTT ONE IS %f and TWO IS %f \n", one, two);
	res = sqrt((one * one) + (two * two));
//	printf("LEFT RET = %f\n", res);
	return (res);
}
