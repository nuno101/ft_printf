/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:44:11 by nlouro              #+#    #+#           */
/*   Updated: 2021/10/08 14:01:30 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	_putstr(char *s);
int	_putchar(char c);
int	_nbrlen(long int nb, int base);
int	_putnbr(int n);
int	_putunbr(unsigned int n);
int	_putptr(unsigned long ptr);
int	_putnbrhex(unsigned int n, char *base);
int	_putlnbrhex(unsigned long n, char *base);
int	_putpercent(void);
int	ft_printf(const char *fmt, ...);

#endif
