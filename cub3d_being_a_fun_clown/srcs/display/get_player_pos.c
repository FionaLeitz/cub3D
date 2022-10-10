/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:28:44 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/10 17:18:00 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*get_player_pos(t_map_lst *map)
{
	int	i;
	int	j;
	int	*tab;

	i = -1;
	tab = malloc(sizeof(int) * 2);
	if (!tab)
		return (NULL);
	while (map != NULL)
	{
		j = -1;
		while (map->map_line[++j])
		{
			if (map->map_line[j] == 'N')
			{
				i++;
				tab[0] = j;
				tab[1] = i;
				return (tab);
			}
		}
		i++;
		map = map->next;
	}
	return (0);
}
