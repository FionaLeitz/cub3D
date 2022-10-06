/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:02:14 by mcouppe           #+#    #+#             */
/*   Updated: 2021/11/29 15:32:00 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int	main()
{
        printf("mine : %d\n", ft_isprint(32));
        printf("mine : %d\n", ft_isprint(32));
        printf("mine : %d\n", ft_isprint(0));
        printf("mine : %d\n", ft_isprint(0));
	return (0);
}*/
