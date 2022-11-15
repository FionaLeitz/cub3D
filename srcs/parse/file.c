/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:36:33 by fleitz            #+#    #+#             */
/*   Updated: 2022/11/14 16:28:31 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// get map in char **
static int	get_map_tab(t_file *file, int count)
{
	t_map_lst	*tmp;
	int			empty;

	file->map = malloc(sizeof(char *) * (count + 3));
	if (file->map == NULL)
		return (0);
	tmp = file->first;
	count = -1;
	empty = -1;
	while (tmp)
	{
		if (empty != -1 && tmp->map_line[0] != '\n')
			return (error_return("Error\nEmpty line\n", 0));
		file->map[++count] = tmp->map_line;
		if (empty == -1 && tmp->map_line[0] == '\n')
		{
			file->map[count] = NULL;
			empty = count;
		}
		tmp = tmp->next;
	}
	file->map[count + 1] = NULL;
	empty_line(empty, file->first);
	return (1);
}

// pass empty lines
static int	pass_useless(int fd, t_file *file)
{
	char	*str;

	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			return (error_return("Error\nNo map\n", 0));
		if (str[0] != '\n')
			break ;
		free(str);
	}
	file->first = new_line(str, 0);
	if (file->first == NULL)
		return (0);
	return (1);
}

// get map in list struct t_map_lst
static int	get_map_lst(int fd, t_file *file, int *y_max)
{
	char		*str;
	t_map_lst	*tmp;

	if (pass_useless(fd, file) == 0)
		return (0);
	tmp = file->first;
	str = get_next_line(fd);
	y_max[0] = 0;
	while (str != NULL)
	{
		tmp->next = new_line(str, ++y_max[0]);
		if (tmp->next == NULL)
			return (0);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		str = get_next_line(fd);
	}
	close(fd);
	if (get_map_tab(file, y_max[0]) == 0)
		return (0);
	return (1);
}

// get the textures informations
static int	get_file_infos(int fd, t_file *file, int *y_max)
{
	int		count;

	count = 0;
	while (count < 6)
	{
		file->params[count] = get_next_line(fd);
		if (file->params[count] == NULL)
			return (error_return("Error\nNot enough lines\n", 0));
		if (file->params[count][0] == '\n')
			free(file->params[count]);
		else
			count++;
	}
	file->params[count] = NULL;
	if (get_map_lst(fd, file, y_max) == 0)
		return (0);
	if (check_params(file->params, &file->texture) == 0)
		return (0);
	return (1);
}

// verify file's viability
int	check_file(char *filename, t_file *file, int *y_max)
{
	int	size;
	int	fd;

	size = ft_strlen(filename);
	if (ft_strcmp(&filename[size - 4], ".cub") != 0)
		return (error_return("Error\nWrong file name\n", 0));
	fd = open(filename, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (error_return("Error\nFile is a directory\n", 0));
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_return("Error\nOpening file\n", 0));
	if (get_file_infos(fd, file, y_max) == 0)
		return (0);
	if (map_characters(file) == 0)
		return (0);
	return (1);
}
