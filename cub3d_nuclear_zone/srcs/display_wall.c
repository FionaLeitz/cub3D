/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:03:40 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/06 14:49:51 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3disaster.h"

/*
	display of right wall pannel by pannel
*/
void	display_right_wall(t_gbl *gbl, int height, int x, int y)
{
	int	width;
	int	i;

	width = x + 50;
	while (y < height)
	{
		i = x;
		while (i++ < width)
			mlx_pixel_put(gbl->mlx, gbl->win, i, y, 0x8caab22);
		y++;
	}
}

/*
	display of left wall pannel by pannel
*/
void	display_left_wall(t_gbl *gbl, int height, int x, int y)
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
			mlx_pixel_put(gbl->mlx, gbl->win, i, j, 0x8caab22);
		j++;
	}
}

/*
	display of front wall but many variables aren't necessary yet or added to make it work
	but will be implemented directly within the struct (for exemple the width of pannel, the
	height) because they are subject to evolution with the distance between player and wall...
*/
void	display_front_wall(int *pos, t_gbl *gbl, int w_x, int ratio_w)
{
	int	height;
	int	width;
	int	x;
	int	i;
	int	y;
	int	j;

	(void)pos;
/*
	quand on approche du mur le 550 de height augmente
*/
	x = 200 + (w_x * ratio_w);
	y = 250 - (ratio_w + 100);
	height = y + 600;
	width = x + ratio_w;
	i = x;
	j = y;
	//printf("i = %d, j = %d, height = %d\n", i, j, height);
	while (j < height)
	{
		i = x;
		while (i++ < width)
			mlx_pixel_put(gbl->mlx, gbl->win, i, j, 0x7cfc00);
		j++;
	}
//	printf("i = %d, j = %d, height = %d\n", i, j, height);
}

