/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:14:26 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/10 18:05:23 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	for now, it's set in a very arbitrary way but the idea is to recover and 
	implement the dist from position to wall
*/
int	get_dist(t_map_lst *map, int *pos)
{
	(void)map;
	return (pos[1] * 10);
}

/*
	all display are launched from here, potentially it's also here we can 
	implement the put_image_to_window function
*/
void	make_things_visible(t_map_lst *map, t_mlx *mlx, t_play *play)
{
		int	i;
		int	x;
		int	dist;
		int	height;

		i = -1;
		(void)play;
		dist = get_dist(map, mlx->p_pos);
	/*
		attention la ligne au dessus et la boucle dessous seront a modif
		en cas de map non carrée !!!
	*/
		while (++i <= ft_strlen(map->map_line))
			display_front_wall(mlx, mlx->p_pos, (i + 1), dist);
/*
	si on approche du mur le 690 augmente (environ + 50 par case ?)
	en fait il faut prevoir un ratio avec la taille de la window
*/
		i = 0;
		x = 261;
		height = dist * 20;
		while (x >= 0)
		{
			display_left_wall(mlx, (height + (5 * i)), x , (90 - (5 * i)));
			i++;
			x -= 10;
		}
		i = 0;
		x = 1340;
		while (x < 1600)
		{
			display_right_wall(mlx, (height + (5 * i)), x, (90 - (5 * i)));
			i++;
			x += 10;
		}
}

t_mlx	start(t_file *file)
{
	t_mlx	mlx;
	t_play	play;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d 'isaster");
	mlx.p_pos = get_player_pos(file->first);
	mlx.play = play;
	make_things_visible(file->first, &mlx, &play);
	return (mlx);
}
