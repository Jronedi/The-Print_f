/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:42:38 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/24 17:45:03 by mojarone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_putnbr(int nb)
{
	int re;
	re = 0;

	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		re += write(1, "-", 1);
		nb *= -1;
	}

	if (nb > 9)
	{
		re += ft_putnbr(nb / 10);
		re += ft_putnbr(nb % 10);
	}
	else
		re += ft_putchar(nb + 48);
	return (re);
}
