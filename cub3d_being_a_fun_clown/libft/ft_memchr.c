/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:15:25 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/11 16:27:12 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*sbis;
	char			d;
	unsigned long	i;

	d = c;
	sbis = (char *)s;
	i = 0;
	while (i < n)
	{
		if (sbis[i] == d)
		{
			return (&sbis[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <string.h>

int main()
{
	char s1[] = "bonjourno";
	char s2[] = "bonjourno";
	printf("mine : %s \n",(char *)ft_memchr((const void *)s1, 'n', 2));
	printf("lib : %s", (char *)memchr((const void *)s2, 'n', 2));
	return (0);
}*/
