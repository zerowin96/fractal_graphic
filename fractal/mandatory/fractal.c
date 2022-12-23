/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:33:10 by yeham             #+#    #+#             */
/*   Updated: 2022/11/03 09:59:49 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	printlist(void)
{
	printf("프랙탈 모델 하나를 골라라\n");
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf(">> Mandelbrot\n");
	printf(">> Julia\n");
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if (s1[i] == '\0')
		return (1);
	return (0);
}

void	setting(t_data *data)
{
	data->xlen = 4;
	data->ylen = 4;
	data->zoom = 0.9;
	data->flag = 0;
	data->left = -2;
	data->top = -2;
}

int	main(int argc, char *argv[])
{
	t_comp	first;

	if (argc == 1)
		printlist();
	if (ft_strcmp(argv[1], "Mandelbrot"))
	{
		if (argc != 2)
			printlist();
		makeman();
	}
	else if (ft_strcmp(argv[1], "Julia"))
	{
		if (argc != 4)
			printlist();
		first.real = ft_atod(argv[2]);
		first.imaginary = ft_atod(argv[3]);
		makejul(&first);
	}
	else
		printlist();
	return (0);
}
