/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:01 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/19 11:08:37 by mcouppe          ###   ########.fr       */
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
int	key_press(int key, t_gbl *gbl)
{
	if (key == 65307)
		mlx_loop_end(gbl->mlx);
	else if (key == 119)
		gbl->keys.front = 1;
	else if (key == 115)
		gbl->keys.back = 1;
	else if (key == 97)
		gbl->keys.left = 1;
	else if (key == 65361)
		gbl->keys.rot_left = 1;
	else if (key == 100)
		gbl->keys.right = 1;
	else if (key == 65363)
		gbl->keys.rot_right = 1;
	return (0);
}

int	deal_key(t_gbl *gbl)
{
	if (gbl->keys.front == 1)
		gbl->p_pos += gbl->p_dir * SPEED;
	else if (gbl->keys.back == 1)
		gbl->p_pos -= gbl->p_dir * SPEED;
	if (gbl->keys.left == 1)
		gbl->p_pos += gbl->p_dir.yx * (t_vec2){-1, 1} * SPEED;
	else if (gbl->keys.right == 1)
		gbl->p_pos += gbl->p_dir.yx * (t_vec2){1, -1} * SPEED;
	if (gbl->keys.rot_left == 1) {
		t_vec2 old_dir = gbl->p_dir;
		gbl->p_dir.x = gbl->p_dir.x * gbl->rotate_precompute.x - gbl->p_dir.y * gbl->rotate_precompute.y;
		gbl->p_dir.y = old_dir.x * gbl->rotate_precompute.y + gbl->p_dir.y * gbl->rotate_precompute.x;
	}
	if (gbl->keys.rot_right == 1) {
		t_vec2 old_dir = gbl->p_dir;
		gbl->p_dir.x = gbl->p_dir.x * gbl->rotate_precompute.x - gbl->p_dir.y * -gbl->rotate_precompute.y;
		gbl->p_dir.y = old_dir.x * -gbl->rotate_precompute.y + gbl->p_dir.y * gbl->rotate_precompute.x;
	}
	return (0);
}

int	key_release(int key, t_gbl *gbl)
{
	if (key == 119)
		gbl->keys.front = 0;
	else if (key == 115)
		gbl->keys.back = 0;
	else if (key == 97)
		gbl->keys.left = 0;
	else if (key == 100)
		gbl->keys.right = 0;
	else if (key == 65361)
		gbl->keys.rot_left = 0;
	else if (key == 65363)
		gbl->keys.rot_right = 0;
	return (0);
}

// quit with cross
int	deal_cross(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}
