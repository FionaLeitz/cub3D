/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:01 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/11 13:46:06 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// sin(0) = 0
// sin(90) = 1
// sin(180) = 0
// sin(270) = -1
// sin(360) = 0
// cos(0) = 1
// cos(90) = 0
// cos(180) = -1
// cos(270) = 0
// cos(360) = 1

// get key value and quit with escape
int	deal_key(int key, t_gbl *gbl)
{
	if (key == 119 || key == 65362)
	{
		gbl->p_pos[0] += sin(gbl->direction * 3.141592 / 180);				// manque la "vitesse"
		gbl->p_pos[1] += cos(gbl->direction * 3.141592 / 180);				// manque la "vitesse"
		ft_printf("haut\n");
	}
	else if (key == 115 || key == 65364)
	{
		gbl->p_pos[0] -= sin(gbl->direction * 3.141592 / 180);				// manque la "vitesse"
		gbl->p_pos[1] -= cos(gbl->direction * 3.141592 / 180);				// manque la "vitesse"
		ft_printf("bas\n");
	}
	else if (key == 97 || key == 65361)
	{
		if (gbl->direction == 0)
			gbl->direction = 360;
		gbl->direction -= 5;						// de 5 degre en 5 degre ?
		ft_printf("gauche\ndirection %d degres\n", gbl->direction);
	}
	else if (key == 100 || key == 65363)
	{
		gbl->direction += 5;						// de 5 degre en 5 degre ?
		if (gbl->direction == 360)
			gbl->direction = 0;
		ft_printf("droite\ndirection %d degres\n", gbl->direction);
	}
	else if (key == 65307)
		mlx_loop_end(gbl->mlx);
	printf("x = %f	y = %f\n", gbl->p_pos[0], gbl->p_pos[1]);
	return (0);
}

// quit with cross
int	deal_cross(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}
