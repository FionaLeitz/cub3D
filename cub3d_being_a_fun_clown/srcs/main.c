/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:36:43 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/10 14:59:14 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_file *file)
{
	ft_bzero(file->params, sizeof(char *) * 7);
	file->map = NULL;
	file->first = NULL;
	file->texture.north = NULL;
	file->texture.south = NULL;
	file->texture.east = NULL;
	file->texture.west = NULL;
	file->texture.f = NULL;
	file->texture.c = NULL;
	file->start_x = -1;
	file->start_y = -1;
	file->N = 0;
	file->S = 0;
	file->E = 0;
	file->W = 0;
}

int	main(int argc, char **argv)
{
	t_file		file;
	t_mlx		mlx;

	if (argc != 2)
	{
		ft_printf("Error number of arguments\n");
		return (0);
	}
	init(&file);
	if (check_file(argv[1], &file) == 0)
		return (end_parse(&file, 0));
	else
	{
		mlx = start(&file);
		mlx_hook(mlx.win, 2, 1L << 0, keypress, &mlx);
		mlx_hook(mlx.win, 33, 1L << 2, close_btn, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (end_parse(&file, 1));
}