/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:11:12 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/08 14:39:43 by fbenini-         ###   ########.fr       */
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
	if (flags->sharp && !flags->zeros)
		width += 2;
	if (flags->zeros + flags->dot > len)
	{
		len = flags->zeros;
		if (flags->dot && flags->sharp)
			width += 2;
	}
	if (flags->space > len)
		width = flags->space - len;
	return (len + width);
}

static void	insert_zeros(char *res, int len, t_special_flags *flags)
{
	int	i;

	i = 0;
	if (flags->space)
		i = flags->space + 1;
	if (i > len)
		i = 0;
	while (i < len)
	{
		res[i] = '0';
		i++;
	}
}

static void	insert_space(t_special_flags **flags, char *res, char *src)
{
	int	i;
	int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < (*flags)->space)
	{
		res[i] = ' ';
		i++;
	}
	if ((*flags)->zeros > src_len)
		(*flags)->space -= (*flags)->zeros + 1;
	else
		(*flags)->space -= src_len + 1;
	if ((*flags)->space < 0)
		(*flags)->space = 0;
	(*flags)->dot = 0;
}

static void	fill_hex_number(t_special_flags *flags, char *src, char *res)
{
	int		i;
	int		src_len;
	int		offset;

	offset = ft_strlen(res) - ft_strlen(src);
	if (offset < 0)
		offset = 0;
	if (flags->sharp && !flags->zeros && !flags->space)
		offset += 2;
	flags->space -= 1;
	if (flags->space < 0)
		flags->space = 0;
	if (flags->sharp && flags->flag == 'x')
		ft_memcpy(res + flags->space, "0x", 2);
	if (flags->sharp && flags->flag == 'X')
		ft_memcpy(res + flags->space, "0X", 2);
	src_len = ft_strlen(src);
	i = src_len - 1;
	while (i >= 0)
	{
		res[offset++] = src[i];
		i--;
	}
}

int	ft_printhex(unsigned long long n, int is_upper, t_special_flags *flags)
{
	char		*src;
	int			len;
	char		*res;

	if (n == 0)
		return (ft_printnbr(flags, 0));
	src = convert_to_hex(n, is_upper);
	len = get_len(flags, src);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	insert_space(&flags, res, src);
	if (flags->zeros > (int)ft_strlen(src))
		insert_zeros(res, len, flags);
	fill_hex_number(flags, src, res);
	flags->dot = 0;
	len = ft_printstr(flags, res);
	free(src);
	free(res);
	return (len);
}
