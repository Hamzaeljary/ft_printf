/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:49:28 by heljary           #+#    #+#             */
/*   Updated: 2024/11/16 12:11:18 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int			count;
	long long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		count++;
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
		count++;
	}
	return (count);
}
