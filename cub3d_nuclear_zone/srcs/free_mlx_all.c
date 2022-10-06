/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:22:35 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/04 16:08:19 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3disaster.h"

void	free_mlx_all(t_gbl *gbl)
{
	mlx_destroy_window(gbl->mlx, gbl->win);
	mlx_destroy_display(gbl->mlx);
	ft_free_tab(gbl->map);
	free(gbl->p_pos);
	free(gbl->mlx);
}
