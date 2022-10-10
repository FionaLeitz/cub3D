/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:15:03 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/27 13:06:53 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1bis;
	unsigned char	*s2bis;

	i = 0;
	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && (s1bis[i] != '\0' || s2bis[i] != '\0'))
	{
		if (s1bis[i] == s2bis[i])
			i++;
		else
			return (s1bis[i] - s2bis[i]);
	}
	return (s1bis[i] - s2bis[i]);
}
/*#include <libc.h>
#include <stdio.h>

int	main()
{
	char s1[] = "test\200";
	char s2[] = "test\0";
	printf("mine : %d\n",
		   	ft_strncmp((const char *)s1, (const char *)s2, 6));
	printf("lib : %d", strncmp((const char *)s1, (const char *)s2, 6));
	return (0);
}*/
