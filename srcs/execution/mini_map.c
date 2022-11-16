/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:17:38 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/16 12:48:23 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mini_map(t_gbl *gbl);
{
	int	x_mini;
	int	y_mini;
	int	*pix;

	x_mini = WIDTH_MAX - (WIDTH_MAX / 4);
	while (++x_mini < WIDTH_MAX)
	{
		y_mini = HEIGHT_MAX - (HEIGHT_MAX / 5);
		while (++y_mini < HEIGHT_MAX)
		{
			pix = gbl->new_img.str + (y * gbl->new_img.size_line / 4 + x_mini);
			*pix = 
		}
	}
}
