/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:44:53 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/25 12:32:46 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printptr(unsigned long long p)
{
	int		len;

	len = 0;
	if (p == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	len += ft_printhex(p, 0);
	return (len);
}

static void	printf_options(char *s, int *len, va_list args)
{
	if (ft_strncmp(s, "c", 1) == 0)
		*len += ft_printchar(va_arg(args, int));
	else if (ft_strncmp(s, "%", 1) == 0)
		*len += ft_printchar('%');
	else if (ft_strncmp(s, "s", 1) == 0)
		*len += ft_printstr(va_arg(args, char *));
	else if (ft_strncmp(s, "d", 1) == 0 || ft_strncmp(s, "i", 1) == 0)
		*len += ft_printnbr(va_arg(args, int));
	else if (ft_strncmp(s, "x", 1) == 0)
		*len += ft_printhex(va_arg(args, unsigned int), 0);
	else if (ft_strncmp(s, "X", 1) == 0)
		*len += ft_printhex(va_arg(args, unsigned int), 1);
	else if (ft_strncmp(s, "p", 1) == 0)
		*len += ft_printptr(va_arg(args, unsigned long long));
	else if (ft_strncmp(s, "u", 1) == 0)
		*len += ft_printunsigned(va_arg(args, unsigned int));
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			printf_options((char *)s + i + 1, &len, args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
