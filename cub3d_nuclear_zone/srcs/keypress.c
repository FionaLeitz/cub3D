/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:16:36 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/04 15:21:18 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3disaster.h"

int	keypress(int keycode, t_gbl *gbl)
{
	if (keycode == 65307)
	{
		free_mlx_all(gbl);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int close_btn(t_gbl *gbl)
{
	free_mlx_all(gbl);
	exit(EXIT_SUCCESS);
	return (0);
}
