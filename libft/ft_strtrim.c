/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:09:26 by artperez          #+#    #+#             */
/*   Updated: 2024/11/19 09:05:37 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, const char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	a;
	size_t	lenf;

	a = 0;
	lenf = ft_strlen(s1) - 1;
	while (check(s1[a], set) == 1)
		a++;
	if (ft_strlen(s1) == a)
	{
		str = ft_strdup("");
		if (str == NULL)
			return (NULL);
		return (str);
	}
	while (lenf > a && check(s1[lenf], set) == 1)
		lenf--;
	str = ft_substr(s1, a, lenf - a + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}
/*
int	main()
{
	printf("%s", ft_strtrim("siubabsiu", "siu"));
}*/