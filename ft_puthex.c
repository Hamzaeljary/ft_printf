/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:06:56 by heljary           #+#    #+#             */
/*   Updated: 2024/11/19 09:50:10 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	int		len;
	int		i;
	char	*hex;
	char	str[9];

	if (n == 0)
		return (ft_putchar('0'));
	if (format == 'x')
	{
		hex = "0123456789abcdef";
	}
	else
		hex = "0123456789ABCDEF";
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
