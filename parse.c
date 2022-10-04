#include "cub3d.h"

t_map_lst	*new_line(char *line, int y)
{
	t_map_lst	*new;

	new = malloc(sizeof(t_map_lst));
	if (new == NULL)
	{
		ft_printf("Error malloc\n");
		return (NULL);
	}
	new->map_line = line;
	new->y = y;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	get_map_tab(t_file *file, int count)
{
	t_map_lst	*tmp;

	file->map = malloc(sizeof(char *) * (count + 3));
	if (file->map == NULL)
		return (0);
	tmp = file->first;
	count = -1;
	while (tmp)
	{
		file->map[++count] = tmp->map_line;
		tmp = tmp->next;
	}
	file->map[count + 1] = NULL;
	return (1);
}

int	get_map_lst(int fd, t_file *file)
{
	int			count;
	char		*str;
	t_map_lst	*tmp;

	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			ft_printf("Error no map\n");
			return (0);
		}
		if (str[0] != '\n')
			break ;
		free(str);
	}
	file->first = new_line(str, 0);
	if (file->first == NULL)
		return (0);
	tmp = file->first;
	str = get_next_line(fd);
	count = 0;
	while (str != NULL)
	{
		tmp->next = new_line(str, ++count);
		if (tmp->next == NULL)
			return (0);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		str = get_next_line(fd);
	}
	close(fd);
	if (get_map_tab(file, count) == 0)
		return (0);
	return (1);
}

int	ft_space(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (0);
	return (-1);
}

char	*get_params(char *params)
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

int	get_color(char *color, long int *nbr)
{
	int	count;

	count = 0;
	while (color[count] != '\0' && color[count] != ',')
		count++;
	color[count] = '\0';
	nbr[0] = ft_atol(color);
	color[count] = ',';
	return (count);
}

char	*check_color(char *color, int *color_nbr)
{
	int			count;
	long int	r;
	long int	g;
	long int	b;

	if (color == NULL)
		return (NULL);
	count = 0;
	while (color[count] != '\0' && ft_isdigit(color[count]) == 1)
		count++;
	if (color[count] != ',' && color[count] != '.')
		return (NULL);
	count++;
	while (color[count] != '\0' && ft_isdigit(color[count]) == 1)
		count++;
	if (color[count] != ',' && color[count] != '.')
		return (NULL);
	count++;
	while (color[count] != '\0' && ft_isdigit(color[count]) == 1)
		count++;
	while (color[count] != '\0' && ft_space(color[count]) == 0)
		count++;
	if (color[count] != '\0')
		return (NULL);
	count = get_color(color, &r);
	count += get_color(&color[count + 1], &g) + 1;
	get_color(&color[count + 1], &b);
	color_nbr[0] = ((r << 16) + (g << 8) + (b));
	return (color);
}

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
		{
			texture->f = get_params(&params[i][1]);
			texture->f = check_color(texture->f, &texture->color_f);
		}
		else if (ft_strncmp(params[i], "C", 1) == 0)
		{
			texture->c = get_params(&params[i][1]);
			texture->c = check_color(texture->c, &texture->color_c);
		}
	}
	if (!(texture->north && texture->south && texture->west && texture->east && texture->f && texture->c))
	{
		ft_printf("Error params\n");
		return (0);
	}
	return (1);
}

int	get_file_infos(int fd, t_file *file)
{
	int		count;

	count = 0;
	while (count < 6)
	{
		file->params[count] = get_next_line(fd);
		if (file->params[count] == NULL)
		{
			ft_printf("Error malloc or not enough lines\n");
			return (0);
		}
		if (file->params[count][0] == '\n')
			free(file->params[count]);
		else
			count++;
	}
	file->params[count] = NULL;
	if (check_params(file->params, &file->texture) == 0)
		return (0);
	if (get_map_lst(fd, file) == 0)
		return (0);
	return (1);
}

int	check_file(char *filename, t_file *file)
{
	int	size;
	int	fd;

	size = ft_strlen(filename);
	if (ft_strcmp(&filename[size - 4], ".cub") != 0)
	{
		ft_printf("Error file name\n");
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (0);
	}
	if (get_file_infos(fd, file) == 0)
		return (0);
	return (1);
}