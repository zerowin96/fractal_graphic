/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:03:52 by yeham             #+#    #+#             */
/*   Updated: 2022/11/07 19:28:29 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	julia_code(int i, int j, t_data *var)
{
	double	temp;
	double	zx;
	double	zy;
	int		n;

	zx = var->left + i * (var->xlen) / X_LEN;
	zy = var->top + j * (var->ylen) / Y_LEN;
	n = 0;
	while ((zx * zx) + (zy * zy) <= 4 && n < N_MAX)
	{
		temp = 2 * zx * zy;
		zx = (zx * zx) - (zy * zy) + var->c.real;
		zy = temp + var->c.imaginary;
		n++;
	}
	return (n);
}

int	print_julia(t_data *var)
{
	int		i;
	int		j;
	int		n;

	mlx_clear_window(var->mlx, var->mlx_win);
	i = 0;
	while (i < X_LEN)
	{
		j = 0;
		while (j < Y_LEN)
		{
			n = julia_code(i, j, var);
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

int	makejul(t_comp *first)
{
	t_data	var;

	var.c.real = first->real;
	var.c.imaginary = first->imaginary;
	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx, X_LEN, Y_LEN, "Julia");
	var.mlx_img = mlx_new_image(var.mlx, X_LEN, Y_LEN);
	var.addr = mlx_get_data_addr(var.mlx_img, &var.bits_per_pixel,
			&var.line_length, &var.endian);
	setting(&var);
	print_julia(&var);
	mlx_mouse_hook(var.mlx_win, jul_mouse_hook, &var);
	mlx_key_hook(var.mlx_win, jul_key_hook, &var);
	mlx_hook(var.mlx_win, 17, 0, x_exit, &var);
	mlx_loop(var.mlx);
	return (0);
}

int	jul_key_hook(int key, t_data *var)
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
	print_julia(var);
	return (0);
}

int	jul_mouse_hook(int key, int x, int y, t_data *var)
{
	if (key == 1)
	{
		var->c.real = var->left + x * (var->xlen) / X_LEN;
		var->c.imaginary = var->top + y * (var->ylen) / Y_LEN;
	}
	if (key == 4)
		zoom_in(var, x, y);
	if (key == 5)
		zoom_out(var, x, y);
	print_julia(var);
	return (0);
}
