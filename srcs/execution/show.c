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

#include "../../cub3d.h"

void	wall_col(t_wall	*wall, t_gbl *gbl, t_image *img)
{
	int		y_window;
	int		y_texture;
	int		wall_size;
	int		color;


	wall_size =  HEIGHT_MAX / wall->ratio;
	y_window = (HEIGHT_MAX / 2 - wall_size / 2) - 1;
	y_texture = -1;
	while (++y_window < ((HEIGHT_MAX / 2) + (wall_size / 2)))
	{
		y_texture++;
		if (y_window >= 0 && y_window < HEIGHT_MAX)
		{
			color = img->str[((int)(y_texture * ((double)img->height / (double)wall_size)) * img->size_line / 4)
					+ (int)(wall->x_wall * (img->width))];

			gbl->new_img.str[(y_window * gbl->new_img.size_line / 4
					+ wall->x_window)] = color;
		}
	}
}

int	show_background(t_gbl *gbl)
{
	int		x;
	int		y;
	int		*pixel;

	x = -1;
	while (++x < WIDTH_MAX)
	{
		y = -1;
		while (++y < HEIGHT_MAX)
		{
			pixel = gbl->new_img.str + (y * gbl->new_img.size_line / 4 + x);
			if (y >= HEIGHT_MAX / 2)
				*pixel = gbl->file.texture.color_f;
			else
				*pixel = gbl->file.texture.color_c;
		}
	}
	return (1);
}














