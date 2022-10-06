/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:10:33 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/27 19:58:40 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*destbis;
	unsigned char	*srcbis;

	i = 0;
	destbis = (unsigned char *)dest;
	srcbis = (unsigned char *)src;
	if (!src && !dest)
		return (dest);
	while ((i < (int)n) && ((int)n > 0))
	{
		destbis[i] = srcbis[i];
		i++;
	}
	while (i < (int)n)
		destbis[i++] = '\0';
	return (dest);
}
/*
#include <libc.h>
#include <stdio.h>

int	main()
{
	char	src1[] = "testtesttestestestest !";
	char	dst1[] = "";
	char	src2[] = "zy\0xw\0vu\0\0tsr";
	char	dst2[] = "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj";
	ft_memcpy(dst1 ,src1 , 0);
	memcpy((void *)0,(void *)0, 3);
	printf("mine : %s\n", dst1);
	printf("lib : %s", dst2);
	printf("mine : %p\n", ft_memcpy(dst1, src1, 0));
	printf("lib : %p", memcpy(dst1, src1, 0));
	return (0);
}*/
