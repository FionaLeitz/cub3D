/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:11 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/24 10:48:56 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	wall_col(t_wall	wall, t_gbl *gbl)
{
	int	y_window;
	int	y_texture;
	double	wall_size;
//	double	ratio;

	char	*pixel;
	char	*pixel2;
	int		color;

//	ratio = gbl->vector * 0.1;
	wall_size = gbl->file.texture.north.width / wall.ratio;
//	printf("wall_size after = %f\n", wall_size);
	y_window = (HEIGHT_MAX / 2 - wall_size / 2) - 1;
	y_texture = -1;
	while (++y_window < ((HEIGHT_MAX / 2) + (wall_size / 2)))
	{
		y_texture++;
		if (y_window > 0)
		{
			pixel = gbl->file.texture.north.str + ((int)(y_texture * wall.ratio) * gbl->file.texture.north.size_line + (int)(wall.x_wall * wall.ratio) * (gbl->file.texture.north.bpp / 8));
			color = *(int *)pixel;
			pixel2 = gbl->new_img.str + (y_window * gbl->new_img.size_line + wall.x_window * (gbl->new_img.bpp / 8));
			*(int *)pixel2 = color;
		}
	}
}

void	wall_front(t_gbl *gbl)
{
	t_wall wall;

//	printf("wall_size before = %f\n", 64 / (gbl->vector * 0.1));
	wall.x_window = 0;
	wall.x_wall = 30;
	while (++wall.x_wall < (gbl->file.texture.north.width / (gbl->vector * 0.1)))
	{
		wall.x_window++;
		wall_col(wall, gbl);
	}
	return ;

	int	x_img_first;			// a gauche du mur
	int	y_img_first;			// en haut du mur
	int	x_img_last;				// a droite du mur
	int	y_img_last;				// en bas du mur
	int	x_count = -1;			// x sur la texture
	int	y_count;				// y sur la texture
	char	*pixel;				// emplacement du pixel qu'on veut dans la textur
	char	*pixel2;			// emplacement du prochain pixel a poser dans la nouvelle image
	int	color;					// save de la couleur du pixel de texture
	double ratio = (gbl->vector/* * 0.1*/);

	//double	wall_size = gbl->file.texture.north.width / ratio;
	// printf("wall size = %f\n", wall_size);

	x_img_first = ((WIDTH_MAX / 2) - (gbl->file.texture.north.width / 2) / ratio) - 1;
	x_img_last = (int)((WIDTH_MAX / 2) + (gbl->file.texture.north.width / 2) / ratio);
	// x_img_first = ((WIDTH_MAX / 2) - (wall_size / 2)) - 1;
	// x_img_last = (int)((WIDTH_MAX / 2) + (wall_size / 2));
	while (++x_img_first < x_img_last)
	{
		// y_img_first = ((HEIGHT_MAX / 2) - (wall_size / 2)) - 1;
		// y_img_last = ((HEIGHT_MAX / 2) + (wall_size / 2));
		y_img_first = ((HEIGHT_MAX / 2) - (gbl->file.texture.north.height / 2) / ratio) - 1;
		y_img_last = (int)((HEIGHT_MAX / 2) + (gbl->file.texture.north.height / 2) / ratio);
		y_count = -1;
		x_count++;
		while (++y_img_first < y_img_last)
		{
			++y_count;
			if (y_img_first > 0)
			{
				pixel = gbl->file.texture.north.str + ((int)(y_count * ratio) * gbl->file.texture.north.size_line + (int)(x_count * ratio) * (gbl->file.texture.north.bpp / 8));
				color = *(int *)pixel;
				// if (color != 812580)
				// 	printf("before segfault color is %d\n", color);
				//printf("x = %d, y = %d\n", x_img_first, y_img_first);
				pixel2 = gbl->new_img.str + (y_img_first * gbl->new_img.size_line + x_img_first * (gbl->new_img.bpp / 8));
				//printf("adresse pixel2[0] %c\n", pixel2[0]);
				*(int *)pixel2 = color;
			}
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
	// affichage
	display_wall(gbl);
	wall_front(gbl);
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->new_img.ptr, 0, 0);
	return (1);
}
