#include "../../cub3d.h"

int	show(t_gbl *gbl, t_file *file)
{
	int		x;
	int		y;
	char	*pixel;

	y = -1;
	while (++y < HEIGHT_MAX)
	{
		x = -1;
		while (++x < WIDTH_MAX)
		{
			pixel = gbl->new_img.str + (y * gbl->new_img.size_line + x * (gbl->new_img.bpp / 8));
			if (y >= HEIGHT_MAX / 2)
				*(int *)pixel = file->texture.color_f;
			else
				*(int *)pixel = file->texture.color_c;
		}
	}
	mlx_put_image_to_window(gbl->mlx, gbl->window, gbl->new_img.ptr, 0, 0);
	mlx_key_hook(gbl->window, deal_key, gbl);
	mlx_hook(gbl->window, 17, 0, deal_cross, gbl->mlx);
	mlx_loop(gbl->mlx);
	return (1);
}
