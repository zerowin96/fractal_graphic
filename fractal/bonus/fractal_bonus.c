/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:09:29 by yeham             #+#    #+#             */
/*   Updated: 2022/10/26 19:15:33 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	printlist(void)
{
	printf("프랙탈 모델 하나를 골라라\n");
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
	printf(">> Ship\n");
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
	if (argc != 2)
		printlist();
	if (ft_strcmp(argv[1], "Ship"))
	{
		makeship();
	}
	return (0);
}
