/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:33:01 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/24 10:47:10 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_left_dist(t_gbl *gbl)
{
	double	third_angle;
	double	left_dist;

	third_angle = HALF_FULL_RAD - (RAD_PERP + RAD_FOV);

	left_dist = sin(RAD_PERP) * (gbl->vector / sin(RAD_FOV));
	printf("left dist ? %f\n",left_dist);
	return (left_dist);
}
