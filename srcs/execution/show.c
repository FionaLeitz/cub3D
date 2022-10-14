/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:11 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/12 14:06:51 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	wall_front(t_gbl *gbl)
{
	int	x_img_first;			// a gauche du mur
	int	y_img_first;			// en haut du mur
	int	x_img_last;				// a droite du mur
	int	y_img_last;				// en bas du mur
	int	x_count = -1;			// x sur la texture
	int	y_count = -1;			// y sur la texture
	char	*pixel;				// emplacement du pixel qu'on veut dans la textur
	char	*pixel2;			// emplacement du prochain pixel a poser dans la nouvelle image
	int	color;					// save de la couleur du pixel de texture
	double ratio = gbl->vector / 2;

	x_img_first = ((WIDTH_MAX / 2) - (gbl->file.texture.north.width / 2) / (ratio)) - 1;
	x_img_last = (int)((WIDTH_MAX / 2) + (gbl->file.texture.north.width / 2) / ratio);
	while (++x_img_first < x_img_last)
	{
		y_img_first = ((HEIGHT_MAX / 2) - (gbl->file.texture.north.height / 2) / ratio) - 1;
		y_img_last = (int)((HEIGHT_MAX / 2) + (gbl->file.texture.north.height / 2) / ratio);
		y_count = -1;
		x_count++;
		while (++y_img_first < y_img_last)
		{
			pixel = gbl->file.texture.north.str + ((int)(++y_count * ratio) * gbl->file.texture.north.size_line + (int)(x_count * ratio) * (gbl->file.texture.north.bpp / 8));
			color = *(int *)pixel;
			pixel2 = gbl->new_img.str + (y_img_first * gbl->new_img.size_line + x_img_first * (gbl->new_img.bpp / 8));
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
	// affichage
	display_wall(gbl);
	wall_front(gbl);
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->new_img.ptr, 0, 0);
	return (1);
}
