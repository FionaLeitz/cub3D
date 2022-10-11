/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:14:26 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/11 18:22:39 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
	SLT MARINE
	tu as fais beaucoup de bordel sur ce cube donc
	mission du jour :
		- cleaner
		- bien tout passer en double en fait
		- faire des printf pour controler si les calc fonctionnent
		- definir les define donc FOV en rad etc
		- prier pour ke tout soit ok du premier kou
	ENSUITE
		- il faudra meler les codes et tout au bon endroit

	et apres enfin, on pourra REGLER la proportion avec la distance yaaaay
	les ressources d'hier étaient :
	- https://fr.wikipedia.org/wiki/Th%C3%A9or%C3%A8me_de_Thal%C3%A8s
	- https://www.dummies.com/article/academics-the-arts/math/pre-calculus/how-to-solve-a-triangle-when-you-know-two-angle-measures-167848/
	
*/

/*
	for now, it's set in a very arbitrary way but the idea is to recover and 
	implement the dist from position to wall
*/
int	get_dist(t_map_lst *map, int *pos, char **tab_map)
{
	int	x;
	int	y;
	int	j;

	void(map);
	x = pos[0];
	y = pos[1];
	j = y;
	while (tab_map && tab_map[y] && tab_map[y][x])
	{
		if (tab_map[y][x] == '1')
			return(j);
		y--;
		j--;
	}
	return (0);
}

/*
	recover the left dist with the FOV omg yes
	en gros on a besoin de BC pour savoir si entre B et 0
	y'a un mur
*/

int	get_left_dist(double AB, int *pos, char **map, double rad)
{
	double	BC;
	double	x;
	double	*coordonnees;
	int		y;

	rad_perp = 1;
	BC = AB / sin(180 - (rad + RAD_PERP))
	/*
		la on incremente thales pour check coordonnees
	*/
	coordonnees = get_coord_w_thales(map, pos, BC, AB, rad);
	if (map[coordonnees[0]][coordonnees[1]] == '1')
			return (coordonnees);
	return (0);
	/*
		AB == vector_dist == c
		c / sin(180 - (FOV + 90)) soit sin(30)
		donc c/sin(30) ==
		vector_dist / sin(30 en radian) = BC
		  
		en gros pos X --> pos[1] - dist 
	*/
}

double	get_coord_w_thales(char **map, double *pos, double BC, double AB, double rad)
{
	double	AD;
	double	DE;
	double	*coord;
	int		coord_x;
	int		coord_y;

	AD = AB - 1;
	DE = (AD * BC) / (AB * BC);
	coord = malloc(sizeof(double) * 2);
	coord_x = (pos[0] - (int)DE);
	// FOV / rad --> en gros de combien on est remonté dans les y
	coord_y = (int)(pos[1] - (FOV / rad));
	if (map[coord_y] && map[coord_y][coord_x]
		&& map[coord_y][coord_x] == '1')
		return (DE);
	return (0);
}
/*
	all display are launched from here, potentially it's also here we can 
	implement the put_image_to_window function
*/

void	make_things_visible(t_map_lst *map, t_mlx *mlx, t_play *play)
{
		double	i;
		double	rad;
		double	vector_dist;
		double	height;
		double	un_truc_en_radian_ki_decremente;

		i = -1;
/*
	le un_truc_en_radian_ki_decremente ---> a fix en define
	tout comme FOV et RAD_PERP
*/
		vector_dist = get_main_dist(map, mlx->p_pos, play->file->map);
		rad = FOV;
		while (rad > 0 && i = get_left_dist(vector_dist, mlx->p_pos, play->file->map, rad) != 0)
			rad -= un_truc_en_radian_ki_decremente;
		if (i == 0)
			printf("bah fuck\n");
			// en gros i = left_dist;
		
/********************************************************/
		while (++i <= ft_strlen(map->map_line))
			display_front_wall(mlx, mlx->p_pos, (i + 1), dist);
/*
	si on approche du mur le 690 augmente (environ + 50 par case ?)
	en fait il faut prevoir un ratio avec la taille de la window
*/
		i = 0;
		x = 261;
		height = dist * 22;
		while (x >= 0)
		{
			display_left_wall(mlx, (height + (5 * i)), x , (90 - (5 * i)));
			i++;
			x -= 10;
		}
		i = 0;
		x = 1340;
		while (x < 1600)
		{
			display_right_wall(mlx, (height + (5 * i)), x, (90 - (5 * i)));
			i++;
			x += 10;
		}
}

t_mlx	start(t_file *file)
{
	t_mlx	mlx;
	t_play	play;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d 'isaster");
	mlx.p_pos = get_player_pos(file->first);
	mlx.play = play;
	make_things_visible(file->first, &mlx, &play);
	return (mlx);
}
