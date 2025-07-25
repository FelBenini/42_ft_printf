/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:44:53 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/25 11:30:29 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_options(char *s, int *len, va_list args)
{
	if (ft_strncmp(s, "c", 1) == 0)
		*len += ft_printchar(va_arg(args, int));
	if (ft_strncmp(s, "%", 1) == 0)
		*len += ft_printchar('%');
	if (ft_strncmp(s, "s", 1) == 0)
		*len += ft_printstr(va_arg(args, char *));
	if (ft_strncmp(s, "d", 1) == 0 || ft_strncmp(s, "i", 1) == 0)
		*len += ft_printnbr(va_arg(args, int));
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
