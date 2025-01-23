/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:00:09 by artperez          #+#    #+#             */
/*   Updated: 2024/11/15 09:30:50 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft__strlen(int nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	if (nbr < 10)
		return (i);
	while (nbr >= 10)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static char	*nbr(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		if (str == NULL)
			return (NULL);
		return (str);
	}
	if (n == 0)
	{
		str = ft_strdup("0");
		if (str == NULL)
			return (NULL);
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		s;

	i = 0;
	i = ft__strlen(n);
	if (n == -2147483648 || n == 0)
		return (nbr(n));
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (n != 0)
	{
		s = n % 10;
		str[i - 1] = s + 48;
		n = n / 10;
		i--;
	}
	return (str);
}
/*
int	main()
{
	printf("%s", ft_itoa(INT_MAX));
}*/