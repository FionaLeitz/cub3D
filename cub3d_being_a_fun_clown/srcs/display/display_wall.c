/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:03:40 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/11 11:30:45 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	display of right wall pannel by pannel
*/
void	display_right_wall(t_mlx *mlx, int height, int x, int y)
{
	int	width;
	int	i;

	width = x + 50;
	while (y < height)
	{
		i = x;
		while (i++ < width)
			mlx_pixel_put(mlx->mlx, mlx->win, i, y, 0x8caab22);
		y++;
	}
}

/*
	display of left wall pannel by pannel
*/
void	display_left_wall(t_mlx *mlx, int height, int x, int y)
{
	int	i;
	int	j;
	int	width;

	width = x - 50;
	i = x;
	j = y;
	while (j < height)
	{
		i = x;
		while (i-- > width)
			mlx_pixel_put(mlx->mlx, mlx->win, i, j, 0x8caab22);
		j++;
	}
}

/*
	display of front wall but many variables aren't necessary yet or added to make it work
	but will be implemented directly within the struct (for exemple the width of pannel, the
	height) because they are subject to evolution with the distance between player and wall...
*/
void	display_front_wall(t_mlx *mlx, int *pos, int w_x, int dist)
{
	int	height;
	int	width;
	int	x;
	int	i;
	int	y;
	int	j;

/*
	quand on approche du mur le 550 de height augmente
*/
	x = 200 + (w_x * dist);
	y = (dist * pos[1]);
	height = ((WIN_HEIGHT / pos[1]) + (WIN_HEIGHT / pos[1]) + (dist * pos[1]));
	width = x + dist;
	printf("x = %d y = %d, ratio_w = %d, w_x = %d\n", x, y, dist, w_x);
	i = x;
	j = y;
	printf("i = %d, j = %d, height = %d\n", i, j, height);
	while (j < height)
	{
		i = x;
		while (i++ < width)
			mlx_pixel_put(mlx->mlx, mlx->win, i, j, 0x7cfc00);
		j++;
	}
//	printf("i = %d, j = %d, height = %d\n", i, j, height);
}

