/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:13:24 by artperez          #+#    #+#             */
/*   Updated: 2024/11/06 14:55:21 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		r;
	char	p;

	r = 0;
	i = 0;
	p = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (10 * r) + (str[i] - 48);
		i++;
	}
	return (r * p);
}
/*
#include <stdio.h>
int	main(void)
{
	char	a[] = "+529a3";

	printf("%i", ft_atoi(a));
}*/