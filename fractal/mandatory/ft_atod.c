/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:58:09 by yeham             #+#    #+#             */
/*   Updated: 2022/10/28 19:12:31 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

double	cul(unsigned int num, unsigned int sosu, unsigned int count)
{
	double	prime;
	double	real;

	prime = sosu;
	while (count--)
		prime = prime / 10;
	real = (double)num + prime;
	return (real);
}

void	test(char *argv, int i)
{
	int	minus;
	int	jum;

	minus = 0;
	jum = 0;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else if (argv[i] == '-' && i == 0)
			i++;
		else if (argv[i] == '.' && i != 0 && argv[i - 1] >= '0'
			&& argv[i - 1] <= '9' && argv[i + 1] >= '0' && argv[i + 1] <= '9')
		{
			i++;
			jum++;
		}
		else
			printlist();
	}
	if (jum >= 2)
		printlist();
}

double	go_double(char *argv, int i)
{
	unsigned int	num;
	unsigned int	sosu;
	unsigned int	count;

	num = 0;
	sosu = 0;
	count = 0;
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		num = num * 10 + (argv[i] - '0');
		i++;
	}
	if (argv[i] == '.')
	{
		i++;
		while (argv[i] >= '0' && argv[i] <= '9')
		{
			sosu = sosu * 10 + (argv[i] - '0');
			count++;
			i++;
		}
	}
	return (cul(num, sosu, count));
}

double	ft_atod(char *argv)
{
	int		buho;
	int		i;
	double	answer;

	buho = 1;
	i = 0;
	test(argv, i);
	if (argv[0] == '-' && argv[1] >= '0' && argv[1] <= '9')
	{
		buho *= -1;
		i++;
	}
	answer = go_double(argv, i);
	return (buho * answer);
}
