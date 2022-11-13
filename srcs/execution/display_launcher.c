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

void	display_wall_launcher(t_wall wall, t_gbl *gbl, t_vectors *vec)
{
	wall.x_window = -1;
	wall.ratio = vec->res_dda;
//	wall.ratio = vec->res_dda * 0.1;
	if (wall.geo == 'N')
		wall_col(wall, gbl, &gbl->file.texture.north);
	else if (wall.geo == 'E')
		wall_col(wall, gbl, &gbl->file.texture.east);
	else if (wall.geo == 'S')
		wall_col(wall, gbl, &gbl->file.texture.south);
	else
		wall_col(wall, gbl, &gbl->file.texture.west);
}
