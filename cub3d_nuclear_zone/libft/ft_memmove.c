/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:11:13 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/27 18:53:13 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*srcbis;
	char		*destbis;
	size_t		i;

	srcbis = (char *)src;
	destbis = (char *)dest;
	i = 0;
	if (!src && !dest)
		return (NULL);
	if (dest > src)
	{
		while ((int)--n >= 0)
			*(destbis + n) = *(srcbis + n);
	}
	else
	{
		while (i < n)
		{
			*(destbis + i) = *(srcbis + i);
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <libc.h>

int main()
{
	char *dest;
	char src[] = {67, 68, 67, 68, 69, 0, 45};
	//char srcbis[] = "cons\0ect\0etur";

	dest = src + 1;
	printf("mine : %s\n", ft_memmove(dest , src, 2));
	printf("lib : %s\n", memmove(dest, src, 2));
	return (0);
}*/
