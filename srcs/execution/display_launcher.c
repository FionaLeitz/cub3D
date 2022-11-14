/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:41:00 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/13 13:54:46 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_wall_launcher(t_wall *wall, t_gbl *gbl, t_vectors *vec)
{
	wall->ratio = vec->res_dda;

	if (vec->dist_side == 0)
		wall->x_wall = vec->pos.y + wall->ratio * vec->ray.y;
	else
		wall->x_wall = vec->pos.x + wall->ratio * vec->ray.x;
	wall->x_wall -= floor(wall->x_wall);


	if (wall->geo == 'N')
		wall_col(wall, gbl, &gbl->file.texture.north);
	else if (wall->geo == 'E')
		wall_col(wall, gbl, &gbl->file.texture.east);
	else if (wall->geo == 'S')
		wall_col(wall, gbl, &gbl->file.texture.south);
	else
		wall_col(wall, gbl, &gbl->file.texture.west);
}
