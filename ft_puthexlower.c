/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:29:11 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/26 19:18:39 by mojarone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexlower(unsigned int nb)
{
	int		re;
	char	*base;
	int		ads;

	re = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		re = ft_puthexlower(nb / 16);
		if (re == -1)
			return (-1);
		ads = ft_puthexlower(nb % 16);
		if (ads == -1)
			return (-1);
		re += ads;
	}
	else
		re = ft_putchar(base[nb % 16]);
	if (re == -1)
		return (-1);
	return (re);
}
