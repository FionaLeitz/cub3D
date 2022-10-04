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
//	t_map_lst	*tmp;

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
	ft_printf("%s\n%s\n%s\n%s\n%s\n%s\n", file.texture.north, file.texture.south, file.texture.east, file.texture.west, file.texture.f, file.texture.c);
	// tmp = file.first;
	// while (tmp)
	// {
	// 	ft_printf("line %d =	%s", tmp->y, tmp->map_line);
	// 	tmp = tmp->next;
	// }
	// ft_printf("\n\n");
	// count = -1;
	// while (file.map[++count] != NULL)
	// 	ft_printf("line %d = 	%s", count, file.map[count]);
	free_struct(file.first);
	count = -1;
	while (file.params[++count])
		free(file.params[count]);
	free(file.map);
	return (1);
}