/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:41:00 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/16 11:01:06 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	setting_east_west_walls(t_wall *wall, t_gbl *gbl, t_vectors *vec)
{
	if (vec->dist_side == 0 && vec->ray.x > 0)
	{
		wall->x_wall = gbl->p_pos.y + vec->res_dda * vec->ray.y;
		wall->x_wall -= floor(wall->x_wall);
		vec->geo = 'E';
		return (1);
	}
	else if (vec->dist_side == 0 && vec->ray.x <= 0)
	{
		wall->x_wall = gbl->p_pos.y + vec->res_dda * vec->ray.y;
		wall->x_wall = 1 - (wall->x_wall - floor(wall->x_wall));
		vec->geo = 'W';
		return (1);
	}
	return (0);
}

void	display_wall_launcher(t_wall *wall, t_gbl *gbl, t_vectors *vec)
{
	wall->ratio = vec->res_dda;
	if (wall->geo == 'N')
		wall_col(wall, gbl, &gbl->file.texture.north);
	else if (wall->geo == 'E')
		wall_col(wall, gbl, &gbl->file.texture.east);
	else if (wall->geo == 'S')
		wall_col(wall, gbl, &gbl->file.texture.south);
	else
		wall_col(wall, gbl, &gbl->file.texture.west);
}
