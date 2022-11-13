/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:40:00 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/13 13:59:42 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	display_wall(t_gbl *gbl)
{
	double	rad;
	//double	i;
	double	get_vector;
	double	incr;
	double	add_y;
	double	ray;
	//double	dist_x;
//	t_wall	wall;

//	get_player_pos(gbl->file.first, gbl);					// ne modifie pas la position ?
//	printf("check pos = pos[0] %f pos[1] %f\n", gbl->p_pos[0], gbl->p_pos[1]);
//	get_vector = get_int_vector_north(gbl->file.map, gbl->p_pos);
	get_vector = get_int_vector_north(gbl->file.first, gbl->p_pos, gbl->y_max);
	gbl->vector = get_real_vector_north(gbl->p_pos, get_vector);
	printf("bonjour gbl->vector = %f\n", gbl->vector);
	rad = RAD_FOV;
	incr = 1;
/******************************************************************************/
/**************		LE MUR LE PLUS PROCHE SUR LA GAUCHE		*******************/
/******************************************************************************/
//	printf("before get_left_dist : x = %f	y = %f\n", gbl->p_pos[0], gbl->p_pos[1]);
	add_y = 0.1;
//	i = get_left_dist(gbl, rad,add_y, 1);
//	gbl->left_fov_dist = i;
//	printf("rayon FOV gauche ? %f\n", i);
//	wall.x_window = -1;
//	wall.x_wall = -1;
//	wall.ratio = i * 0.1;
//	wall_col(wall, gbl, &gbl->file.texture.west);
	while (add_y < gbl->vector)
	{
		ray = get_left_dist(gbl, rad, add_y, incr);
		check_little_ray(gbl, add_y, ray);
		//(add_y / gbl->vector) * left_dist;
		/*if (check_ray(gbl, add_y, ray, dist_x) == 1)
		{
			wall.x_window = -1;
			wall.x_wall = -1;
			//i = get_left_dist(gbl, rad, add_y);
			wall.ratio = 1 / ray;
			wall_col(wall, gbl, &gbl->file.texture.west);
		}*/
		add_y += 0.1;
	}
	//printf("coucou\n");
	/*if (i > 0)
	{
		wall_col(wall, gbl, &gbl->file.texture.west);
		rad -= DECR_RAD;
		add_y += 0.1;
		while (rad > 0 && ++wall.x_window < WIDTH_MAX && incr < 10)
		{
			incr++;
			i = get_left_dist(gbl, rad, add_y, 1);
			wall.ratio = i * 0.1 ;			// pour gerer differentes tailles de textures, changer le 0.1
		//	if (incr == 1 || incr == 11 || incr == 31 || incr == 51 )
				printf("*************************\nvector = %f\n wall.ratio = %f\n", i, wall.ratio);
			wall_col(wall, gbl, &gbl->file.texture.north);
			rad -= DECR_RAD;
		}
	}*/

//	printf("left dist = %f\nx = %f	y = %f\n", i, gbl->p_pos[0], gbl->p_pos[1]);

	// while (rad > 0 && i != 0)
	// {
	// 	printf("lol i = %f et rad = %f\n", i, rad);
	
	// 	incr++;

	// 	i = get_left_dist(gbl, rad);
	// 	wall.ratio = i * 0.1;
	// 	wall.x_window += 1;
	// 	printf("i ? %f\n", i);
	// 	wall_col(wall, gbl, &gbl->file.texture.north);

	// 	//if (i != 0)
	// 		// on a un mur a distance i 
	// }

}
