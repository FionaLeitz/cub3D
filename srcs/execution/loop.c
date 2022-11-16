/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:11 by fleitz            #+#    #+#             */
/*   Updated: 2022/11/16 11:17:32 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_pixel(t_image *img, t_vec2 v, int color)
{
	if (v.x >= img->width || v.x < 0 || v.y >= img->height || v.y < 0)
		return ;
	img->str[(int)v.x + (int)v.y * img->size_line / 4] = color;
}

int	loop(t_gbl *gbl)
{
	deal_key(gbl);
	show_background(gbl);
	get_display_w_vectors(gbl);
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->new_img.ptr, 0, 0);
	mini_map(gbl);
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->new_img.ptr, 0, 0);
	return (0);
}
