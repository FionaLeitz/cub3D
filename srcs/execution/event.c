/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:01 by fleitz            #+#    #+#             */
/*   Updated: 2022/11/15 12:14:33 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_vec2	rotate_vector(t_vec2 v, char d, t_gbl *gbl)
{
	return ((t_vec2){
		v.x * gbl->rotate_precompute.x - d * v.y * gbl->rotate_precompute.y,
		d * v.x * gbl->rotate_precompute.y + v.y * gbl->rotate_precompute.x});
	return (v);
}

int	key_press(int key, t_gbl *gbl)
{
	if (key == 65307)
		mlx_loop_end(gbl->mlx);
	else if (key == 'w')
		gbl->keys.front = 1;
	else if (key == 's')
		gbl->keys.back = 1;
	else if (key == 'a')
		gbl->keys.left = 1;
	else if (key == 'd')
		gbl->keys.right = 1;
	else if (key == 65361 || key == 'q')
		gbl->keys.rot_left = 1;
	else if (key == 65363 || key == 'e')
		gbl->keys.rot_right = 1;
	return (0);
}

int	deal_key(t_gbl *gbl)
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
	if (gbl->keys.rot_left == 1)
	{
		gbl->p_dir = rotate_vector(gbl->p_dir, -1, gbl);
		gbl->p_plane = rotate_vector(gbl->p_plane, -1, gbl);
	}
	if (gbl->keys.rot_right == 1)
	{
		gbl->p_dir = rotate_vector(gbl->p_dir, 1, gbl);
		gbl->p_plane = rotate_vector(gbl->p_plane, 1, gbl);
	}
	return (0);
}

int	key_release(int key, t_gbl *gbl)
{
	if (key == 'w')
		gbl->keys.front = 0;
	else if (key == 's')
		gbl->keys.back = 0;
	else if (key == 'a')
		gbl->keys.left = 0;
	else if (key == 'd')
		gbl->keys.right = 0;
	else if (key == 65361 || key == 'q')
		gbl->keys.rot_left = 0;
	else if (key == 65363 || key == 'e')
		gbl->keys.rot_right = 0;
	return (0);
}

// quit with cross
int	deal_cross(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}
