/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:13:08 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/14 15:07:24 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	i = 0;
	d = c;
	while (s[i] != '\0')
	{
		if (d == s[i])
			return (&(((char *)s)[i]));
		i++;
	}
	if (d == 0)
		return (&(((char *)s)[i]));
	return (NULL);
}
/*#include <string.h>
#include <stdio.h>
int	main()
{
	char	*dest;
	char	*orig;
	char s[] = "tripouille";
	dest = ft_strchr((const char *)s, ('t' + 256));
	orig = strchr((const char *)s, ('t' + 256));
	printf("mine : %s\n", dest);
	printf("orig : %s", orig);
	return (0);
}*/
