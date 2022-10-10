/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:37:56 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/10 17:04:02 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>

# define WIN_WIDTH 1600
# define WIN_HEIGHT 800

typedef struct s_map_lst
{
	char				*map_line;
	int					x;
	struct s_map_lst	*next;
	struct s_map_lst	*prev;
}				t_map_lst;

typedef struct s_texture
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

typedef struct s_play
{
	int		*p_pos;
	t_file	*file;
}			t_play;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		*p_pos;
	t_play	play;
}			t_mlx;

/*****************************************************************************/
/****************					PARSING					******************/
/*****************************************************************************/
// file.c
int			check_file(char *file, t_file *file_infos);
// utils.c
t_map_lst	*new_line(char *line, int y);
int			ft_space(char c);
// texture_colors.c
int			check_params(char **params, t_texture *texture);
// parse_map.c
int			map_characters(t_file *file);
// end.c
void		free_struct(t_map_lst *first);
int			end_parse(t_file *file, int ret);

/*****************************************************************************/
/****************					DISPLAY					******************/
/*****************************************************************************/
t_mlx	start(t_file *file);

void	free_mlx_all(t_mlx *mlx);
int		keypress(int keycode, t_mlx *mlx);
int		close_btn(t_mlx *mlx);

void	make_things_visible(t_map_lst *map, t_mlx *mlx, t_play *play);
void	display_left_wall(t_mlx *mlx, int height, int x, int y);
void	display_front_wall(t_mlx *mlx, int *pos, int w_x, int ratio_w);
void	display_right_wall(t_mlx *mlx, int height, int x, int y);

int		*get_player_pos(t_map_lst *map);

#endif
