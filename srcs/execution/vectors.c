/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:33:01 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/24 16:47:20 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_left_dist(t_gbl *gbl, double rad_to_use, double incr)
{
	double	third_angle;
	double	left_dist;
	double	check_ray;

//	third_angle = HALF_FULL_RAD - (RAD_PERP + rad_to_use);

	third_angle = HALF_FULL_RAD - ((90 * HALF_FULL_RAD / 180) + rad_to_use);
	printf("////////////////////////////\n\tcalculs :\n\t\tHALF_FULL_RAD = %f\n\t\t rad_to_use = %f\n\t\tthird angle = %f\n", (90 * HALF_FULL_RAD / 180), rad_to_use, third_angle);
	left_dist = sin((90 * HALF_FULL_RAD / 180)) * (gbl->vector / sin(third_angle));
	printf("left dist ? %f\n",left_dist);
	// ON CHERCHER LE POINT E ET DONC AE
	// DU COUP AE / left_dist = (gbl->vector - 1) / gbl->vector
	check_ray = (incr/ gbl->vector) * left_dist;
	printf("~~~~~~\t\tCHECK_RAY\t\t~~~~~%f\n", check_ray);
	printf("les positions ici sont (%f, %f);\n", gbl->p_pos[0], gbl->p_pos[1]);
	if (check_coord_left_ray(check_ray, left_dist, gbl, incr))
		return (check_ray);
	else
		get_left_dist(gbl, rad_to_use, (++incr));
	//if (check_coord_left_ray(check_ray, ))
	/*check ray == p_pos[1] - 1 et p_pos[0] -= DE;
	donc pour avoir DE il nous faut une autre fonction pour avoir BC deja*/
	return (left_dist);
}

int	check_coord_left_ray(double check_ray, double left_dist, t_gbl *gbl, double incr)
{
	double	dist_x;
	double	map_x;
	double	map_y;
	double	check_x;
	double	check_y;
	t_map_lst	*map;
// DE * DE + DA * DA = EA * EA 
// DE * DE  = check_ray *check_ray - (incr * incr);
// DE * DE = 
	(void)left_dist;
	//(soit y - 1)
	check_y = p_pos[1] - incr;
	map_x = 0;
	map_y = 0;
	// on va calculer la distance en x entre le player et le 1er point de croisement entre
	// le rayon check_ray et le y - 1 (incr)
	dist_x = sqrt((check_ray * check_ray) - (incr * incr));
	printf("CHECK COOORD  =  dist_x %f\n", dist_x);
	check_x = p_pos[0] - dist_x;
	// on va maintenant chercher dans la map les coordonnees check_x et check_y
	map = gbl->file.first;

	return (1);
}
