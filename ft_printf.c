/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:44:53 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/26 20:59:05 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printptr(unsigned long long p, t_special_flags *flags)
{
	int		len;

	len = 0;
	if (p == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	write(1, "0x", 2);
	len += ft_printhex(p, 0, flags, 2);
	return (len);
}

static void	printf_options(char *s, int *len, va_list args, int *i)
{
	t_special_flags	*flags;

	flags = ft_parse_special_flags(&s, i);
	if (flags->flag == 'c')
		*len += ft_printchar(va_arg(args, int), flags);
	else if (flags->flag == '%' || !ft_strchr("%csdixXpu", flags->flag))
		*len += ft_printchar('%', flags);
	else if (flags->flag == 's')
		*len += ft_printstr(va_arg(args, char *), flags);
	else if (flags->flag == 'd' || flags->flag == 'i')
		*len += ft_printnbr(va_arg(args, int), flags);
	else if (flags->flag == 'x')
		*len += ft_printhex(va_arg(args, unsigned int), 0, flags, 0);
	else if (flags->flag == 'X')
		*len += ft_printhex(va_arg(args, unsigned int), 1, flags, 0);
	else if (flags->flag == 'p')
		*len += ft_printptr(va_arg(args, unsigned long long), flags);
	else if (flags->flag == 'u')
		*len += ft_printunsigned(va_arg(args, unsigned int), flags);
	if (!ft_strchr("%csdixXpu", flags->flag))
		*i = *i + 1;
	else
		*i = *i + 2;
	free(flags);
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
			printf_options((char *)s + i + 1, &len, args, &i);
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
