#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_file	file;
	int		count;

	if (argc != 2)
	{
		ft_printf("Error number of arguments\n");
		return (0);
	}
	if (check_file(argv[1], &file) == 0)
		return (0);
	count = -1;
	while (file.params[++count] != NULL)
	{
		ft_printf("%s", file.params[count]);
		free(file.params[count]);
	}
	ft_printf("\n");
	count = -1;
	while (file.map[++count] != NULL)
	{
		ft_printf("%s", file.map[count]);
		free(file.map[count]);
	}
	free(file.map);
	return (1);
}