/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:42:38 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/27 17:10:46 by mojarone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		re;
	long	nbr;
	int		helper;

	re = 0;
	nbr = nb;
	if (nbr < 0)
	{
		helper = ft_putchar('-');
		if (helper == -1)
			return (-1);
		re += helper;
		nbr *= -1;
	}
	if (nbr > 9)
	{
		re = ft_putnbr(nbr / 10);
		if (re == -1)
			return (-1);
		helper = ft_putnbr(nbr % 10);
		if (helper == -1)
			return (-1);
		re += helper;
	}
	else
	{
		helper = ft_putchar(nbr + 48);
		if (helper == -1)
			return (-1);
		re += helper;
	}
	return (re);
}
