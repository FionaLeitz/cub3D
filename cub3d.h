/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:37:56 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/14 14:01:12 by mcouppe          ###   ########.fr       */
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
# include <math.h>
# define HEIGHT_MAX 800
# define WIDTH_MAX 1600
# define RAD_FOV 1.0472
# define RAD_PERP 1.5708
# define DECR_RAD 0.174533
# define HALF_FULL_RAD 3.14159

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

typedef struct s_key
{
	int	front;
	int	back;
	int	right;
	int	left;
}		t_key;

typedef struct s_gbl
{
	void	*mlx;
	void	*window;
	t_image	new_img;
	t_file	file;
	double	p_pos[2];
	double	vector;	//distance from player to closest front wall
	double	left_fov_dist;
	int		direction;
	t_key	keys;
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
int			key_press(int key, t_gbl *gbl);
int			deal_key(t_gbl *gbl);
int			key_release(int key, t_gbl *gbl);
int			deal_cross(void *mlx);
// show.c
int			show_background(t_gbl *gbl);
// display_wall.c
void		display_wall(t_gbl *gbl);
// get_dist.c
double		get_int_vector_north(char **map, double *pos);
double		get_real_vector_north(double *pos, double old_vector);
double		get_left_dist(double AB, double *pos, char **map, double rad, double incr);
int			check_coord(int x, int y, double DE, char **map);
// get_player_pos.c
void		get_player_pos(t_map_lst *map, t_gbl *gbl);
#endif
