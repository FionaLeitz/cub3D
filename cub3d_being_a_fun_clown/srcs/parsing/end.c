/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:37:15 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/10 16:19:50 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
static void	free_table(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
*/

// free list structure t_map_lst
void	free_struct(t_map_lst *first)
{
	t_map_lst	*tmp;

	while (first != NULL)
	{
		tmp = first;
		free(tmp->map_line);
		first = first->next;
		free(tmp);
	}
}

// free all parse
int	end_parse(t_file *file, int ret)
{
	int	count;

	free_struct(file->first);
	count = -1;
	while (file->params[++count])
		free(file->params[count]);
	free(file->map);
	return (ret);
}