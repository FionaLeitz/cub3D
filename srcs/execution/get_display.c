/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:56:29 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/15 22:49:49 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_ray(t_gbl *gbl, t_vectors *vec, double x)
{
	vec->view_line = 2 * x / WIDTH_MAX - 1;
	vec->ray = gbl->p_dir + gbl->p_plane * vec->view_line;
	if (vec->ray.x == 0)
		vec->dd.x = 1e30;
	else
		vec->dd.x = fabs(1 / vec->ray.x);
	if (vec->ray.y == 0)
		vec->dd.y = 1e30;
	else
		vec->dd.y = fabs(1 / vec->ray.y);
	vec->pos = gbl->p_pos;
}

void	check_n_step(t_vectors *vec)
{
	if (vec->ray.x < 0)
	{
		vec->step.x = -1;
		vec->side.x = (vec->pos.x - (int)vec->pos.x) * vec->dd.x;
	}
	else
	{
		vec->step.x = 1;
		vec->side.x = ((int)vec->pos.x + 1.0 - vec->pos.x) * vec->dd.x;
	}
	if (vec->ray.y < 0)
	{
		vec->step.y = -1;
		vec->side.y = (vec->pos.y - (int)vec->pos.y) * vec->dd.y;
	}
	else
	{
		vec->step.y = 1;
		vec->side.y = ((int)vec->pos.y + 1.0 - vec->pos.y) * vec->dd.y;
	}
}

t_wall	get_geo_n_win_points(t_gbl *gbl, t_vectors *vec)
{
	t_wall	wall;

	if (vec->dist_side == 0 && vec->ray.x > 0)
	{
		wall.x_wall = gbl->p_pos.y + vec->res_dda * vec->ray.y;
		wall.x_wall -= floor(wall.x_wall);
		vec->geo = 'E';
	}
	else if (vec->dist_side == 0 && vec->ray.x <= 0)
	{
		wall.x_wall = gbl->p_pos.y + vec->res_dda * vec->ray.y;
		wall.x_wall = 1 - (wall.x_wall - floor(wall.x_wall));
		vec->geo = 'W';
	}
	else if (vec->dist_side == 1 && vec->ray.y > 0)
	{
		wall.x_wall = gbl->p_pos.x + vec->res_dda * vec->ray.x;
		wall.x_wall = 1 - (wall.x_wall - floor(wall.x_wall));
		vec->geo = 'S';
	}
	else
	{
		wall.x_wall = gbl->p_pos.x + vec->res_dda * vec->ray.x;
		wall.x_wall -= floor(wall.x_wall);
		vec->geo = 'N';
	}
	wall.geo = vec->geo;
	return (wall);
}

void	get_display_w_vectors(t_gbl *gbl)
{
	double		x;
	t_wall		wall;
	t_vectors	*vec;
	int			checker;

	vec = &gbl->vec;
	x = 0;
	while (x < WIDTH_MAX)
	{
		get_ray(gbl, vec, x);
		check_n_step(vec);
		checker = get_walls(vec, gbl->file.map);
		wall = get_geo_n_win_points(gbl, vec);
		wall.x_window = x;
	//	if (checker != 1)
	//		vec->res_dda += x;
		display_wall_launcher(&wall, gbl, vec);
		x++;
	}
}
