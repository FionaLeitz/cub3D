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
		free(tmp);
		first = first->next;
	}
}

int	main(int argc, char **argv)
{
	t_file		file;
	int			count;
	t_map_lst	*tmp;

	if (argc != 2)
	{
		ft_printf("Error number of arguments\n");
		return (0);
	}
	if (check_file(argv[1], &file) == 0)
		return (0);
	count = -1;
	while (file.params[++count])
		free(file.params[count]);
	tmp = file.first;
	while (tmp)
	{
		ft_printf("line %d = %s", tmp->y, tmp->map_line);
		tmp = tmp->next;
	}
	free_struct(file.first);
//	free(file.first->map_line);
//	free(file.first);
//	free_table(file.map);
	return (1);
}