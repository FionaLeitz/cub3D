#include "minilibx-linux/mlx_int.h"
#include "minilibx-linux/mlx.h"
#include "../libft/headers/ft_printf.h"

int	deal_cross(void *mlx_ptr)
{
	mlx_loop_end(mlx_ptr);
	return (0);
}
//char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int	main(void)
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*text;
	int		width;
	int		height;


	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	text = mlx_xpm_file_to_image(mlx_ptr, "../texture/texture_north.xpm", &width, &height);
	if (text == NULL)
	{
		free(mlx_ptr);
		return (3);
	}

	int	bits_per_pixel;
	int	size_line;
	int	endian;
	char *str;
	str = mlx_get_data_addr(text, &bits_per_pixel, &size_line, &endian);
	ft_printf("%s\nbits : %d\nsize : %d\nendian : %d\nwidth : %d\nint = %d\n", str, bits_per_pixel, size_line, endian, width,  sizeof(int));


	window_ptr = mlx_new_window(mlx_ptr, 2000, 1000, "Cub3D");
	if (window_ptr == NULL)
	{
		mlx_destroy_image(mlx_ptr, text);
		free(mlx_ptr);
		return (2);
	}

	int x = -1;
	char	*pixel;
	int		color;
	while (++x < width)
	{
		int y = -1;
		while (++y < height)
		{
			pixel = str + (y * size_line + x * (bits_per_pixel / 8/* / 2*/));
			color = *(int *)pixel;
			mlx_pixel_put(mlx_ptr, window_ptr, x, y, color);
		}
	}

	mlx_hook(window_ptr, 17, 0, deal_cross, mlx_ptr);
	mlx_loop(mlx_ptr);
	mlx_destroy_image(mlx_ptr, text);
	return (0);
}
//int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
/*
char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;*/
//index = line_len * y + x * (bpp / 8)
//(image_width * (bpp / 8)) * x et 
//img->over.img = mlx_xpm_file_to_image(params->mlx_ptr, "./xpm/game_over2.xpm", &img->over.width, &img->over.height);