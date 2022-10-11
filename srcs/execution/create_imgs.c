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

static int	create_string(t_image *img)
{
	img->str = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, &img->endian);
	if (img->str == NULL)
		return (0);
	return (1);
}

static int	open_texture(t_image *img, void *mlx)
{
	img->ptr = mlx_xpm_file_to_image(mlx, img->texture, &img->width, &img->height);
	if (img->texture == NULL)
		return (0);
	if (create_string(img) == 0)
		return (0);
	return (1);
}

int	open_all(t_texture *texture, t_gbl *gbl, t_file *file)
{
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
	gbl->window = mlx_new_window(gbl->mlx, WIDTH_MAX, HEIGHT_MAX, "Cub3d 'isaster");
	if (gbl->window == NULL)
		return (error_return("Error opening window\n", 0));
	if (show(gbl, file) == 0)
		return (0);
	return (1);
}
