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

void	wall_col(t_wall	wall, t_gbl *gbl, t_image *img)
{
	int		y_window;
	int		y_texture;
	double	wall_size;
	int		*pixel;
	int		*pixel2;
	int		color;

	wall_size = img->width / wall.ratio;
	y_window = (HEIGHT_MAX / 2 - wall_size / 2) - 1;
	y_texture = -1;
	while (++y_window <= ((HEIGHT_MAX / 2) + (wall_size / 2)))
	{
		y_texture++;
		if (y_window >= 0 && y_window <= HEIGHT_MAX)
		{
			pixel = img->str + ((int)(y_texture * wall.ratio) * img->size_line / 4
					+ (int)(wall.x_wall * wall.ratio));
			color = *pixel;
			pixel2 = gbl->new_img.str + (y_window * gbl->new_img.size_line / 4
					+ wall.x_window);
			*pixel2 = color;
		}
	}
}

void	wall_front(t_gbl *gbl)
{
	(void)gbl;
//	t_wall	wall;
//
//	wall.x_window = -1;
//	double	vector = 3;
//	wall.ratio = vector * 0.1;				// pour gerer differentes tailles de textures, changer le 0.1
//	wall.x_wall = -1;
//	while (++wall.x_wall <= (gbl->file.texture.west.width / (wall.ratio)) && ++wall.x_window < WIDTH_MAX)
//	{
//		vector += 0.015;
//		wall.ratio = vector * 0.1;			// pour gerer differentes tailles de textures, changer le 0.1
//		printf("*************************\nvector = %f\n wall.ratio = %f\n", vector, wall.ratio);
//		wall_col(wall, gbl, &gbl->file.texture.west);
//	}
//	return ;
}

// fill new image with background
// mlx loop
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
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->new_img.ptr, 0, 0);
	return (1);
}

//	mini_map(gbl->file.map, gbl->p_pos, gbl->new_img);
