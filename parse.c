#include "cub3d.h"

int	get_map2(int fd, t_file *file)
{
	char	*str;
	int		count;

	count = 0;
	str = NULL;
	while (count <= 6)
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			return (0);
		if (str[0] !=  '\n')
			count++;
	}
	count = 0;
	file->map[count] = str;
	while (str != NULL)
	{
		str = get_next_line(fd);
		file->map[++count] = str;
	}
	return (1);
}

int	get_map(int fd, t_file *file)
{
	int		count;
	char	*str;

	count = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			return (0);
		if (str[0] != '\n')
			break ;
		free(str);
	}
	while (str != NULL)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	file->map = malloc(sizeof(char *) * 15);
	if (file->map == NULL)
		return (0);
	close(fd);
	return (1);
}

int	get_file_infos(char *filename, int fd, t_file *file)
{
	int		count;

	count = 0;
	while (count < 6)
	{
		file->params[count] = get_next_line(fd);
		if (file->params[count] == NULL)
		{
			while (--count >= 0)
				free(file->params[count]);
			ft_printf("Error malloc or not enough lines\n");
			return (0);
		}
		if (file->params[count][0] == '\n')
			free(file->params[count]);
		else
			count++;
	}
	file->params[count] = NULL;
	if (get_map(fd, file) == 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (get_map2(fd, file) == 0)
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
	if (get_file_infos(filename, fd, file) == 0)
		return (0);
	return (1);
}