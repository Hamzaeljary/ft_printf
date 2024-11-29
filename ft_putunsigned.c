/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:17:36 by heljary           #+#    #+#             */
/*   Updated: 2024/11/19 13:52:09 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	char	num[10];
	int		i;
	int		len;

	i = 0;
	len = 0;
	n = n % 4294967296;
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		num[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
		len += write(1, &num[i], 1);
	return (len);
}
