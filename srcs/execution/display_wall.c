/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:40:00 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/12 13:27:22 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	display_wall(t_gbl *gbl)
{
	double	rad;
	double	i;
	double	incr;

	get_player_pos(gbl->file.first, gbl);					// ne modifie pas la position ?
	gbl->vector = get_vector(gbl->file.map, gbl->p_pos);
	rad = RAD_FOV;
	incr = 0;
/******************************************************************************/
/**************		LE MUR LE PLUS PROCHE SUR LA GAUCHE		*******************/
/******************************************************************************/
//	printf("before get_left_dist : x = %f	y = %f\n", gbl->p_pos[0], gbl->p_pos[1]);
	i = get_left_dist(gbl->vector, gbl->p_pos, gbl->file.map, rad, incr);
	printf("left dist = %f\nx = %f	y = %f\n", i, gbl->p_pos[0], gbl->p_pos[1]);
	while (rad > 0 && (i == 0))
	{
		printf("lol i = %f et rad = %f\n", i, rad);
		rad -= DECR_RAD;
		incr++;
		i = get_left_dist(gbl->vector, gbl->p_pos, gbl->file.map, rad, incr);
	}
	if (i == 0)
		printf("bah fuck\n");
	else
		printf("oui bon i = %f\n", i);
}
