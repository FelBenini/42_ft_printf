/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:17:24 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/26 20:19:42 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printstr(char *str, t_special_flags *flags)
{
	int	i;
	int	limit;

	limit = 0;
	if (flags->dot && flags->flag == 's')
		limit = flags->zeros;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		if (flags->flag == 's' && i >= limit && flags->dot)
			break ;
		write(1, &str[i], 1);
		i++;
	}
	print_blanks(&i, flags);
	return (i);
}

int	ft_printchar(char c, t_special_flags *flags)
{
	int	len;

	len = 0;
	len += write(1, &c, 1);
	print_blanks(&len, flags);
	return (len);
}

int	ft_printnbr(int n, t_special_flags *flags)
{
	int			len;
	long int	nb;
	int			issig;
	char		*s;

	len = 0;
	nb = n;
	issig = 0;
	if (nb < 0)
	{
		issig = write(1, "-", 1);
		nb *= -1;
		flags->right -= 1;
	}
	if (flags->signal && n >= 0)
		issig = write(1, "+", 1);
	if (!issig && flags->space)
		issig = write(1, " ", 1);
	s = ft_utoa(nb);
	len += ft_strlen(s) + issig;
	len = print_zeros(&len, flags, issig);
	len += ft_printstr(s, flags);
	free(s);
	return (len + issig);
}

int	ft_printhex(unsigned long long n, int is_upper,
				t_special_flags *flags, int len)
{
	char	*digits;
	char	res[20];
	int		i;

	i = 0;
	digits = "0123456789abcdef";
	if (is_upper)
		digits = "0123456789ABCDEF";
	if (n == 0)
		len += ft_printchar('0', flags);
	else
		print_sharp(&len, flags, is_upper);
	while (n > 0)
	{
		res[i++] = digits[n % 16];
		n /= 16;
	}
	res[i] = '\0';
	ft_strrev(res);
	len += ft_strlen(res);
	len += print_zeros(&len, flags, 0);
	ft_putstr_fd(res, 1);
	print_blanks(&len, flags);
	return (len);
}

int	ft_printunsigned(unsigned int n, t_special_flags *flags)
{
	char	*s;
	int		len;
	int		issig;

	s = ft_utoa(n);
	len = ft_strlen(s);
	issig = 0;
	if (flags->signal)
		issig = write(1, "+", 1);
	len = print_zeros(&len, flags, issig);
	len += ft_printstr(s, flags);
	free(s);
	return (len + issig);
}
