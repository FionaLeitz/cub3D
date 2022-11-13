/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:11 by fleitz            #+#    #+#             */
/*   Updated: 2022/11/13 14:00:24 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//mlx_loop_hook(gbl->mlx.mlx_ptr, &loop, gbl);

int		loop(t_gbl *gbl)
{
	// check if key is pressed
	deal_key(gbl);

	printf("%f %f\n", gbl->p_pos.x, gbl->p_pos.y);

	// fill new image with background
	show_background(gbl);

	// raycasting
	get_display_w_vectors(gbl);
	return (0);
}
