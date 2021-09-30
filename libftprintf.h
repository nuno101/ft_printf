/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nlouro@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:44:11 by nuno              #+#    #+#             */
/*   Updated: 2021/09/30 11:16:24 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include "libft/ft_putnbr_fd.c"
# include "libft/ft_putchar_fd.c"
# include "ft_printf.c"

int	ft_printf(const char *, ...);


#endif
