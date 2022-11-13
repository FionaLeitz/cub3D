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

void	color_pixel(t_image *img, int x, int y, int color) {
	//printf("%d %d\n", img->width, img->height);
	if (x >= img->width || x < 0 || y >= img->height || y < 0)
		return ;

	img->str[x + y * img->size_line / 4] = color;
}

//mlx_loop_hook(gbl->mlx.mlx_ptr, &loop, gbl);
void display_player(t_gbl *gbl) {
	int i = 0;
	t_vec2 tmp_dir = gbl->p_pos;
	// draw gbl->p_dir from gbl->p_pos
	while (i < 100) {
		color_pixel(&gbl->new_img, tmp_dir.x, tmp_dir.y, 0x000000FF);
		tmp_dir += gbl->p_dir;
		i++;
	}
	color_pixel(&gbl->new_img, gbl->p_pos.x, gbl->p_pos.y, 0x00FF0000);
}

int		loop(t_gbl *gbl)
{
	// check if key is pressed
	deal_key(gbl);

	//printf("%f %f\n", gbl->p_pos.x, gbl->p_pos.y);

	// fill new image with background
	show_background(gbl);

	// raycasting
	//get_display_w_vectors(gbl);

	display_player(gbl);
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->new_img.ptr, 0, 0);
	return (0);
}
