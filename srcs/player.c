/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:56:29 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/13 14:33:35 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_player(t_gbl *gbl) {
	gbl->p_pos = gbl->file.start_pos;
	if (gbl->file.N == 1)
		gbl->p_dir = (t_vec2){0, 1};
	else if (gbl->file.E == 1)
		gbl->p_dir = (t_vec2){1, 0};
	else if (gbl->file.W == 1)
		gbl->p_dir = (t_vec2){-1, 0};
	else if (gbl->file.S == 1)
		gbl->p_dir = (t_vec2){0, -1};

	// Init plane
	gbl->p_plane[0] = gbl->p_dir[0] * cos(RAD_PERP / 2) - gbl->p_dir[1] * sin(RAD_PERP / 2);
	// puis integration du ratio de l'angle utilisé par l'angle vers lequel on veut arriver
	gbl->p_plane[0] *= tan(RAD_PERP / 2);
}