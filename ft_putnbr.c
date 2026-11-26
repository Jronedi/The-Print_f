/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:42:38 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/26 19:58:22 by mojarone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	re;
	int	written;

	re = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		written = ft_putchar('-');
		if (written == -1)
			return (-1);
		re += written;
		nb *= -1;
	}
	if (nb > 9)
	{
		re += ft_putnbr(nb / 10);
		re += ft_putnbr(nb % 10);
	}
	else
		re = ft_putchar(nb + 48);
	if (re == -1)
		return (-1);
	return (re);
}
