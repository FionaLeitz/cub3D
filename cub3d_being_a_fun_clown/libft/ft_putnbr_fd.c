/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:56:55 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/20 17:30:33 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr < 10)
		ft_putchar_fd((nbr + '0'), fd);
	if (nbr >= 10)
	{
		ft_putnbr_fd((nbr / 10), fd);
		ft_putchar_fd(((nbr % 10) + '0'), fd);
	}
}
