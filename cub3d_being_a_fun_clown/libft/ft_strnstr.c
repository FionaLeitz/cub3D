/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:58:41 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/27 19:47:38 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	ktmp;

	i = -1;
	j = 0;
	ktmp = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[++i] != '\0' && (i < n))
	{
		ktmp = i;
		while (s1[i] == s2[j] && (i < n))
		{
			if (s2[j + 1] == '\0')
				return ((&((char *)s1)[ktmp]));
			i++;
			j++;
		}
		j = 0;
		i = ktmp;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char large[30] = "aaaabaaabcaaaaaaabcd";
	char little[15] = "abc";
	
	printf("mine : %s\n", ft_strnstr(large, ((void *)0), 30));
	printf("lib : %s", strnstr(large, ((void *)0), 30));

	char *s1 = "see FF your FF return FF now FF";
	char *s2 = "FF";
	size_t max = strlen(s1);
	char *i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);
	printf("lib %s\n", i1);
	printf("mine %s", i2);
}*/
