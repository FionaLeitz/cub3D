/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:56:29 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/14 16:27:19 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_gbl *gbl)
{
	gbl->p_pos = gbl->file.start_pos + 0.5;
	if (gbl->file.N == 1)
		gbl->p_dir = (t_vec2){0, -1};
	else if (gbl->file.W == 1)
		gbl->p_dir = (t_vec2){1, 0};
	else if (gbl->file.E == 1)
		gbl->p_dir = (t_vec2){-1, 0};
	else if (gbl->file.S == 1)
		gbl->p_dir = (t_vec2){0, 1};
	gbl->p_plane.x = gbl->p_dir.x * cos(RAD_PERP / 2)
		- gbl->p_dir.y * sin(RAD_PERP / 2);
	gbl->p_plane.x *= tan(RAD_PERP / 2);
}
