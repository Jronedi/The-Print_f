/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:10:17 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/27 17:07:26 by mojarone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_address(unsigned long nb)
{
	int		re;
	int		written;
	char	*base;

	re = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		written = ft_puthex_address(nb / 16);
		if (written == -1)
			return (-1);
		re += written;
		written = ft_puthex_address(nb % 16);
		if (written == -1)
			return (-1);
		re += written;
	}
	else
	{
		re = ft_putchar(base[nb]);
		if (re == -1)
			return (-1);
	}
	return (re);
}

int	ft_putadress(void *nb)
{
	int	re;
	int	written;

	if (!nb)
		return (write(1, "(nil)", 5));
	re = ft_putstr("0x");
	if (re == -1)
		return (-1);
	written = ft_puthex_address((unsigned long)nb);
	if (written == -1)
		return (-1);
	re += written;
	return (re);
}
