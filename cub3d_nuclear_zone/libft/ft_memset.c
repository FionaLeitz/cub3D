/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:04:40 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/01 15:21:11 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;
	char			d;

	d = c;
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = d;
		i++;
	}
	return (&(((char *)s)[0]));
}
/*
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("mine %s\n", (char *)ft_memset(av[1], 65, 4));
	printf("lib %s",(char *) memset(av[2], 65, 4));
	return (0);
}*/
