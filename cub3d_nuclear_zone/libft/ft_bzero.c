/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:04:58 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/15 15:59:08 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*sbis;

	i = 0;
	sbis = (char *)s;
	if (n > 0)
	{
		while (i < n)
			sbis[i++] = '\0';
	}
	s = (void *)sbis;
}
/*
#include <stdio.h>
int main()
{
	char	tab[100];
	ft_memset(tab, 'A', 100);
	ft_bzero(tab, 5);
	printf("tab[6] = %c", (char)tab[6]);
	return (0);
}*/
