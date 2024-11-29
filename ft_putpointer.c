/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:56:59 by heljary           #+#    #+#             */
/*   Updated: 2024/11/28 17:29:11 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_long(unsigned long n)
{
	int		len;
	int		i;
	char	*hex;
	char	str[17];

	if (n == 0)
		return (ft_putchar('0'));
	hex = "0123456789abcdef";
	i = 0;
	while (n != 0)
	{
		str[i++] = hex[n % 16];
		n = n / 16;
	}
	len = i;
	while (--i >= 0)
	{
		ft_putchar(str[i]);
	}
	return (len);
}

int	ft_putpointer(void *ptr)
{
	int				len;
	unsigned long	addr;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)ptr;
	len += ft_putstr("0x");
	if (addr == 0)
		len += ft_putchar('0');
	else
		len += ft_puthex_long(addr);
	return (len);
}
