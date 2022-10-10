/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:22:21 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/29 14:54:47 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (j);
}

static void	cpy_word(char *s, char *strcpy, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		strcpy[i] = s[i];
		i++;
	}
	strcpy[i] = '\0';
}

static void	ft_free(char **split, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		free(split[i]);
		i++;
	}
	return ;
}

static void	alloc_word(char *s, char c, char **split)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			split[count] = (char *)malloc(1 * j + 1);
			if (!split)
				ft_free(split, count);
			cpy_word((s + i), split[count], c);
			i += j;
			count++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*str;
	char	**result;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = countword(str, c);
	result = (char **)malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = 0;
	alloc_word(str, c, result);
	return (result);
}

/*#include <stdio.h>

int main()
{
	
	char	str[] = "_H_e_l_l_o_ _w_o_r_l_d_ _!_!_";
	char	**result;
	int	i;

	i = 0;
	result = ft_split(str, '_');
	while (result[i])
	{
		printf("%s", result[i]);
		i++;
		printf(" %d\n", i);
	}
	return (0);
}*/
