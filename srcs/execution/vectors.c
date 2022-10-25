/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:33:01 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/25 17:53:50 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_little_ray(t_gbl *gbl, double add_y, double left_dist)
{
	double	big_side;
	double	big_side_tmp;
	double	dist_x;
	double	left_vector;
	double	i;
	t_wall	wall;

//il faut add t_wall ici
	// AB = gbl->vector
	// AD = add_y
	// AC = left_dist
	// BC_tmp² = AC² - AB²
	// BC_tmp² = (left_dist * left_dist) - (gbl->vector * gbl->vector);
	// BC = sqrt(BC_tmp);
	big_side_tmp = (left_dist * left_dist) - (gbl->vector * gbl->vector);
	big_side = sqrt(big_side_tmp);
	// donc DE = (add_y / gbl->vector) * BC
	// du coup DE --> mon dist_x max dans mon FOV
	// dist_x = DE
	dist_x = (add_y / gbl->vector) * big_side;
	printf("\t\tbig side ? %f dist_x ? %f\n", big_side, dist_x);
	// lol ca ca a aucun sens 
	// le segfault vient des 2 prochaines lignes
	i = dist_x;
	while (i-- > 0)
	{
		// i correspond au parcours sur l'axe des x
		// sur la position verticale add_y
		// comme on parcourt de la gauche vers la droite et du plus près au plus loin
		// les premiers points qui sortent sont les premiers qu'on voit 
		if (check_coord_wall(gbl, i, add_y, dist_x) == 1)
		{
			// get AE
			left_vector = get_little_ray(add_y, i);
			wall.x_window = -1;
			wall.x_wall = -1;
			wall.ratio = 1 / left_vector;
			wall_col(wall, gbl, &gbl->file.texture.west);
		}
	}


}

double	get_little_ray(double add_y, double x)
{
	double	left_ray;
	double	left_ray_tmp;
	// l'angle x^add_y est rectangle
	left_ray_tmp = (x * x) + (add_y * add_y);
	left_ray = sqrt(left_ray_tmp);
	return (left_ray);
}

int	check_coord_wall(t_gbl *gbl, double stop, double add_y, double dist_x)
{
	int	map_x;
	int	map_y;
	int	i;
	t_map_lst	*map;

	i = -1;
	(void)stop;
	map = gbl->file.first;
	printf("positions de player = (%f, %f)\n", gbl->p_pos[0], gbl->p_pos[1]);
	map_x = round(gbl->p_pos[0] - dist_x/* + stop*/);
	map_y = round(gbl->p_pos[1] - add_y);
	printf("\t\tmap_x = %d map_y = %d\n", map_x, map_y);
	while (++i < map_y && map)
		map = map->next;
	if (map && i == map_y && map_x < map->string_size && map->map_line[map_x] == '1')
		return (1);
	return (0);
}








double	get_left_dist(t_gbl *gbl, double rad_to_use, double add_y, double add_x)
{
	double	third_angle;
	double	left_dist;
	//double	check_ray;
	double	check_ray_bis;

	third_angle = HALF_FULL_RAD - ((90 * HALF_FULL_RAD / 180) + rad_to_use);
	left_dist = sin((90 * HALF_FULL_RAD / 180)) * (gbl->vector / sin(third_angle));
	printf("left dist ? %f\n",left_dist);
	//check_ray = (add_x/ gbl->vector) * left_dist;
	check_ray_bis = ((gbl->vector - add_y) / gbl->vector) * left_dist;
	printf("~~~~~~\t\tCHECK_RAY\t\t~~~~~\n ADD_X %f ///// ADD_Y %f ///// check_ray_bis %f\n", add_x, add_y, check_ray_bis);
	return (left_dist);

}
/*
double	get_left_dist(t_gbl *gbl, double rad_to_use, double add_y, double add_x)
{
	double	third_angle;
	double	left_dist;
	double	check_ray;

//	third_angle = HALF_FULL_RAD - (RAD_PERP + rad_to_use);

	third_angle = HALF_FULL_RAD - ((90 * HALF_FULL_RAD / 180) + rad_to_use);
//	printf("////////////////////////////\n\tcalculs :\n\t\tHALF_FULL_RAD = %f\n\t\t rad_to_use = %f\n\t\tthird angle = %f\n", (90 * HALF_FULL_RAD / 180), rad_to_use, third_angle);

//	printf("left dist ? %f\n",left_dist);
	// ON CHERCHER LE POINT E ET DONC AE
	// DU COUP AE / left_dist = (gbl->vector - 1) / gbl->vector
	// AE / LEFT DIST = (gbl->vector - add_y) / gbl->vector
	check_ray = (add_x/ gbl->vector) * left_dist;
	printf("~~~~~~\t\tCHECK_RAY\t\t~~~~~%f\n ADD_X %f ///// ADD_Y %f\n", check_ray, add_x, add_y);
//	printf("les positions ici sont (%f, %f);\n", gbl->p_pos[0], gbl->p_pos[1]);
	if (check_coord_left_ray(check_ray, left_dist, gbl, add_x))
		return (check_ray);
	else
	{
		add_x++;
		get_left_dist(gbl, rad_to_use, add_y, add_x);
	}
	//if (check_coord_left_ray(check_ray, ))
	//check ray == p_pos[1] - 1 et p_pos[0] -= DE;
	//donc pour avoir DE il nous faut une autre fonction pour avoir BC deja
	return (left_dist);
}*/

int	check_coord_left_ray(double check_ray, double left_dist, t_gbl *gbl, double incr)
{
	double		dist_x;
	int			map_x;
	int			map_y;
	double		check_x;
	double		check_y;
	t_map_lst	*map;
// DE * DE + DA * DA = EA * EA 
// DE * DE  = check_ray *check_ray - (incr * incr);
// DE * DE = 
	(void)left_dist;
	//(soit y - 1)
	check_y = gbl->p_pos[1] - incr;
	map_y = 0;
	// on va calculer la distance en x entre le player et le 1er point de croisement entre
	// le rayon check_ray et le y - 1 (incr)
	dist_x = sqrt((check_ray * check_ray) - (incr * incr));
	printf("CHECK COOORD  =  dist_x %f, incr = %f\n", dist_x, incr);
	check_x = gbl->p_pos[0] - dist_x;

	// on va maintenant chercher dans la map les coordonnees check_x et check_y
	map = gbl->file.first;
	map_x = round(check_x);
	printf("check newcoord (%f, %f) && x_rounded = %d\n", check_x, check_y, map_x);
	while (map && ++map_y != check_y)
		map = map->next;
	if (map && map->map_line && map_x <= map->string_size && map->map_line[map_x] 
		&& map->map_line[map_x] == '1')
	{
		printf("MUR///////////////////MUR/////////////\n");
			return (1);
	}
	return (0);
}
