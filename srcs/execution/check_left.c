/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:22:14 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/26 18:30:40 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_left(t_gbl *gbl, char **map)
{
	double	y;
	double	x;
	double	incr;
	double	incr_tmp;
	double	incr_max;
//	p_pos[x, y]

//	le incr_max ca va etre le x_max du FOV 
	x = gbl->p_pos[0];
	y = gbl->p_pos[1];
	incr = 1;
	incr_max = incr + 1;
	while (incr < incr_max)
	{
		incr_tmp = 1;
		check_pos
		incr_max++;
	}
/*	while (check_pos(map, x, y, gbl) == 0)
	{
		check
		y++;
	}*/
	while
}
