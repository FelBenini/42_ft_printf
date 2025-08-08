/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:32:04 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/08 14:41:06 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_to_hex(unsigned long long n, int is_upper)
{
	const char	*digits = "0123456789abcdef";
	char		*src;
	int			i;

	src = ft_calloc(20, sizeof(char));
	if (!src)
		return (NULL);
	if (is_upper)
		digits = "0123456789ABCDEF";
	i = 0;
	while (n > 0)
	{
		src[i++] = digits[n % 16];
		n /= 16;
	}
	src[i] = '\0';
	return (src);
}
