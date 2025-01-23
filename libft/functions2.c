/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:54:58 by artperez          #+#    #+#             */
/*   Updated: 2025/01/15 13:04:05 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	base16(unsigned int nbr, char c)
{
	char	*hexadigit;
	int		len;

	len = 0;
	if (c == 'x')
		hexadigit = "0123456789abcdef";
	else
		hexadigit = "0123456789ABCDEF";
	if (nbr > 15)
		len = len + base16(nbr / 16, c);
	ft_putchar(hexadigit[nbr % 16]);
	len++;
	return (len);
}

int	long_base16(unsigned long nbr, char c)
{
	char	*hexadigit;
	int		len;

	len = 0;
	if (c == 'x')
		hexadigit = "0123456789abcdef";
	else
		hexadigit = "0123456789ABCDEF";
	if (nbr > 15)
		len = len + long_base16(nbr / 16, c);
	ft_putchar(hexadigit[nbr % 16]);
	len++;
	return (len);
}

int	ft_strncmp_printf(const char *first, const char *second)
{
	size_t	i;

	i = 0;
	while (first[i] || second[i])
	{
		if ((unsigned char)first[i] != (unsigned char)second[i])
			return ((unsigned char)first[i] - (unsigned char)second[i]);
		i++;
	}
	return (0);
}

int	print_p(void *ptr)
{
	unsigned long	ulptr;
	int				len;

	ulptr = (unsigned long)ptr;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = 2;
	len = len + long_base16(ulptr, 'x');
	return (len);
}

int	uns_ft_putnbr(unsigned int n)
{
	int	len;
	int	recursive_len;

	len = 0;
	if (n > 9)
	{
		recursive_len = ft_putnbr_printf(n / 10);
		ft_putnbr_printf(n % 10);
		len = len + recursive_len;
	}
	else
		ft_putchar(n + '0');
	return (len + 1);
}
