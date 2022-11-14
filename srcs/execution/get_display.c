/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:56:29 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/14 13:35:00 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_ray(t_gbl *gbl, t_vectors *vec, double x)
{
	vec->view_line = 2 * x / WIDTH_MAX - 1;
	vec->ray = gbl->p_dir + gbl->p_plane * vec->view_line;

	//ddX = sqrt(1 + (raydirY * raydirY) / (raydirX * raydirX));
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

int	get_walls(t_vectors *vec, char **map)
{
	int	checker;
	int	map_x;
	int	map_y;

	checker = 0;
	while (checker == 0)
	{
		if (vec->side.x < vec->side.y)
		{
			vec->side.x += vec->dd.x;
			vec->pos.x += vec->step.x;
			vec->dist_side = 0;
			vec->res_dda = vec->side.x - vec->dd.x;
		}
		else
		{
			vec->side.y += vec->dd.y;
			vec->pos.y += vec->step.y;
			vec->dist_side = 1;
			vec->res_dda = vec->side.y - vec->dd.y;
		}
		map_x = (int)(vec->pos.x);
		map_y = (int)(vec->pos.y);
		if (check_point_in_map(map_x, map_y, map))
		{
			if (map[map_y][map_x] == '1')
				checker = 1;
			printf("resdda = %f\n", vec->res_dda);
		}
		else
		{
			printf("resdda = %f\n", vec->res_dda);
			checker = 2;
		}
	}
	return (checker);
}

t_wall	get_geo_n_win_points(t_gbl *gbl, t_vectors *vec)
{
	t_wall	wall;

	if (vec->dist_side == 0)
		wall.x_wall = gbl->p_pos.y + vec->res_dda * vec->ray.y;
	else
		wall.x_wall = gbl->p_pos.x + vec->res_dda * vec->ray.x;
	if (vec->dist_side == 0 && vec->ray.x > 0)
		vec->geo = 'E';
	else if (vec->dist_side == 0 && vec->ray.x <= 0)
		vec->geo = 'W';
	else if (vec->dist_side == 1 && vec->ray.y > 0)
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
void	get_display_w_vectors(t_gbl *gbl)
{
	double		x;
	t_wall		wall __attribute__((unused));
	t_vectors	*vec;
	int			checker;

	vec = &gbl->vec;
	x = 0;
	while (x < WIDTH_MAX)
	{
		get_ray(gbl, vec, x);
		check_n_step(vec);
		checker = get_walls(vec, FMAP);
		wall = get_geo_n_win_points(gbl, vec);
		wall.x_window = x;
		if (checker != 1)
			vec->res_dda += x;
		display_wall_launcher(&wall, gbl, vec);
		x++;
	}
}
