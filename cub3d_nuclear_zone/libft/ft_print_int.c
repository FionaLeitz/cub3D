/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:36:36 by mcouppe           #+#    #+#             */
/*   Updated: 2022/06/04 13:18:07 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennbr(int nb)
{
	int				lennbr;
	unsigned int	nbr;

	nbr = nb;
	lennbr = 0;
	if (nb <= 0)
	{
		nbr *= -1;
		lennbr++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		lennbr++;
	}
	return (lennbr);
}

int	ft_print_int(int nb)
{
	int		len;

	len = lennbr(nb);
	ft_printf_putnbr(nb);
	return (len);
}
