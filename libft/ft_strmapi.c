/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:08:28 by artperez          #+#    #+#             */
/*   Updated: 2024/11/08 11:06:36 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
/*
char to_upper(unsigned int i, char c)
{
    (void)i; // Ignorer le paramètre `i`
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return c;
}

// Décaler chaque caractère en fonction de son index
char shift_char(unsigned int i, char c)
{
    return (c + i);
}

// Inverser la casse de chaque caractère
char invert_case(unsigned int i, char c)
{
    (void)i; // Ignorer le paramètre `i`
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    else if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return c;
}

int main()
{
    char *result;

    result = ft_strmapi("hello world", to_upper);
    if (result)
    {
        printf("Uppercase: %s\n", result);
        free(result);
    }

    result = ft_strmapi("abcde", shift_char);
    if (result)
    {
        printf("Shifted: %s\n", result);
        free(result);
    }

    result = ft_strmapi("HeLLo WoRLd", invert_case);
    if (result)
    {
        printf("Inverted case: %s\n", result);
        free(result);
    }
    return 0;
}*/