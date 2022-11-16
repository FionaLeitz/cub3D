/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:56:29 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/16 11:05:33 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_gbl *gbl)
{
	gbl->p_pos = gbl->file.start_pos + 0.5;
	if (gbl->file.n == 1)
		gbl->p_dir = (t_vec2){0, -1};
	else if (gbl->file.w == 1)
		gbl->p_dir = (t_vec2){-1, 0};
	else if (gbl->file.e == 1)
		gbl->p_dir = (t_vec2){1, 0};
	else if (gbl->file.s == 1)
		gbl->p_dir = (t_vec2){0, 1};
	if (gbl->file.n || gbl->file.s)
		gbl->p_plane.x = (gbl->p_dir.x * cos(PERP / 2)
				- gbl->p_dir.y * sin(PERP / 2)) * tan(PERP / 2);
	else
		gbl->p_plane.y = - ((gbl->p_dir.y * cos(PERP / 2)
					- gbl->p_dir.x * sin(PERP / 2)) * tan(PERP / 2));
}
