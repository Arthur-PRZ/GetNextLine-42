/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:13:59 by artperez          #+#    #+#             */
/*   Updated: 2025/01/16 09:54:58 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	if (first == NULL)
		return (1);
	while ((first[i] || second[i]) && i < length)
	{
		if ((unsigned char)first[i] != (unsigned char)second[i])
			return ((unsigned char)first[i] - (unsigned char)second[i]);
		i++;
	}
	return (0);
}
/*
int main ()
{
	char a[] = "abcdef";
	char b[] = "abc\375xx";

	printf("%d", ft_strncmp(a, b, 20));
	printf("%d", strncmp(a, b, 20));
}*/