/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:37:56 by fleitz            #+#    #+#             */
/*   Updated: 2022/11/13 14:07:38 by mcouppe          ###   ########.fr       */
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
# define HEIGHT_MAX 600
# define WIDTH_MAX 800
# define RAD_FOV 0.785398
# define RAD_PERP 1.5708
# define DECR_RAD 0.00174533
# define RAD_ROT 0.0872665
# define HALF_FULL_RAD 3.14159
# define SPEED 1 / 2

typedef double t_vec2 __attribute__((ext_vector_type(2)));

typedef struct s_wall
{
	int		x_window;
	double	x_wall;
	double	ratio;
	char	geo;
}		t_wall;

typedef struct s_image
{
	char	*texture;			// path string
	void	*ptr;				// pointer for mlx
	int		width;
	int		height;
	int		bpp;				// bits per pixel
	int		size_line;			// number of bytes in one line
	int		endian;				// ??
	int		*str;				// result of mlx_get_data_addr
}			t_image;

typedef struct s_map_lst
{
	char				*map_line;
	int					x;
	int					string_size;
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
	int	rot_left;
	int	rot_right;
}		t_key;

typedef struct s_vectors
{
	t_vec2	ray;
	t_vec2	pos;
	t_vec2	dd;
	double	view_line;
	t_vec2	side;
	t_vec2	step;
	double	res_dda;				// la fameuse dist grrr
	int		dist_side;
	char	geo;					//N E W S
}			t_vectors;

typedef struct s_gbl
{
	void		*mlx;
	void		*window;
	t_image		new_img;
	t_file		file;
	double		p_pos[2];
	double		dir;				//distance from player to closest front wall
	double		p_dir[2];
	double		plane;
	double		p_plane_r[2];
	double		p_plane_l[2];
	int			direction;
	int			start;
	t_key		keys;
	int			y_max;
	t_vectors	vec;
}				t_gbl;

// file.c
int			check_file(char *file, t_file *file_infos, int *y_max);
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
void		wall_col(t_wall	wall, t_gbl *gbl, t_image *img);
// algo.c
void		display_wall(t_gbl *gbl, char **map);
void		start_pos_to_check(t_gbl *gbl, char **map, double incr);
int			check_v_pos(t_gbl *gbl);
// check_left.c
double		check_left(t_gbl *gbl, char **map);
double		get_fov_left_dist(t_gbl *gbl, double x, double y);
//check_right.c
double		check_right(t_gbl *gbl, char **map);
double		get_fov_right_dist(t_gbl *gbl, double x, double y);
// check_pos.c
int			check_pos(double x, double y, char **map);
// get_display.c
void	get_display_w_vectors(t_gbl *gbl, char **map);
void	get_ray(t_gbl *gbl, t_vectors *vec, double x);
void	check_n_step(t_gbl *gbl, t_vectors *vec);
void	get_walls(t_gbl *gbl, t_vectors *vec, char **map);
t_wall	get_geo_n_win_points(t_gbl *gbl, t_vectors *vec);
// display_launcher.c
// voir si vraiment necessaire
void	display_wall_launcher(t_wall wall, t_gbl *gbl, t_vectors *vec);
#endif
