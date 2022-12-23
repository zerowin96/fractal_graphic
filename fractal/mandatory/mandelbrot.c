/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:37:44 by yeham             #+#    #+#             */
/*   Updated: 2022/11/02 20:51:32 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	mandel_code(double i, double j, t_data *var)
{
	t_comp	z;
	t_comp	c;
	double	temp;
	int		n;

	z.real = 0;
	z.imaginary = 0;
	c.real = var->left + i * (var->xlen) / X_LEN;
	c.imaginary = var->top + j * (var->ylen) / Y_LEN;
	n = 0;
	while ((z.real * z.real) + (z.imaginary * z.imaginary) <= 4 && n < N_MAX)
	{
		temp = 2 * z.real * z.imaginary;
		z.real = (z.real * z.real) - (z.imaginary * z.imaginary) + c.real;
		z.imaginary = temp + c.imaginary;
		n++;
	}
	return (n);
}

int	print_mandelbrot(t_data *var)
{
	double		i;
	double		j;
	int			n;

	mlx_clear_window(var->mlx, var->mlx_win);
	i = 0;
	while (i < X_LEN)
	{
		j = 0;
		while (j < Y_LEN)
		{
			n = mandel_code(i, j, var);
			if (n == N_MAX)
				my_mlx_pixel_put(var, i, j, 0X00000000);
			else
				my_mlx_pixel_put(var, i, j, color(n, var->flag));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->mlx_img, 0, 0);
	return (0);
}

int	makeman(void)
{
	t_data	var;

	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx, X_LEN, Y_LEN, "Mandelbrot");
	var.mlx_img = mlx_new_image(var.mlx, X_LEN, Y_LEN);
	var.addr = mlx_get_data_addr(var.mlx_img, &var.bits_per_pixel,
			&var.line_length, &var.endian);
	setting(&var);
	print_mandelbrot(&var);
	mlx_mouse_hook(var.mlx_win, man_mouse_hook, &var);
	mlx_key_hook(var.mlx_win, man_key_hook, &var);
	mlx_hook(var.mlx_win, 17, 0, x_exit, &var);
	mlx_loop(var.mlx);
	return (0);
}

int	man_key_hook(int key, t_data *var)
{
	if (key == 53)
	{
		mlx_destroy_window(var->mlx, var->mlx_win);
		exit(0);
	}
	if (key == 18)
		var->flag = 1;
	if (key == 19)
		var->flag = 2;
	if (key == 20)
		var->flag = 3;
	if (key == 21)
		var->flag = 4;
	if (key == 126 || key == 13)
		var->top = var->top - var->ylen * 0.1;
	if (key == 125 || key == 1)
		var->top = var->top + var->ylen * 0.1;
	if (key == 123 || key == 0)
		var->left = var->left - var->xlen * 0.1;
	if (key == 124 || key == 2)
		var->left = var->left + var->xlen * 0.1;
	print_mandelbrot(var);
	return (0);
}

int	man_mouse_hook(int key, int x, int y, t_data *var)
{
	if (key == 4)
		zoom_in(var, x, y);
	if (key == 5)
		zoom_out(var, x, y);
	print_mandelbrot(var);
	return (0);
}
