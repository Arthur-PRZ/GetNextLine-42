/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:04:01 by artperez          #+#    #+#             */
/*   Updated: 2025/01/15 13:01:36 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search_type(char c, va_list args)
{
	if (c == 'c')
	{
		ft_putchar(va_arg(args, int));
		return (1);
	}
	if (c == 's')
		return (ft_putstr_len(va_arg(args, char *)));
	if (c == 'p')
		return (print_p(va_arg(args, void *)));
	if (c == 'd')
		return (ft_putnbr_printf(va_arg(args, long int)));
	if (c == 'i')
		return (ft_putnbr_printf(va_arg(args, int)));
	if (c == 'u')
		return (uns_ft_putnbr(va_arg(args, unsigned int)));
	if (c == 'x')
		return (base16(va_arg(args, int), c));
	if (c == 'X')
		return (base16(va_arg(args, int), c));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '\0' && format[i] != '%')
			ft_putchar(format[i]);
		if (format[i] == '%')
		{
			len = len + search_type(format[i + 1], args);
			i++;
			if (format[i] == '%')
				ft_putchar(format[i]);
		}
		else
			len++;
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main()
{
	
	//int	c = -2147483648;

	ft_printf(" %% ");
	printf(" %% ");
}*/