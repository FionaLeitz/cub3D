/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:44:15 by mcouppe           #+#    #+#             */
/*   Updated: 2022/06/04 13:17:25 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_printf_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

void	ft_printf_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		write(1, s, ft_printf_strlen(s));
	return (ft_printf_strlen(s));
}

void	ft_printf_putnbr(int n)
{
	long int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		ft_printf_putchar('-');
	}
	if (nbr < 10)
		ft_printf_putchar(nbr + '0');
	if (nbr >= 10)
	{
		ft_printf_putnbr(nbr / 10);
		ft_printf_putchar((nbr % 10) + '0');
	}
}

int	ft_putchar_augmented(char c)
{
	write(1, &c, 1);
	return (1);
}
