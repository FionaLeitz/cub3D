/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:16:36 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/10 14:57:50 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		free_mlx_all(mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int close_btn(t_mlx *mlx)
{
	free_mlx_all(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
