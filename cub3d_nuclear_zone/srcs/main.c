/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:45:28 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/04 15:36:23 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3disaster.h"

int	main(int ac, char **av)
{
	t_gbl	gbl;

	if (ac == 2)
	{
		gbl = start(av[1]);
		mlx_hook(gbl.win, 2, 1L << 0, keypress, &gbl);
		mlx_hook(gbl.win, 33, 1L << 2, close_btn, &gbl);
		mlx_loop(gbl.mlx);
	}
	return (0);
}
