/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:37:15 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/06 10:37:18 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
/*
static void	free_table(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
*/

// destroy mlx images
static void	end_img(t_image *img, void *mlx)
{
	if (img->ptr != NULL)
		mlx_destroy_image(mlx, img->ptr);
}

// free list structure t_map_lst
void	free_struct(t_map_lst *first)
{
	t_map_lst	*tmp;

	while (first != NULL)
	{
		tmp = first;
		free(tmp->map_line);
		first = first->next;
		free(tmp);
	}
}

// free all parse
void	end_parse(t_file *file)
{
	int	count;

	free_struct(file->first);
	count = -1;
	while (file->params[++count])
		free(file->params[count]);
	free(file->map);
}

// free every mlx associated pointers
void	end_mlx(t_texture *texture, t_gbl *gbl, t_file *file)
{
	end_img(&texture->north, gbl->mlx);
	end_img(&texture->south, gbl->mlx);
	end_img(&texture->east, gbl->mlx);
	end_img(&texture->west, gbl->mlx);
	end_img(&gbl->new_img, gbl->mlx);
	if (gbl->window != NULL)
		mlx_destroy_window(gbl->mlx, gbl->window);
	if (gbl->mlx != NULL)
		mlx_destroy_display(gbl->mlx);
	free(gbl->mlx);
	end_parse(file);
}
