/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:28:44 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/04 14:35:34 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3disaster.h"

int	*get_player_pos(char **map)
{
	int	i;
	int	j;
	int	*tab;

	i = -1;
	tab = malloc(sizeof(int) * 2);
	if (!tab)
		return (NULL);
	while (map && map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				tab[0] = j;
				tab[1] = i;
				return (tab);
			}
		}
	}
	return (0);
}
