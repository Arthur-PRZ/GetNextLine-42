/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:48:27 by artperez          #+#    #+#             */
/*   Updated: 2024/11/19 09:06:48 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*before(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*de;
	char	*sr;

	de = ((char *)dest);
	sr = ((char *)src);
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (de < sr)
		before(de, sr, n);
	else
	{
		i = n;
		while (i > 0)
		{
			de[i - 1] = sr[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
int	main()
{
	char	str[] = "bonjour";
	char	str2[] = "siuuu";
	void	*c;
	void	*m;
	
	c = ft_memmove(str, str2 + 1, 3);
	m = memmove(str, str2 + 1, 3);
	printf("%s ", ((char *)c));
	printf("%s", ((char *)m));
}*/