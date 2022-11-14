/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:36:43 by fleitz            #+#    #+#             */
/*   Updated: 2022/11/14 16:27:41 by mcouppe          ###   ########.fr       */
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
	file->start_pos = (t_vec2){-1, -1};
	gbl->rotate_precompute = (t_vec2){cos(ROTATE_SPEED), sin(ROTATE_SPEED)};
}

int	main(int argc, char **argv)
{
	t_gbl	gbl;

	if (argc != 2)
		return (error_return("Error number of arguments\n", 0));
	init(&gbl.file, &gbl);
	if (check_file(argv[1], &gbl.file, &gbl.y_max) == 0)
	{
		end_parse(&gbl.file);
		return (0);
	}
	if (open_all(&gbl) == 0)
	{
		end_mlx(&gbl.file.texture, &gbl, &gbl.file);
		return (0);
	}
	end_mlx(&gbl.file.texture, &gbl, &gbl.file);
	return (1);
}
