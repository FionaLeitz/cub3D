/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:18:27 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/21 17:59:41 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (size == 0 || nmemb == 0)
	{
		size = 1;
		nmemb = size;
	}
	ptr = (char *)malloc(nmemb * size);
	if (!ptr)
		exit(EXIT_FAILURE);
	ft_bzero(ptr, (size * nmemb));
	return (ptr);
}
