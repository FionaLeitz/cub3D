/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:14:46 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/14 15:06:59 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	d;

	i = 0;
	d = c;
	while (s[i] != '\0')
		i++;
	if (d == 0)
		return (&(((char *)s)[i]));
	else
	{
		while (i >= 0)
		{
			if (d == s[i])
				return (&(((char *)s)[i]));
			i--;
		}
	}
	return (NULL);
}
/*#include <string.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	char	*dest;
	char	*orig;
	(void)ac;
	dest = ft_strrchr((const char *)av[1], 65);
	orig = strrchr((const char *)av[2], 65);
	printf("mine : %s\n", dest);
	printf("orig : %s", orig);
	return (0);
}*/
