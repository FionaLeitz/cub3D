/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_maj_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:26:06 by mcouppe           #+#    #+#             */
/*   Updated: 2022/06/04 13:19:39 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennbr(unsigned int nb)
{
	int	lennbr;

	lennbr = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		lennbr++;
		nb /= 16;
	}
	return (lennbr);
}

int	ft_print_maj_hexa(unsigned int nb)
{
	char				*hexa;
	unsigned long int	n;

	n = nb;
	hexa = "0123456789ABCDEF";
	if (n < 16)
		ft_printf_putchar(hexa[n % 16]);
	if (n >= 16)
	{
		ft_print_maj_hexa(n / 16);
		ft_printf_putchar(hexa[n % 16]);
	}
	return (lennbr(nb));
}
