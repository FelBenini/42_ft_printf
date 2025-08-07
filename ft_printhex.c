/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:11:12 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/07 14:02:22 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(t_special_flags *flags, char *src)
{
	int	len;
	int	width;

	len = 0;
	width = 0;
	len = ft_strlen(src);
	if (flags->zeros + flags->dot > len)
	{
		len = flags->zeros;
		if (flags->dot && flags->sharp)
			len += 2;
	}
	if (flags->space > len)
		width = flags->space - len;
	if (flags->sharp)
		width += 2;
	return (len + width);
}

static void	insert_zeros(char *res, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		res[i] = '0';
		i++;
	}
}

static void	fill_hex_number(t_special_flags *flags, char *src, char *res)
{
	int		i;
	int		src_len;
	int		offset;

	offset = ft_strlen(res) - ft_strlen(src);
	if (offset < 0)
		offset = 0;
	if (flags->sharp)
		offset += 2;
	if (flags->sharp && flags->flag == 'x')
		ft_memcpy(res, "0x", 2);
	if (flags->sharp && flags->flag == 'X')
		ft_memcpy(res, "0X", 2);
	src_len = ft_strlen(src);
	i = src_len - 1;
	ft_strrev(src);
	while (i >= 0)
	{
		res[offset++] = src[i];
		i--;
	}
}

int	ft_printhex(unsigned long long n, int is_upper, t_special_flags *flags)
{
	const char	*digits = "0123456789abcdef";
	char		src[20];
	int			len;
	char		*res;

	if (is_upper)
		digits = "0123456789ABCDEF";
	len = 0;
	if (n == 0)
		return (ft_printnbr(flags, 0));
	while (n > 0)
	{
		src[len++] = digits[n % 16];
		n /= 16;
	}
	src[len] = '\0';
	ft_strrev(src);
	len = get_len(flags, src);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	if (flags->zeros > (int)ft_strlen(src))
		insert_zeros(res, len);
	fill_hex_number(flags, src, res);
	flags->dot = 0;
	len = ft_printstr(flags, res);
	free(res);
	return (len);
}
