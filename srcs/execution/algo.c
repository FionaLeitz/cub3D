/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:31:33 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/26 16:16:16 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_v_pos(t_gbl *gbl)
{
	t_map_lst	*map;
	double	y;

	y = 0;
	map = gbl->file.first;
	if (gbl->v_pos[0] >= 0  && gbl->v_pos[1] >= 0)
	{
		while (map)
		{
			if (round(gbl->v_pos[0]) <= map->string_size
					&& map->map_line[round(gbl->v_pos[0])]
					&& map->map_line[round(gbl->v_pos[0])] == '1' )
				return (1);
			map = map->next;
	}
	return (0);
}

void	start_pos_to_check(t_gbl *gbl, char **map, double incr)
{
	if (map[round(p_pos[1])][round(p_pos[0])] == 'N')
	{
		gbl->v_pos[0] = gbl->p_pos[0];
		gbl->v_pos[1] = gbl->p_pos[1] - incr;
	}
	else if (map[round(p_pos[1])][round(p_pos[0])] == 'E')
	{
		gbl->v_pos[0] = gbl->p_pos[0] + incr;
		gbl->v_pos[1] = gbl->p_pos[1];
	}
	else if (map[round(p_pos[1])][round(p_pos[0])] == 'S')
	{
		gbl->v_pos[0] = gbl->p_pos[0];
		gbl->v_pos[1] = gbl->p_pos[1] + incr;
	}
	else if (map[round(p_pos[1])][round(p_pos[0])] == 'W')
	{
		gbl->v_pos[0] = gbl->p_pos[0] - incr;
		gbl->v_pos[1] = gbl->p_pos[1];
	}
}

double	display_wall(t_gbl *gbl, char **map)
{
	double	i;

	i = -1;
	while (++i && check_v_pos(gbl, map) == 0)
		start_pos_to_check(gbl, map, i);
	
}
