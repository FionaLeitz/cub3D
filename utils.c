/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:38:50 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/05 10:38:52 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_lst	*new_line(char *line, int y)
{
	t_map_lst	*new;

	new = malloc(sizeof(t_map_lst));
	if (new == NULL)
	{
		ft_printf("Error malloc\n");
		return (NULL);
	}
	new->map_line = line;
	new->y = y;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_space(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (0);
	return (-1);
}
