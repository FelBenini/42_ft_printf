/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:55:22 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/08 16:56:27 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int				ft_printf(const char *s, ...);
int				ft_printstr(char *str);
int				ft_printchar(int c);
int				ft_printnbr(int n);
int				ft_printhex(unsigned long long n, int is_upper);
int				ft_printptr(unsigned long long n);
int				ft_printunsigned(unsigned int n);

#endif
