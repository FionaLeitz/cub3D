/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:16:31 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/27 12:48:23 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	int				size;
	unsigned char	*s1bis;
	unsigned char	*s2bis;

	size = (int)n;
	i = 0;
	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	if (n == 0 || (!s1bis && !s2bis))
		return (0);
	while (i < (size - 1))
	{
		if (s1bis[i] == s2bis[i])
			i++;
		else
			return (s1bis[i] - s2bis[i]);
	}
	return (s1bis[i] - s2bis[i]);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char	*s1;
	char	*s2;

	s1 = "helo";
	s2 = "hela";
	printf("mine : %d\n", ft_memcmp(s1, s2, 12));
        printf("lib : %d", memcmp(s1, s2, 12));
	return (0);
}*/
