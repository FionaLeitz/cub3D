/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:40:00 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/11 22:08:39 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	display_wall(t_gbl *gbl)
{
	double	rad;
	double	i;

	get_player_pos(gbl->file.first, gbl);
	gbl->vector = get_vector(gbl->file.map, gbl->p_pos);
	rad = RAD_FOV;
/******************************************************************************/
/**************		LE MUR LE PLUS PROCHE SUR LA GAUCHE		*******************/
/******************************************************************************/
	i = get_left_dist(gbl->vector, gbl->p_pos, gbl->file.map, rad);
	printf("i = %f\n", i);
	while (rad > 0  && (i != 0))
	{
		printf("lol i = %f et rad = %f\n", i, rad);
		rad -= DECR_RAD;
		i = get_left_dist(gbl->vector, gbl->p_pos, gbl->file.map, rad);
	}
	if (i == 0)
		printf("bah fuck\n");
}
