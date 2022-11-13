/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:36:43 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/31 10:53:33 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_img(t_image *img)
{
	img->texture = NULL;
	img->ptr = NULL;
	img->str = NULL;
}

static void	init(t_file *file, t_gbl *gbl)
{
	ft_bzero(file->params, sizeof(char *) * 7);
	ft_bzero(gbl, sizeof(t_gbl));
	init_img(&gbl->new_img);
	ft_bzero(file, sizeof(t_file));
	init_img(&file->texture.north);
	init_img(&file->texture.south);
	init_img(&file->texture.east);
	init_img(&file->texture.west);
	file->start_x = -1;
	file->start_y = -1;
}

int	main(int argc, char **argv)
{
	t_gbl	gbl;

	if (argc != 2)
		return (error_return("Error number of arguments\n", 0));
	init(&gbl.file, &gbl);
	// parsing
	if (check_file(argv[1], &gbl.file, &gbl.y_max) == 0)
	{
		end_parse(&gbl.file);
		return (0);
	}
	// affichage
	if (open_all(&gbl.file.texture, &gbl, &gbl.file) == 0)
	{
		end_mlx(&gbl.file.texture, &gbl, &gbl.file);
		return (0);
	}
	end_mlx(&gbl.file.texture, &gbl, &gbl.file);
	return (1);
}
