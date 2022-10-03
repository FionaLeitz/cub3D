/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:19:19 by fleitz            #+#    #+#             */
/*   Updated: 2022/09/29 13:19:24 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/headers/ft_printf.h"
# include "libft/headers/get_next_line.h"
# include "libft/headers/libft.h"

# include <fcntl.h>

typedef struct s_file
{
	char	*params[7];
	char	**map;
}					t_file;

// parce.c
int	check_file(char *file, t_file *file_infos);

#endif
