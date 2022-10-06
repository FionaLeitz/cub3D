/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:23:15 by mcouppe           #+#    #+#             */
/*   Updated: 2022/06/04 13:20:00 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennbr(unsigned long long nb)
{
	unsigned long long	lennbr;

	lennbr = 0;
	if (nb == 0)
		return (3);
	while (nb > 0)
	{
		lennbr++;
		nb /= 16;
	}
	return (lennbr);
}

static int	ft_print_p_hexa(unsigned long long nb)
{
	char					*hexa;
	unsigned long long		n;

	n = nb;
	hexa = "0123456789abcdef";
	if (n < 16)
		ft_printf_putchar(hexa[n % 16]);
	if (n >= 16)
	{
		ft_print_p_hexa((n / 16));
		ft_printf_putchar(hexa[n % 16]);
	}
	return (ft_lennbr(nb));
}

int	ft_print_p(unsigned long long p)
{
	char	*addr;
	int		j;

	if (!p)
		return (write(1, "(nil)", 5));
	addr = "0x";
	j = ft_printf_strlen(addr);
	ft_printf_putstr(addr);
	j += ft_print_p_hexa(p);
	return (j);
}
