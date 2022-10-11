/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:37:56 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/05 10:38:01 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/headers/ft_printf.h"
# include "libft/headers/get_next_line.h"
# include "libft/headers/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <fcntl.h>
# define HEIGHT_MAX 800
# define WIDTH_MAX 1600

typedef struct s_image
{
	char	*texture;			// path string
	void	*ptr;				// pointer for mlx
	int		width;
	int		height;
	int		bpp;				// bits per pixel
	int		size_line;			// number of bytes in one line
	int		endian;				// ??
	char	*str;				// result of mlx_get_data_addr
}			t_image;	

typedef struct s_map_lst
{
	char				*map_line;
	int					x;
	struct s_map_lst	*next;
	struct s_map_lst	*prev;
}						t_map_lst;

typedef struct s_texture
{
	t_image	north;
	t_image	south;
	t_image	west;
	t_image	east;
	char	*f;
	int		color_f;
	char	*c;
	int		color_c;
}			t_texture;

typedef struct s_file
{
	char		*params[7];
	char		**map;
	int			start_y;
	int			start_x;
	int			N;
	int			S;
	int			E;
	int			W;
	t_map_lst	*first;
	t_texture	texture;
}				t_file;

typedef struct s_gbl
{
	void	*mlx;
	void	*window;
	t_image	new_img;
}			t_gbl;

// file.c
int			check_file(char *file, t_file *file_infos);
// utils.c
int			error_return(char *str, int i);
t_map_lst	*new_line(char *line, int y);
int			ft_space(char c);
// texture_colors.c
int			check_params(char **params, t_texture *texture);
// parse_map.c
int			map_characters(t_file *file);
// end.c
void		end_mlx(t_texture *texture, t_gbl *gbl, t_file *file);
void		free_struct(t_map_lst *first);
void		end_parse(t_file *file);
// create_imgs
int			open_all(t_texture *texture, t_gbl *gbl, t_file *file);
// event.c
int			deal_key(int key, t_gbl *gbl);
int			deal_cross(void *mlx);
// show.c
int			show(t_gbl *gbl, t_file *file);

#endif
