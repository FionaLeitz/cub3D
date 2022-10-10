/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:01:55 by mcouppe           #+#    #+#             */
/*   Updated: 2021/11/29 15:31:14 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int	main()
{
	printf("mine : %d\n", ft_isascii(32));
        printf("lib : %d\n", ft_isascii(32));
        printf("mine : %d\n", ft_isascii(250));
        printf("lib : %d\n", ft_isascii(250));
	return (0);
}*/
