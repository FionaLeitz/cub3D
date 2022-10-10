/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binaryconvert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:16:30 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/21 18:16:08 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	ft_binarytoascii(char *strinbits, int power)
{
	int	result;
	int	power_tmp;
	int	result_tmp;
	int	i;

	i = (ft_strlen(strinbits) - 1);
	result = 0;
	result_tmp = 0;
	while (i >= 0)
	{
		if (strinbits[i] == '1')
		{
			power_tmp = power;
			if (power == 0 )
				result = 1;
			else
				result_tmp = 1;
			while (power_tmp-- > 0)
				result_tmp *=  2;
			result += result_tmp;
		}
		power++;
		i--;
	}
	return (result);
}

char	*asciitobinary(char *strtobits)
{
	int	i;
//	int	j;
	char	*bitstr;

	i = 0;
	if (strtobits == NULL)
		return (NULL);
	bitstr = malloc(sizeof(char) * (8 * ft_strlen(strtobits)));
	if (!bitstr)
		return (NULL);
	while (strtobits[i] != '\0')
	{
		bitstr = chartobinary(strtobits[i], bitstr);
		i++;
	//	j++;
	}
	//bitstr[j] = NULL;
	free(strtobits);
	return (bitstr);
}*/

int	ft_converttobit(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_converttobit(nb, (power -1)));
}
/*
char	*chartobinary(char c, char *binarystr)
{
	int	i;
	int	nbr;
	nbr = (int)c;
	i = 0;
	while (nbr > 0 && i < 8)
	{
		if (nbr % 2 == 1)
			binarystr[i] = '1';
		else
			binarystr[i] = '0';
		i++;
		nbr /= 2;
	}
	binarystr[i] = '\0';
	return (binarystr);
}*/
