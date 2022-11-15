/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:21:31 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/15 15:43:06 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left_right(t_gbl *gbl)
{
	if (gbl->keys.left == 1)
	{
		gbl->p_pos -= gbl->p_dir.yx * (t_vec2){-1, 1} * SPEED;
		if (wall_collision_checker(gbl))
		{
			gbl->p_pos += gbl->p_dir.yx * (t_vec2){-1, 1} * SPEED;
			gbl->p_pos += gbl->p_dir.yx * (t_vec2){-1, 1} * SPEED;
		}
	}
	else if (gbl->keys.right == 1)
	{
		gbl->p_pos -= gbl->p_dir.yx * (t_vec2){1, -1} * SPEED;
		if (wall_collision_checker(gbl))
		{
			gbl->p_pos += gbl->p_dir.yx * (t_vec2){1, -1} * SPEED;
			gbl->p_pos += gbl->p_dir.yx * (t_vec2){1, -1} * SPEED;
		}
	}
}

void	move_front_back(t_gbl *gbl)
{
	if (gbl->keys.front == 1)
	{
		gbl->p_pos += gbl->p_dir * SPEED;
		if (wall_collision_checker(gbl))
		{
			gbl->p_pos -= gbl->p_dir * SPEED;
			gbl->p_pos -= gbl->p_dir * SPEED;
		}
	}
	else if (gbl->keys.back == 1)
	{
		gbl->p_pos -= gbl->p_dir * SPEED;
		if (wall_collision_checker(gbl))
		{
			gbl->p_pos += gbl->p_dir * SPEED;
			gbl->p_pos += gbl->p_dir * SPEED;
		}
	}
}
