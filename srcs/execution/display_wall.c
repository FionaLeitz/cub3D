/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:40:00 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/14 18:02:57 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	display_wall(t_gbl *gbl)
{
	double	rad;
	double	i;
	double	get_vector;
	double	incr;

	get_vector = get_int_vector_north(gbl->file.map, gbl->p_pos);
	gbl->vector = get_real_vector_north(gbl->p_pos, get_vector);
	rad = RAD_FOV;
	incr = 1;
/******************************************************************************/
/**************		LE MUR LE PLUS PROCHE SUR LA GAUCHE		*******************/
/******************************************************************************/
//	printf("before get_left_dist : x = %f	y = %f\n", gbl->p_pos[0], gbl->p_pos[1]);
	i = get_left_dist(gbl->vector, gbl->p_pos, gbl->file.map, rad, incr);
	gbl->left_fov_dist = i;
	printf("i ? %f\n", i);
	
//	printf("left dist = %f\nx = %f	y = %f\n", i, gbl->p_pos[0], gbl->p_pos[1]);
/*
	while (rad > 0 && i != 0)
	{
	//	printf("lol i = %f et rad = %f\n", i, rad);
		rad -= DECR_RAD;
		incr++;
		i = get_left_dist(gbl->vector, gbl->p_pos, gbl->file.map, rad, incr);
		printf("i ? %f\n", i);
		//if (i != 0)
			// on a un mur a distance i 
	}
*/
/*	if (i == 0)
		printf("bah fuck\n");
	else
		printf("oui bon i = %f\n", i);*/
/*
	affichage des murs : concevoir les 1 comme des cubes avec 4 faces

	-->>	111111111
			10000000
			10000000
		donnerait  en gros :
			□ □ □ □ □ □
			□
			□
		avec la partie  _  --> texture SOUTH
			 la partie   | --> texture EAST
			 la partie |   --> texture WEST
			 la partie  ﹉ --> texture NORTH
		
		du coup il faut que chaque 1 ait une taille définie à laquelle on applique la proportionnalité 
		déterminée par le calcul par la distance (le fameux i juste au dessus) + le gbl->vector (la dist au mur en face)
		pour l'instant c'est ok pour quand on regarde le nord mais pour le reste il faut reflechir a koman calculer 
		position tt ca la 
*/

}
