/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:51:33 by artperez          #+#    #+#             */
/*   Updated: 2024/11/12 10:06:41 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sstrlen(const char *len)
{
	int	i;

	i = 0;
	while (len[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	c;
	int		s;

	c = 0;
	s = 0;
	if (s2[c] == 0)
		return ((char *)s1);
	while (c + s < len && s1[c] != '\0')
	{
		s = 0;
		while (s1[c + s] == s2[s] && c + s < len)
		{
			s++;
			if (sstrlen(s2) == s)
				return ((char *)s1 + c);
		}
		c++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	char str1[30] = "aaabcabcd";
	char str2[] = "cd";

	printf("%s", ft_strnstr(str1, str2, 8));
}*/