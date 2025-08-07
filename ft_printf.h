/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:48:40 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/07 12:41:30 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_special_flags
{
	int		zeros;
	int		signal;
	int		right;
	int		sharp;
	int		dot;
	int		space;
	int		flag;
}	t_special_flags;

int				ft_printf(const char *s, ...);
int				ft_printstr(t_special_flags *flags, char *str);
int				ft_printchar(t_special_flags *flags, int c);
int				ft_printnbr(t_special_flags *flags, int n);
int				ft_printhex(unsigned long long n, int is_upper,
					t_special_flags *flags);
int				ft_printptr(t_special_flags *flags, unsigned long long n);
int				ft_printunsigned(unsigned int n, t_special_flags *flags);
t_special_flags	*ft_parse_special_flags(char **s_ptr, int *i);
int				get_total_len(t_special_flags *flags, int len);

#endif
