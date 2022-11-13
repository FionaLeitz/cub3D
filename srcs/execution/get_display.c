/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:56:29 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/13 14:33:35 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_ray(t_gbl *gbl, t_vectors *vec, double x)
{
	vec->view_line = 2 * x / WIDTH_MAX - 1;
	vec->ray_x = gbl->p_dir[0] + gbl->p_plane_r[0] * vec->view_line;
	vec->ray_y = gbl->p_dir[1] + gbl->p_plane_r[1] * vec->view_line;
	//ddX = sqrt(1 + (raydirY * raydirY) / (raydirX * raydirX));
	if (vec->ray_x == 0)
		vec->dd_x = 1e30;
	else
		vec->dd_x = fabs(1 / vec->ray_x);
	if (vec->ray_y == 0)
		vec->dd_y = 1e30;
	else
		vec->dd_y = fabs(1 / vec->ray_y);
	vec->pos_x = gbl->p_pos[0];	
	vec->pos_y = gbl->p_pos[1];	
}

void	check_n_step(t_gbl *gbl, t_vectors *vec)
{
	if (vec->ray_x < 0)
	{
		vec->step_x = -1;
		vec->side_x = (gbl->p_pos[0] - vec->pos_x) * vec->dd_x;
	}
	else
	{
		vec->step_x = 1;
		vec->side_x = (vec->pos_x + 1.0 - gbl->p_pos[0] * vec->dd_x);
	}
	if (vec->ray_y < 0)
	{
		vec->step_y = -1;
		vec->side_y = (gbl->p_pos[1] - vec->pos_y) * vec->dd_y;
	}
	else
	{
		vec->step_y = 1;
		vec->side_y = (vec->pos_y + 1.0 - gbl->p_pos[1]) * vec->dd_y;
	}
}

void	get_walls(t_gbl *gbl, t_vectors *vec, char **map)
{
	int	checker;
	int	map_x;
	int	map_y;

	(void)gbl;
	checker = 0;
	while (checker == 0)
	{
		if (vec->side_x < vec->side_y)
		{
			vec->side_x += vec->dd_x;
			vec->pos_x += vec->step_x;
			vec->side = 0;
			vec->res_dda = vec->side_x - vec->dd_x;
		}
		else
		{
			vec->side_y += vec->dd_y;
			vec->pos_y += vec->step_y;
			vec->side = 1;
			vec->res_dda = vec->side_y - vec->dd_y;
		}
		map_x = round(vec->pos_x);
		map_y = round(vec->pos_y);
		if (map[map_y][map_x] == '1')
			checker = 1;
	}
}

t_wall	get_geo_n_win_points(t_gbl *gbl, t_vectors *vec)
{
	t_wall	wall;

	if (vec->side == 0)
		wall.x_wall = gbl->p_pos[1] + vec->res_dda * vec->ray_y;
	else
		wall.x_wall = gbl->p_pos[0] + vec->res_dda * vec->ray_x;
	if (vec->side == 0 && vec->ray_x > 0)
		vec->geo = 'E';
	else if (vec->side == 0 && vec->ray_x <= 0)
		vec->geo = 'W';
	else if (vec->side == 1 && vec->ray_y > 0)
		vec->geo = 'S';
	else
		vec->geo = 'N';
	wall.geo = vec->geo;
	return (wall);
}

// vec->geo == 'N' -> north
// vec->geo == 'E' -> EAST
// vec->geo == 'S' -> SOUTH
// vec->geo == 'W' -> WEST
void	get_display_w_vectors(t_gbl *gbl, char **map)
{
	double		x;
	t_wall		wall;
	t_vectors	*vec;

	vec = &gbl->vec;
	printf("dans display w vec\n");
	x = 0;
	gbl->p_plane_r[0] = gbl->p_dir[0] * cos(RAD_PERP / 2) - gbl->p_dir[1] * sin(RAD_PERP / 2);
	// puis integration du ratio de l'angle utilisé par l'angle vers lequel on veut arriver
	gbl->p_plane_r[0] *= tan(RAD_PERP / 2); 
//	printf("new_img width ??? %d\n", gbl->new_img.width);
	// attention rot inversée , le y va dans le sens inverse
// en gros le truc suivant : x = point de depart de Vec1  +  point d'arrivee de Vec2
// et w = width (de la window ??? de la map ???)
	while (x < WIDTH_MAX)
	{
		get_ray(gbl, vec, x);
		check_n_step(gbl, vec);
		get_walls(gbl, vec, map);
		wall = get_geo_n_win_points(gbl, vec);
		display_wall_launcher(wall, gbl, vec);
	}
}
