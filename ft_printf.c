/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:41 by heljary           #+#    #+#             */
/*   Updated: 2024/11/29 10:17:41 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, int), format));
	else if (format == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar('%') + ft_putchar(format));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		p_len;
	va_list	args;

	i = 0;
	p_len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			p_len += ft_format(args, str[i + 1]);
			i++;
		}
		else
			p_len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (p_len);
}
