/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:56:11 by mcouppe           #+#    #+#             */
/*   Updated: 2022/06/04 13:20:18 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennbr(int nb)
{
	int				lennbr;
	unsigned int	nbr;

	nbr = nb;
	lennbr = 0;
	if (nb == 0)
		lennbr++;
	while (nbr > 0)
	{
		nbr /= 10;
		lennbr++;
	}
	return (lennbr);
}

static void	ft_putnbr_un(unsigned int n)
{
	long int	nbr;

	nbr = n;
	if (nbr < 10)
		ft_printf_putchar(nbr + '0');
	if (nbr >= 10)
	{
		ft_putnbr_un(nbr / 10);
		ft_printf_putchar((nbr % 10) + '0');
	}
}

int	ft_print_un(unsigned int nb)
{
	int	len;

	len = lennbr(nb);
	ft_putnbr_un(nb);
	return (len);
}
