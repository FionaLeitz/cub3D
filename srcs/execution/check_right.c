/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:56:04 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/31 15:01:23 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	check_right(t_gbl *gbl, char ** map)
{
	double	x;
	double	y;
	int		ret;

	x = gbl->p_pos[0];
	y = gbl->p_pos[1];
	x++;
	y--;
	ret = check_pos(x, y, map);
	while (ret == 0)
	{
		x++;
		y--;
		ret = check_pos(x, y, map);
	}
	if (ret == 1)
	{
//		printf("RIGHTil y a un mur a %f,%f youhou\n", x,y);
		return (get_fov_right_dist(gbl, x, y));
	}
	else if (ret == -1)
	{
		printf("olala tres mysterieux on sort de la map sans mur ??\n");
		return (-1);
	}
	return (0);
}

double	get_fov_right_dist(t_gbl *gbl, double x, double y)
{
	double	res;
	double	one;
	double	two;

	one = (x - gbl->p_pos[0]);
	two = (gbl->p_pos[1] - y);
//	printf("RIGHT ONE IS %f and TWO IS %f\n", one, two);
	res = sqrt((one * one) + (two * two));
//	printf("RIGHT RET = %f\n", res);
	return (res);
}
