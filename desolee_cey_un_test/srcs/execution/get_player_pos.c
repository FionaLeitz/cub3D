/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:28:44 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/11 22:06:50 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_player_pos(t_map_lst *map, t_gbl *gbl)
{
	int	i;
	int	j;

	i = -1;
/*	gbl->p_pos = malloc(sizeof(int) * 2);
	if (!gbl->p_pos)
	return (NULL);*/
	while (map != NULL)
	{
		j = -1;
		while (map->map_line[++j])
		{
			if (map->map_line[j] == 'N')
			{
				i++;
				gbl->p_pos[0] = (double)j;
				gbl->p_pos[1] = (double)i;
			//	printf("pos = %d\n",i);
				return ;
			}
		}
		i++;
		map = map->next;
	}
//	return (0);
}
