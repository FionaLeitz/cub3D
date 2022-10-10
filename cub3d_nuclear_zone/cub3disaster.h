/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3disaster.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:34:23 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/10 13:00:57 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DISASTER_H
# define CUB3DISASTER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct	s_gbl
{
	char	**map;
	void	*mlx;
	void	*win;
	int		*p_pos;
}	t_gbl;
/*
typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;

}*/

t_gbl	start(char *path);
void	make_things_visible(char **map, int *p_pos, t_gbl *gbl);
char	**building_map(char **map, char *line, int fd, int lines_nbr);
char	**getmap(char *path);
int		get_len_line(char *line);
int		get_nbr_lines(char *path);
int		*get_player_pos(char **map);
void	free_mlx_all(t_gbl *gbl);
int		keypress(int keycode, t_gbl *gbl);
int		close_btn(t_gbl *gbl);

void	display_left_wall(t_gbl *gbl, int height, int x, int y);
void	display_front_wall(int *pos, t_gbl *gbl, int w_x, int ratio_w);
void	display_right_wall(t_gbl *gbl, int height, int x, int y);


#endif
