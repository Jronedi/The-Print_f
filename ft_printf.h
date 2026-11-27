/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojarone <mojarone@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 17:38:05 by mojarone          #+#    #+#             */
/*   Updated: 2026/11/27 17:12:20 by mojarone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putadress(void *nb);
int	ft_putchar(char c);
int	ft_puthexlower(unsigned int nb);
int	ft_puthexupper(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	ft_putunbr(unsigned int nb);

// main func
int	ft_printf(const char *str, ...);

#endif