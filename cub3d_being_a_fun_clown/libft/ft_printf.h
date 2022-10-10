/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:57:45 by mcouppe           #+#    #+#             */
/*   Updated: 2022/03/04 16:43:11 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_print_int(int nb);
int		ft_print_un(unsigned int nb);
int		ft_print_hexa(unsigned int nb);
int		ft_print_maj_hexa(unsigned int nb);
int		ft_print_p(unsigned long long p);
int		ft_printf_putstr(char *s);
int		ft_putchar_augmented(char c);
void	ft_printf_putnbr(int n);
void	ft_printf_putchar(char c);
size_t	ft_printf_strlen(const char *s);

#endif
