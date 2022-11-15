/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:35:42 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/15 14:42:59 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_collision_checker(t_gbl *gbl)
{
	t_vec2	vec_tmp;
	int		map_x;
	int		map_y;
	int		checker;

	vec_tmp = gbl->p_pos;
	vec_tmp.x += gbl->p_dir.x * SPEED;
	checker = 0;
	map_x = (int)vec_tmp.x;
	map_y = (int)vec_tmp.y;
	if (check_point_in_map(map_x, map_y, gbl->file.map))
	{
		if (gbl->file.map[map_y][map_x] == '1')
			checker++;
	}
	vec_tmp.y += gbl->p_dir.y * SPEED;
	map_y = (int)vec_tmp.y;
	if (check_point_in_map(map_x, map_y, gbl->file.map))
	{
		if (gbl->file.map[map_y][map_x] == '1')
			checker++;
	}
	return (checker);
}
