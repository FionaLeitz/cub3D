/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:37:56 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/26 17:21:48 by mcouppe          ###   ########.fr       */
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


typedef struct s_wall
{
	int		x_window;
	double	x_wall;
	double	ratio;
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
	char	*str;				// result of mlx_get_data_addr
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

typedef struct s_gbl
{
	void	*mlx;
	void	*window;
	t_image	new_img;
	t_file	file;
	double	p_pos[2];
	double	vector;				//distance from player to closest front wall
	double	left_fov_dist;
	double	v_pos[2];
	int		direction;
	int		start;
	t_key	keys;
	int		y_max;
}			t_gbl;

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
void	wall_col(t_wall	wall, t_gbl *gbl, t_image *img);
// algo.c
void	display_wall(t_gbl *gbl, char **map);
void	start_pos_to_check(t_gbl *gbl, char **map, double incr);
int		check_v_pos(t_gbl *gbl);
// check_left.c
void	check_left(t_gbl *gbl, char **map);
//check_right.c
void	check_right(t_gbl *gbl, char **map);

/*
// display_wall.c
void		display_wall(t_gbl *gbl);
// get_dist.c
double		get_int_vector_north(t_map_lst *map_lst, double *pos, int y_max);
double		get_real_vector_north(double *pos, double old_vector);
//double		get_left_dist(double AB, double *pos, char **map, double rad, double incr);
int			check_coord(int x, int y, double DE, char **map);
// get_player_pos.c
void		get_player_pos(t_map_lst *map, t_gbl *gbl);

// vectors.c
void	check_little_ray(t_gbl *gbl, double add_y, double left_dist);
double	get_little_ray(double add_y, double x);
int	check_coord_wall(t_gbl *gbl, double i, double add_y, double dist_x);
double	get_left_dist(t_gbl *gbl, double rad_to_use, double add_y, double add_x);
//int	check_coord_left_ray(double check_ray, double left_dist, t_gbl *gbl, double incr);
*/

#endif
