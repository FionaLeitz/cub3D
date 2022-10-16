/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:03:06 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/17 01:54:45 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	CALCULER MATRICE DE ROTATION (genre comment avoir les mesures de distances si 
	gbl->vector tombe pas en angle droit sur front wall ?)

	on peut trouver le nouveau vecteur en utilisant la mesure de l'ancien 
	BC (le new_vector) = (sin(90)) * (gbl->vector / sin (180 - (90 + ANGLE_ROT)));
	si ANGLE_ROT on dit c 10 degrés ca donnerait :
	new_vector = sin(90) * (gbl->vector / sin(80));
	et ensuite on a les angles de son FOV  	
	
	pour ca on peut reutiliser get_left_dist mais en fait la variable
	RAD_PERP sera plus celle qu'on utilisera --> on aura besoin de l'angle 
	entre new_vector et le mur  soit le 80 degré soit 180 degre - 80 degre = 100 degré
	
*/
