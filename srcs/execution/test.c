/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:56:29 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/04 13:14:58 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_ray_go(t_gbl *gbl, t_vectors *vec, double x)
{
	vec->view_line = 2 * x / (double)(gbl->new_img.width) - 1;
	vec->ray_x = gbl->p_dir[0] + gbl->p_plane_r[0] * vec->view_line;
	vec->ray_y = gbl->p_dir[1] + gbl->p_plane_r[1] * vec->view_line;
	//ddX = sqrt(1 + (raydirY * raydirY) / (raydirX * raydirX));
	vec->dd_x = abs(1 / vec->ray_x);
	vec->dd_y = abs(1 / vec->ray_y);
	vec->pos_x = gbl->p_pos[0];	
	vec->pos_y = gbl->p_pos[1];	
}

void	ft_test(t_gbl *gbl, char **map)
{
	double		x;
	t_vectors	*vec;

	vec = gbl->vec;
	x = 0;
	gbl->p_plane_r[0] = gbl->p_dir[0] * cos(RAD_PERP / 2) - gbl->p_dir[1] * sin(RAD_PERP / 2);
	// puis integration du ratio de l'angle utilisé par l'angle vers lequel on veut arriver
	gbl->p_plane_r[0] *= tan(RAD_PERP / 2); 
	// attention rot inversée , le y va dans le sens inverse
// en gros le truc suivant : x = point de depart de Vec1  +  point d'arrivee de Vec2
// et w = width (de la window ??? de la map ???)
	while (x < (double)(gbl->new_img.width))
	{
		go_ray_go(gbl, vec, x);
	}
}
