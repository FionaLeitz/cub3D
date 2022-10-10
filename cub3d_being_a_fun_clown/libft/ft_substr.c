/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:23:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/07/04 16:25:13 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, int len)
{
	int		i;
	int		j;
	char	*result;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (i > ft_strlen(s))
		len = 0;
	while (s[i] != '\0' && (j < len))
	{
		result[j] = s[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
