/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:38:42 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/05 10:38:45 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// get colors in integers for red, green and blue
static int	get_color(char *color, int *nbr)
{
	int	count;

	count = 0;
	while (color[count] != '\0' && color[count] != ',')
		count++;
	color[count] = '\0';
	if (count > 3)
	{
		nbr[0] = -1;
		return (count);
	}
	nbr[0] = ft_atoi(color);
	color[count] = ',';
	return (count);
}

// verfy color format
static int	color_format(char *color)
{
	int	count;

	count = 0;
	while (color[count] != '\0' && ft_isdigit(color[count]) == 1)
		count++;
	if (color[count] != ',' && color[count] != '.')
		return (-1);
	return (count);
}

// get exact line without identifier
static char	*get_params(char *params)
{
	int		count;
	int		save;

	params[ft_strlen(params) - 1] = '\0';
	count = 0;
	while (params[count] != '\0' && ft_space(params[count]) == 0)
		count++;
	save = count;
	while (params[count] != '\0' && ft_space(params[count]) != 0)
		count++;
	while (params[count] != '\0' && ft_space(params[count]) == 0)
		count++;
	if (params[count] != '\0')
		return (NULL);
	return (&params[save]);
}

// check if colors are in good format
static char	*check_color(char *params, char *color, int *color_nbr)
{
	int	count;
	int	r;
	int	g;
	int	b;

	color = get_params(&params[1]);
	if (color == NULL)
		return (NULL);
	count = color_format(color);
	count += color_format(&color[count + 1]) + 1;
	if (count++ == -1)
		return (NULL);
	while (color[count] != '\0' && ft_isdigit(color[count]) == 1)
		count++;
	while (color[count] != '\0' && ft_space(color[count]) == 0)
		count++;
	if (color[count] != '\0')
		return (NULL);
	count = get_color(color, &r);
	count += get_color(&color[count + 1], &g) + 1;
	get_color(&color[count + 1], &b);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (NULL);
	color_nbr[0] = ((r << 16) + (g << 8) + (b));
	return (color);
}

// stock arguments (texture's lines and color's lines)
int	check_params(char **params, t_texture *texture)
{
	int	i;

	i = -1;
	while (params[++i])
	{
		if (ft_strncmp(params[i], "NO", 2) == 0)
			texture->north = get_params(&params[i][2]);
		else if (ft_strncmp(params[i], "SO", 2) == 0)
			texture->south = get_params(&params[i][2]);
		else if (ft_strncmp(params[i], "WE", 2) == 0)
			texture->west = get_params(&params[i][2]);
		else if (ft_strncmp(params[i], "EA", 2) == 0)
			texture->east = get_params(&params[i][2]);
		else if (ft_strncmp(params[i], "F", 1) == 0)
			texture->f = check_color(params[i], texture->f, &texture->color_f);
		else if (ft_strncmp(params[i], "C", 1) == 0)
			texture->c = check_color(params[i], texture->c, &texture->color_c);
	}
	if (!(texture->north && texture->south && texture->west
			&& texture->east && texture->f && texture->c))
	{
		ft_printf("Error params\n");
		return (0);
	}
	return (1);
}
