/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:42:38 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/27 17:25:31 by mojarone         ###   ########.fr       */
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
		if (ft_putchar('-') == -1)
			return (-1);
		re++;
		nbr *= -1;
	}
	if (nbr > 9)
	{
		helper = ft_putnbr(nbr / 10);
		if (helper == -1)
			return (-1);
		re += helper;
	}
	if (ft_putchar((nbr % 10) + '0') == -1)
		return (-1);
	re++;
	return (re);
}
