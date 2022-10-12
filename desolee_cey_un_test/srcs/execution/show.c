/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:11 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/11 20:37:28 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// fill new image with background
// mlx loop
int	show_background(t_gbl *gbl)
{
	int		x;
	int		y;
	char	*pixel;

	deal_key(gbl);
	y = -1;
	while (++y < HEIGHT_MAX)
	{
		x = -1;
		while (++x < WIDTH_MAX)
		{
			pixel = gbl->new_img.str + (y * gbl->new_img.size_line + x
					* (gbl->new_img.bpp / 8));
			if (y >= HEIGHT_MAX / 2)
				*(int *)pixel = gbl->file.texture.color_f;
			else
				*(int *)pixel = gbl->file.texture.color_c;
		}
	}
	// affichage
//	printf("in show_background : x = %f	y = %f\n", gbl->p_pos[0], gbl->p_pos[1]);
	display_wall(gbl);
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->new_img.ptr, 0, 0);
	return (1);
}
