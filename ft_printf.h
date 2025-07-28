/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:48:40 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/26 20:19:17 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include "stdarg.h"

typedef struct s_special_flags
{
	int	zeros;
	int	signal;
	int	right;
	int	sharp;
	int	dot;
	int	space;
	int	flag;
}	t_special_flags;

int				ft_printf(const char *s, ...);
int				ft_printstr(char *str, t_special_flags *flags);
int				ft_printchar(char c, t_special_flags *flags);
int				ft_printnbr(int n, t_special_flags *flags);
int				ft_printhex(unsigned long long n, int is_upper,
					t_special_flags *flags, int len);
int				ft_printunsigned(unsigned int n, t_special_flags *flags);
t_special_flags	*ft_parse_special_flags(char **s_ptr, int *i);
int				print_zeros(int *len, t_special_flags *flags, int issig);
void			print_blanks(int *len, t_special_flags *flags);
void			print_sharp(int *len, t_special_flags *flags, int is_upper);

#endif
