/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 17:02:25 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/27 17:06:31 by mojarone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(va_list args, char c)
{
	int	re;

	re = 0;
	if (c == 'd' || c == 'i')
		re = ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		re = ft_putchar(va_arg(args, int));
	else if (c == 's')
		re = ft_putstr(va_arg(args, char *));
	else if (c == 'x')
		re = ft_puthexlower(va_arg(args, unsigned int));
	else if (c == 'X')
		re = ft_puthexupper(va_arg(args, unsigned int));
	else if (c == 'p')
		re = ft_putadress((va_arg(args, void *)));
	else if (c == 'u')
		re = ft_putunbr(va_arg(args, unsigned int));
	else if (c == '%')
		return (ft_putchar('%'));
	if (re == -1)
		return (-1);
	return (re);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		re;
	int		written;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	re = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			written = ft_check(args, str[++i]);
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else
			written = ft_putchar(str[i]);
		if (written == -1)
			return (va_end(args), -1);
		re += written;
		i++;
	}
	va_end(args);
	return (re);
}
