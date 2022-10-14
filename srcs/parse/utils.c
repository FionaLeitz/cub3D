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

#include "../../cub3d.h"

// norme ! Print error message and 
int	error_return(char *str, int i)
{
	ft_printf("%s", str);
	return (i);
}

// create new element for list struct t_lst_map
t_map_lst	*new_line(char *line, int x)
{
	t_map_lst	*new;

	new = malloc(sizeof(t_map_lst));
	if (new == NULL)
	{
		ft_printf("Error malloc\n");
		return (NULL);
	}
	new->map_line = line;
	new->x = x;
	new->string_size = ft_strlen(line);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// check if c is whitespace
int	ft_space(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (0);
	return (-1);
}
