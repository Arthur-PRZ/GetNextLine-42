/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:40:19 by artperez          #+#    #+#             */
/*   Updated: 2024/11/08 11:37:42 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ftt_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (dest[len] != '\0' && len < size)
		len++;
	if (len >= size)
		return (len + ftt_strlen(src));
	while (i + len < size - 1 && src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (len + ftt_strlen(src));
}
/*
#include <stdio.h>
int	main()
{
	char	str[8] = "bonjour";
	char	str2[] = "siu";
	
	printf("%zu", ft_strlcat(str, str2, 8));
//	printf("%d", strlcat(str, str2, 8));
}*/