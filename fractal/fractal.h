/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:14:39 by yeham             #+#    #+#             */
/*   Updated: 2022/11/04 20:26:27 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "./mlx/minilibx_mms_20210621/mlx.h"
# define X_LEN 800
# define Y_LEN 800
# define N_MAX 100

typedef struct s_comp
{
	double	real;
	double	imaginary;
}	t_comp;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		flag;
	double	left;
	double	top;
	double	xlen;
	double	ylen;
	double	zoom;
	t_comp	c;
}	t_data;

int		makejul(t_comp *c);
int		makeman(void);
int		makeship(void);
int		jul_mouse_hook(int key, int x, int y, t_data *var);
int		man_mouse_hook(int key, int x, int y, t_data *var);
int		ship_mouse_hook(int key, int x, int y, t_data *var);
int		jul_key_hook(int key, t_data *var);
int		man_key_hook(int key, t_data *var);
int		ship_key_hook(int key, t_data *var);
int		print_julia(t_data *var);
int		print_mandelbrot(t_data *var);
int		print_ship(t_data *var);
int		color(int n, int flag);
int		x_exit(t_data *var);
double	ft_atod(char *argv);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	printlist(void);
void	setting(t_data *data);
void	zoom_in(t_data *data, int x, int y);
void	zoom_out(t_data *data, int x, int y);

#endif