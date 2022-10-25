/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:11 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/24 13:41:00 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	wall_col(t_wall	wall, t_gbl *gbl, t_image *img)
{
	int		y_window;
	int		y_texture;
	double	wall_size;
	char	*pixel;
	char	*pixel2;
	int		color;

//	ratio = gbl->vector * 0.1;
	wall_size = img->width / wall.ratio;
	printf("**************WALL SIZE ***********\n\twall size = %f\n", wall_size);
	y_window = (HEIGHT_MAX / 2 - wall_size / 2) - 1;
	y_texture = -1;
	while (++y_window <= ((HEIGHT_MAX / 2) + (wall_size / 2)))
	{
		y_texture++;
		if (y_window >= 0 && y_window <= HEIGHT_MAX)
		{
			pixel = img->str + ((int)(y_texture * wall.ratio) * img->size_line
					+ (int)(wall.x_wall * wall.ratio) * (img->bpp / 8));
			color = *(int *)pixel;
			pixel2 = gbl->new_img.str + (y_window * gbl->new_img.size_line
					+ wall.x_window * (gbl->new_img.bpp / 8));
			*(int *)pixel2 = color;
		}
	}
}

// fill new image with background
// mlx loop
int	show_background(t_gbl *gbl)
{
	int		x;
	int		y;
	char	*pixel;

	deal_key(gbl);
	x = -1;
	while (++x < WIDTH_MAX)
	{
		y = -1;
		while (++y < HEIGHT_MAX)
		{
			pixel = gbl->new_img.str + (y * gbl->new_img.size_line + x
					* (gbl->new_img.bpp / 8));
			if (y >= HEIGHT_MAX / 2)
				*(int *)pixel = gbl->file.texture.color_f;
			else
				*(int *)pixel = gbl->file.texture.color_c;
		}
	}
	display_wall(gbl);
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->new_img.ptr, 0, 0);
	mini_map(gbl->file.map, gbl->p_pos, gbl);
	return (1);
}

