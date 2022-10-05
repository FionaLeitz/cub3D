#include "cub3d.h"

void	free_table(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_struct(t_map_lst *first)
{
	t_map_lst	*tmp;

	while (first != NULL)
	{
		tmp = first;
		free(tmp->map_line);
		first = first->next;
		free(tmp);
	}
}

void	init(t_file *file)
{
	ft_bzero(file->params, sizeof(char *) * 7);
	file->map = NULL;
	file->first = NULL;
	file->texture.north = NULL;
	file->texture.south = NULL;
	file->texture.east = NULL;
	file->texture.west = NULL;
	file->texture.f = NULL;
	file->texture.c = NULL;
}

int	main(int argc, char **argv)
{
	t_file		file;
	int			count;

	if (argc != 2)
	{
		ft_printf("Error number of arguments\n");
		return (0);
	}
	init(&file);
	if (check_file(argv[1], &file) == 0)
	{
		free_struct(file.first);
		count = -1;
		while (file.params[++count])
			free(file.params[count]);
		free(file.map);
		return (0);
	}
	ft_printf("%s\n%s\n%s\n%s\n%s\n%d\n%s\n%d\n", file.texture.north, file.texture.south, file.texture.east, file.texture.west, file.texture.f, file.texture.color_f, file.texture.c,  file.texture.color_c);
	free_struct(file.first);
	count = -1;
	while (file.params[++count])
		free(file.params[count]);
	free(file.map);
	return (1);
}