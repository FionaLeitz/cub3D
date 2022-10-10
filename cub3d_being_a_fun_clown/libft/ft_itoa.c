/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:40:49 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/14 12:51:45 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>*/

static int	ft_lennbr(int n)
{
	unsigned int	nbr;
	int				len;

	nbr = n;
	len = 0;
	if (n < 0)
	{
		len++;
		nbr *= -1;
	}
	if (n == 0)
		len++;
	while (nbr > 1)
	{
		len++;
		nbr /= 10;
	}
	if (nbr == 1)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*result;
	int				len;
	int				i;

	nbr = n;
	i = 1;
	len = ft_lennbr(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		nbr *= -1;
		result[0] = '-';
	}
	if (n == 0)
		result[0] = '0';
	while (nbr >= 1)
	{
		result[len - i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	result[len] = '\0';
	return (result);
}
/*
int	main()
{
	printf("%s\n", ft_itoa(-10));
	char *str = ft_itoa(-1234);
	printf("%s", str);
	free(ft_itoa(0));
	free(ft_itoa(-56476568));
	return (0);
}*/
