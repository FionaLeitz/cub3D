/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:33:01 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/24 13:48:41 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_left_dist(t_gbl *gbl, double rad_to_use)
{
	double	third_angle;
	double	left_dist;

//	third_angle = HALF_FULL_RAD - (RAD_PERP + rad_to_use);

	third_angle = HALF_FULL_RAD - ((90 * HALF_FULL_RAD / 180) + rad_to_use);
	printf("////////////////////////////\n\tcalculs :\n\t\tHALF_FULL_RAD = %f\n\t\t rad_to_use = %f\n\t\tthird angle = %f\n", (90 * HALF_FULL_RAD / 180), rad_to_use, third_angle);
	left_dist = sin(third_angle) * (gbl->vector / sin(90 * HALF_FULL_RAD / 180));
	printf("left dist ? %f\n",left_dist);
	return (left_dist);
}
