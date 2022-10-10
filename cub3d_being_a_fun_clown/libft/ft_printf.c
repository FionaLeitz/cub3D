/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:19:36 by mcouppe           #+#    #+#             */
/*   Updated: 2022/06/04 13:17:05 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parseformat(int i, va_list arg, const char *str)
{
	int	j;

	j = 0;
	if (str[i] == 'd' || str[i] == 'i')
		j += ft_print_int(va_arg(arg, int));
	if (str[i] == 'c')
		j += ft_putchar_augmented(va_arg(arg, int));
	if (str[i] == 's')
		j += ft_printf_putstr(va_arg(arg, char *));
	if (str[i] == 'p')
		j += ft_print_p(va_arg(arg, unsigned long long));
	if (str[i] == 'x')
		j += ft_print_hexa(va_arg(arg, unsigned int));
	if (str[i] == 'X')
		j += ft_print_maj_hexa(va_arg(arg, unsigned int));
	if (str[i] == 'u')
		j += ft_print_un(va_arg(arg, unsigned int));
	if (str[i] == '%')
		j += write(1, &str[i], 1);
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			j;
	va_list		arg;

	i = 0;
	j = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			j += parseformat(i, arg, str);
		}
		else
			j += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (j);
}
