/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:13:48 by fleitz            #+#    #+#             */
/*   Updated: 2022/11/14 16:26:35 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	window(t_gbl *gbl)
{
	mlx_hook(gbl->window, KeyPress, KeyPressMask, key_press, gbl);
	mlx_hook(gbl->window, KeyRelease, KeyReleaseMask, key_release, gbl);
	mlx_hook(gbl->window, 17, 0, deal_cross, gbl->mlx);
	mlx_loop_hook(gbl->mlx, loop, gbl);
	mlx_loop(gbl->mlx);
}

static int	create_string(t_image *img)
{
	img->str = (int *)mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->endian);
	if (img->str == NULL)
		return (0);
	return (1);
}

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

int	open_all(t_gbl *gbl)
{
	init_player(gbl);
	gbl->mlx = mlx_init();
	if (gbl->mlx == NULL)
		return (error_return("Error init mlx\n", 0));
	if (open_texture(&gbl->file.texture.north, gbl->mlx) == 0
		|| open_texture(&gbl->file.texture.south, gbl->mlx) == 0
		|| open_texture(&gbl->file.texture.east, gbl->mlx) == 0
		|| open_texture(&gbl->file.texture.west, gbl->mlx) == 0)
		return (error_return("Error opening textures\n", 0));
	gbl->new_img.ptr = mlx_new_image(gbl->mlx, WIDTH_MAX, HEIGHT_MAX);
	gbl->new_img.width = WIDTH_MAX;
	gbl->new_img.height = HEIGHT_MAX;
	if (gbl->new_img.ptr == NULL || create_string(&gbl->new_img) == 0)
		return (error_return("Error creating image\n", 0));
	gbl->window = mlx_new_window(gbl->mlx, WIDTH_MAX, HEIGHT_MAX, "Cub3d");
	if (gbl->window == NULL)
		return (error_return("Error opening window\n", 0));
	window(gbl);
	return (1);
}
