/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:10:17 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/26 18:30:42 by mojarone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(unsigned long nb)
{
	int		re;
	char	*base;
	int		written;

	re = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		re = ft_putadress(nb / 16);
		if (re == -1)
			return (-1);
		written = ft_putadress(nb % 16);
		if (written == -1)
			return (-1);
		re += written;
	}
	else
		re = ft_putchar(base[nb % 16]);
	if (re == -1)
		return (-1);
	return (re);
}
