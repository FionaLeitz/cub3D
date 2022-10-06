/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:49:42 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/04 16:05:07 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	this function is a tool to free the memory for all char **
*/
void	ft_free_tab(char **strs)
{
	int		i;

	i = -1;
	while (strs && strs[++i])
	{
		free(strs[i]);
	}
	free(strs);
}
