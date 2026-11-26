/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:05:03 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/26 19:52:21 by mojarone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int	re;
	int	written;

	re = 0;
	if (nb > 9)
	{
		re = ft_putunbr(nb / 10);
		if (re == -1)
			return (-1);
		written = ft_putunbr(nb % 10);
		if (written == -1)
			return (-1);
		re += written;
	}
	else
		re = ft_putchar(nb + 48);
	if (re == -1)
		return (-1);
	return (re);
}
