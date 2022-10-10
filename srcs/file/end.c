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

void	end_img(t_image *img, void *mlx)
{
	free(img->str);
	if (img->ptr != NULL)
		mlx_destroy_image(mlx, img->ptr);
}

void	end_mlx(t_texture *texture, t_gbl *gbl)
{
	end_img(&texture->north, gbl->mlx);
	end_img(&texture->south, gbl->mlx);
	end_img(&texture->east, gbl->mlx);
	end_img(&texture->west, gbl->mlx);
	if (gbl->window != NULL)
		mlx_destroy_window(gbl->mlx, gbl->window);
	if (gbl->mlx != NULL)
		mlx_destroy_display(gbl->mlx);
	free(gbl->mlx);
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
int	end_parse(t_file *file, int ret)
{
	int	count;

	free_struct(file->first);
	count = -1;
	while (file->params[++count])
		free(file->params[count]);
	free(file->map);
	return (ret);
}
