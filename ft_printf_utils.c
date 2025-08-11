/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:54:07 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/08 17:28:35 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	char	*res;
	int		len;

	res = ft_itoa(n);
	if (!res)
		return (0);
	ft_putstr_fd(res, 1);
	len = ft_strlen(res);
	free(res);
	return (len);
}

int	ft_printunsigned(unsigned int n)
{
	char	*res;
	int		len;

	res = ft_utoa(n);
	if (!res)
		return (0);
	ft_putstr_fd(res, 1);
	len = ft_strlen(res);
	free(res);
	return (len);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printhex(unsigned long long n, int is_upper)
{
	const char	*digits = "0123456789abcdef";
	char		src[20];
	int			i;

	if (n == 0)
		return (ft_printnbr(0));
	if (is_upper)
		digits = "0123456789ABCDEF";
	i = 0;
	while (n > 0)
	{
		src[i++] = digits[n % 16];
		n /= 16;
	}
	src[i] = '\0';
	ft_strrev(src);
	ft_putstr_fd(src, 1);
	return (ft_strlen(src));
}

int	ft_printptr(unsigned long long n)
{
	int	len;

	len = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	len += ft_printhex(n, 0);
	return (len);
}
