/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:37:55 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/26 19:16:00 by mojarone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexupper(unsigned int nb)
{
	int		re;
	char	*base;
	int		written;

	re = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		re = ft_puthexupper(nb / 16);
		if (re == -1)
			return (-1);
		written = ft_puthexupper(nb % 16);
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
