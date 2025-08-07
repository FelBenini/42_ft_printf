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

static int	get_len(t_special_flags **flags, char *src)
{
	int	len;
	int	s_len;

	s_len = ft_strlen(src);
	len = s_len;
	if ((*flags)->zeros + (*flags)->dot > len)
		len = (*flags)->zeros;
	if ((*flags)->dot && (*flags)->signal)
		len += 1;
	if ((*flags)->zeros && (*flags)->signal)
		len -= 1;
	if ((*flags)->space > len + (*flags)->signal)
	{
		len = (*flags)->space - (*flags)->signal;
		(*flags)->space = len - (*flags)->zeros;
		(*flags)->zeros = len;
	}
	if (len < s_len + 2 && (*flags)->sharp)
		len += 2;
	return (len + (*flags)->signal);
}

static void	insert_space(t_special_flags *flags, char *res)
{
	int	i;

	i = 0;
	while (i < flags->space)
	{
		res[i] = ' ';
		i++;
	}
}

static void	fill_hex_number(t_special_flags *flags, char *src, char *res)
{
	int		i;
	int		src_len;
	int		offset;

	insert_space(flags, res);
	offset = 0;
	if (flags->sharp)
		offset = 2;
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
	len = get_len(&flags, src);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	fill_hex_number(flags, src, res);
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}
