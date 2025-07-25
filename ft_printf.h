/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:48:40 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/25 12:32:09 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include "stdarg.h"

int	ft_printf(const char *s, ...);
int	ft_printstr(char *str);
int	ft_printchar(char c);
int	ft_printnbr(int n);
int	ft_printhex(unsigned long long n, int is_upper);
int	ft_printunsigned(unsigned int n);

#endif
