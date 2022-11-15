/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:11 by fleitz            #+#    #+#             */
/*   Updated: 2022/11/14 15:20:52 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	multiply(int a, int b)
{
	return (a * b);
}

void	wall_col(t_wall	*wall, t_gbl *gbl, t_image *img)
{
	int		y_window;
	int		y_tex;
	int		w_s;
	int		color;

	w_s = HEIGHT_MAX / wall->ratio;
	y_window = (HEIGHT_MAX / 2 - w_s / 2) - 1;
	y_tex = -1;
	while (++y_window < ((HEIGHT_MAX / 2) + (w_s / 2)))
	{
		y_tex++;
		if (y_window >= 0 && y_window < HEIGHT_MAX)
		{
			color = img->str[multiply((int)(y_tex * ((double)img->height
							/ (double)w_s)), img->size_line / 4)
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
