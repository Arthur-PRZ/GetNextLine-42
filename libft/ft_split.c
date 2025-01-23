/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:15:52 by artperez          #+#    #+#             */
/*   Updated: 2024/11/13 11:31:23 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft__strlen(int start, char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i + start] && str[i + start] != c)
		i++;
	return (i);
}

static char	**remp(char **tab, int pos, const char *str, int len)
{
	int	i;

	i = 0;
	tab[pos] = ft_calloc((len + 1), sizeof(char));
	if (tab[pos] == NULL)
	{
		while (pos >= 0)
		{
			free(tab[pos]);
			pos--;
		}
		free(tab);
		return (NULL);
	}
	while (i < len)
	{
		tab[pos][i] = str[i];
		i++;
	}
	return (tab);
}

static int	nbrstr(char c, char const *s)
{
	int	i;
	int	str;

	i = 0;
	str = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c || s[i] == '\0')
		{
			while (s[i] == c)
				i++;
			str++;
		}
		else
			i++;
	}
	if (s[i - 1] != c && s[i] == '\0')
		str++;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		str;

	str = 0;
	if (s == NULL || *s == '\0')
		return (ft_calloc(1, sizeof(char *)));
	tab = ft_calloc((nbrstr(c, s) + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (remp(tab, str, s + i, ft__strlen(i, c, s)) == NULL)
				return (NULL);
			str++;
			i = i + ft__strlen(i, c, s);
		}
		else
			i++;
	}
	tab[str] = NULL;
	return (tab);
}
/*
int	main()
{
	char	str[] = "hello!";
	char	charset = ' ';
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(str, charset);
	while(tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab);
}*/