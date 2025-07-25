/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:17:24 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/25 12:31:33 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_printnbr(int n)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	len = ft_strlen(s);
	ft_printstr(s);
	free(s);
	return (len);
}

int	ft_printhex(unsigned long long n, int is_upper)
{
	int		len;
	char	*digits;

	digits = "0123456789abcdef";
	if (is_upper)
		digits = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_printhex(n / 16, is_upper);
	len += ft_printchar(digits[n % 16]);
	return (len);
}

int	ft_printunsigned(unsigned int n)
{
	char	*s;
	int		len;

	s = ft_utoa(n);
	len = ft_strlen(s);
	ft_printstr(s);
	free(s);
	return (len);
}
