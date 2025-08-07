/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:19:43 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/07 17:40:14 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_options(char *s, va_list args, int *i, int *len)
{
	t_special_flags	*flags;

	flags = ft_parse_special_flags(&s, i);
	if (flags->flag == 'c')
		*len += ft_printchar(flags, va_arg(args, int));
	if (flags->flag == '%')
		*len += ft_printchar(flags, '%');
	if (flags->flag == 's')
		*len += ft_printstr(flags, va_arg(args, char *));
	if (flags->flag == 'd' || flags->flag == 'i')
		*len += ft_printnbr(flags, va_arg(args, int));
	if (flags->flag == 'x')
		*len += ft_printhex(va_arg(args, unsigned int), 0, flags);
	if (flags->flag == 'X')
		*len += ft_printhex(va_arg(args, unsigned int), 1, flags);
	if (flags->flag == 'p')
		*len += ft_printptr(flags, va_arg(args, unsigned long long));
	if (flags->flag == 'u')
		*len += ft_printunsigned(va_arg(args, unsigned int), flags);
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
			printf_options((char *)s + i + 1, args, &i, &len);
		else
		{
			write(1, &s[i], 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
