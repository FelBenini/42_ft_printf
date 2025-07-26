/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:17:24 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/26 19:15:03 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printnbr(int n, t_special_flags *flags)
{
	int			len;
	long int	nb;
	char		*s;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb *= -1;
	}
	if (flags->signal && n >= 0)
		len += write(1, "+", 1);
	s = ft_utoa(nb);
	len += ft_strlen(s);
	print_zeros(&len, flags);
	ft_printstr(s);
	free(s);
	return (len);
}

int	ft_printhex(unsigned long long n, int is_upper, t_special_flags *flags)
{
	int		len;
	char	*digits;
	char	res[20];
	int		i;

	i = 0;
	digits = "0123456789abcdef";
	if (is_upper)
		digits = "0123456789ABCDEF";
	len = 0;
	if (n == 0)
		len += ft_printchar('0');
	while (n > 0)
	{
		res[i++] = digits[n % 16];
		n /= 16;
	}
	res[i] = '\0';
	ft_strrev(res);
	len += ft_strlen(res);
	print_zeros(&len, flags);
	ft_printstr(res);
	return (len);
}

int	ft_printunsigned(unsigned int n, t_special_flags *flags)
{
	char	*s;
	int		len;

	s = ft_utoa(n);
	len = ft_strlen(s);
	if (flags->signal)
		len += write(1, "+", 1);
	print_zeros(&len, flags);
	ft_printstr(s);
	free(s);
	return (len);
}
