#include "Minilibx/mlx.h"
#include "Minilibx/mlx_int.h"

typedef struct	s_data {
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		square_x;
	int		square_y;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	coiso(int keycode, t_data *vars)
{
	if (keycode == XK_Up)
	{
		vars->square_y -= 100;
		
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->square_y, vars->square_x);
	}
	else if (keycode == XK_Down)
	{
		vars->square_y += 100;
		
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->square_y, vars->square_x);
	}
	if (keycode == XK_Escape)
	{
		
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image (vars->mlx, vars->img);
		mlx_destroy_display (vars->mlx);
		free (vars->mlx);
		exit (0);
	}
	printf ("matem-me");
	fflush (stdout);
	return (0);
}

// int	render_next_frame(t_data *img)
// {
// 	int y = 0;
// 	int x = 0;
// 	// Clear image (set all pixels to black)
// 	for (int y = 0; y < 1080; y++)
// 		for (int x = 0; x < 1920; x++)
// 			my_mlx_pixel_put(img, x, y, 0x000000);

// 	// Draw square at current position
// 	for (int y = img->square_y; y < img->square_y + 50; y++)
// 		for (int x = img->square_x; x < img->square_x + 50; x++)
// 			my_mlx_pixel_put(img, x, y, 0xFFFFFF);

// 	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
// 	return (0);
// }

int	main(void)
{
	t_data	img;
	// void	*mlx;
	// void	*mlx_win;
	char *relative_path = "fds.xpm";
	// int x = 0;
	// int y = 0;
	// int hexa = 0;
	int sprite = 64;
	// img.square_x = 0;
	// img.square_y = 0;

	img.mlx = mlx_init();
	img.img = mlx_xpm_file_to_image (img.mlx, relative_path, &sprite, &sprite);
	img.win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// while (y < 500)
	// {
	// 	x = 0;
	// 	while (x >= 0 && x <= 500)
	// 		my_mlx_pixel_put(&img, x++, y, hexa++);
	// 	y++;
	// }
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	// mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_hook (img.win, KeyPress, KeyPressMask, coiso, &img);
	mlx_loop(img.mlx);
}
