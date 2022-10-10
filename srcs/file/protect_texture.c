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

static int	open_texture(t_image *img, void *mlx)
{
	img->ptr = mlx_xpm_file_to_image(mlx, img->texture, &img->width, &img->height);
	if (img->texture == NULL)
		return (0);
	return (1);
}

int	open_all(t_texture *texture, t_gbl *gbl)
{
	gbl->mlx = mlx_init();
	if (gbl->mlx == NULL)
		return (0);
	gbl->window = mlx_new_window(gbl->mlx, 1600, 800, "Cub3d 'isaster");	// 1600 et 800 ? A caser dans le .h ?
	if (gbl->window == NULL)
		return (0);
	if (open_texture(&texture->north, gbl->mlx) == 0
		|| open_texture(&texture->south, gbl->mlx) == 0
		|| open_texture(&texture->east, gbl->mlx) == 0
		|| open_texture(&texture->west, gbl->mlx) == 0)
		return (0);
	gbl->new_img.ptr = mlx_new_image(gbl->mlx, 1600, 800);						// idem
	if (gbl->new_img.ptr == NULL)
		return (0);
	return (1);
}
