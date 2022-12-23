/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:24:26 by yeham             #+#    #+#             */
/*   Updated: 2022/10/28 20:03:20 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	zoom_in(t_data *data, int x, int y)
{	
	double	prev_xlen;
	double	prev_ylen;

	prev_xlen = data->xlen;
	prev_ylen = data->ylen;
	data->xlen = data->xlen * data->zoom;
	data->ylen = data->ylen * data->zoom;
	data->left = data->left + x * prev_xlen / X_LEN - x * data->xlen / X_LEN;
	data->top = data->top + y * prev_ylen / Y_LEN - y * data->ylen / Y_LEN;
}

void	zoom_out(t_data *data, int x, int y)
{	
	double	prev_xlen;
	double	prev_ylen;

	prev_xlen = data->xlen;
	prev_ylen = data->ylen;
	data->xlen = data->xlen / data->zoom;
	data->ylen = data->ylen / data->zoom;
	data->left = data->left + x * prev_xlen / X_LEN - x * data->xlen / X_LEN;
	data->top = data->top + y * prev_ylen / Y_LEN - y * data->ylen / Y_LEN;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	x_exit(t_data *var)
{
	mlx_destroy_window(var->mlx, var->mlx_win);
	exit(0);
}

int	color(int n, int flag)
{
	int	color;
	int	ff;

	ff = 256;
	if (flag == 0)
		color = ((n * 20) % ff << 16) + ((n * 20) % ff << 8) + ((n * 20) % ff);
	if (flag == 1)
		color = ((n * 20) % ff << 16) + ((n * 1) % ff << 8) + ((n * 2) % ff);
	if (flag == 2)
		color = ((n * 40) % ff << 16) + ((n * 10) % ff << 8) + ((n * 30) % ff);
	if (flag == 3)
		color = ((n * 10) % ff << 16) + ((n * 50) % ff << 8) + ((n * 20) % ff);
	if (flag == 4)
		color = ((n * 10) % ff << 16) + ((n * 20) % ff << 8) + ((n * 40) % ff);
	return (color);
}
