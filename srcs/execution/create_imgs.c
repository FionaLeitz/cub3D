/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:13:48 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/10 17:13:50 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	window(t_gbl *gbl)
{
	mlx_key_hook(gbl->window, deal_key, gbl);
	mlx_hook(gbl->window, 17, 0, deal_cross, gbl->mlx);
	mlx_loop(gbl->mlx);
}

// create string associated with texture
// to modify image or get correct color for pixel
static int	create_string(t_image *img)
{
	img->str = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->endian);
	if (img->str == NULL)
		return (0);
	return (1);
}

// open texture
static int	open_texture(t_image *img, void *mlx)
{
	img->ptr = mlx_xpm_file_to_image(mlx, img->texture,
			&img->width, &img->height);
	if (img->texture == NULL)
		return (0);
	if (create_string(img) == 0)
		return (0);
	return (1);
}

void	set_up_start(t_gbl *gbl, t_file *file)
{
	gbl->p_pos[0] = file->start_x;
	gbl->p_pos[1] = file->start_y;
//	printf("x = %f	y = %f\n", gbl->p_pos[0], gbl->p_pos[1]);
	if (file->N == 1)
		gbl->direction = 0;
	else if (file->E == 1)
		gbl->direction = 90;
	else if (file->S == 1)
		gbl->direction = 180;
	else if (file->W == 1)
		gbl->direction = 270;
}

// conversion degres vers radian : degres * 3.141592 / 180
// 1 degres = 0.017453

// open every textures and create new image
// open window
int	open_all(t_texture *texture, t_gbl *gbl, t_file *file)
{
	set_up_start(gbl, file);
	gbl->mlx = mlx_init();
	if (gbl->mlx == NULL)
		return (error_return("Error init mlx\n", 0));
	if (open_texture(&texture->north, gbl->mlx) == 0
		|| open_texture(&texture->south, gbl->mlx) == 0
		|| open_texture(&texture->east, gbl->mlx) == 0
		|| open_texture(&texture->west, gbl->mlx) == 0)
		return (error_return("Error opening textures\n", 0));
	gbl->new_img.ptr = mlx_new_image(gbl->mlx, WIDTH_MAX, HEIGHT_MAX);
	if (gbl->new_img.ptr == NULL || create_string(&gbl->new_img) == 0)
		return (error_return("Error creating image\n", 0));
	gbl->window = mlx_new_window(gbl->mlx, WIDTH_MAX, HEIGHT_MAX, "Cub3d'isaster");
	if (gbl->window == NULL)
		return (error_return("Error opening window\n", 0));
	if (show_background(gbl, file) == 0)
		return (0);
	window(gbl);
	return (1);
}
