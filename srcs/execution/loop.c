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

void	color_pixel(t_image *img, t_vec2 v, int color) {
	//printf("%d %d\n", img->width, img->height);
	if (v.x >= img->width || v.x < 0 || v.y >= img->height || v.y < 0)
		return ;

	img->str[(int)v.x + (int)v.y * img->size_line / 4] = color;
}

// a simple debug function
// TODO: remove this function
void display_player(t_gbl *gbl) {
	int i = 0;
	t_vec2 tmp_dir = gbl->p_pos;
	t_vec2 tmp_plane = gbl->p_plane;
	while (i < 100) {
		color_pixel(&gbl->new_img, tmp_dir, 0x000000FF);
		color_pixel(&gbl->new_img, tmp_plane + gbl->p_pos + gbl->p_dir * 100, 0x0000FF00);
		color_pixel(&gbl->new_img, -tmp_plane + gbl->p_pos + gbl->p_dir * 100, 0xFF00FF);
		tmp_dir += gbl->p_dir;
		tmp_plane += gbl->p_plane;
		i++;
	}
	color_pixel(&gbl->new_img, gbl->p_pos, 0x00FF0000);
}

int		loop(t_gbl *gbl)
{
	// check if key is pressed
	deal_key(gbl);

	// fill new image with background
	show_background(gbl);

	// raycasting
	get_display_w_vectors(gbl);

	//display_player(gbl);
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->new_img.ptr, 0, 0);
	return (0);
}
