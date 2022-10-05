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

typedef struct	s_map_lst
{
	char				*map_line;
	int					y;
	struct s_map_lst	*next;
	struct s_map_lst	*prev;
}				t_map_lst;

typedef struct	s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*f;
	int		color_f;
	char	*c;
	int		color_c;
}			t_texture;

typedef struct	s_file
{
	char		*params[7];
	char		**map;
	t_map_lst	*first;
	t_texture	texture;
}				t_file;

// file.c
int			check_file(char *file, t_file *file_infos);
// utils.c
t_map_lst	*new_line(char *line, int y);
int			ft_space(char c);
// texture_colors.c
int			check_params(char **params, t_texture *texture);

#endif
