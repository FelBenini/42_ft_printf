/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:15:10 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/07 16:34:07 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(t_special_flags *flags, unsigned int nb)
{
	int	len;
	int	width;

	len = 0;
	width = 0;
	len = ft_intlen(nb);
	if (flags->zeros + flags->dot > len)
	{
		len = flags->zeros;
		if (flags->dot && flags->signal)
			len += 1;
	}
	if (flags->space > len)
		width = flags->space - len;
	if (flags->space == 1 && !flags->arithmetic)
		width += 1;
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

static void	insert_space(t_special_flags **flags, char *res,
						unsigned int nb)
{
	int	i;

	i = 0;
	while (i < (*flags)->space - (*flags)->zeros)
	{
		res[i] = ' ';
		i++;
	}
	if ((*flags)->zeros > ft_intlen(nb))
		(*flags)->space -= (*flags)->zeros + 1;
	else
		(*flags)->space -= ft_intlen(nb) + 1;
	if ((*flags)->space < 0)
		(*flags)->space = 0;
	(*flags)->dot = 0;
}

static void	fill_number(char *src,
						int len, char *res)
{
	int		i;
	int		src_len;

	src_len = ft_strlen(src);
	i = src_len - 1;
	ft_strrev(src);
	while (i >= 0)
	{
		res[len - i - 1] = src[i];
		i--;
	}
	free(src);
}

int	ft_printunsigned(unsigned int n, t_special_flags *flags)
{
	char	*res;
	int		len;

	if (flags->dot && !flags->zeros && n == 0)
		return (ft_printstr(flags, ""));
	len = get_len(flags, n);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	fill_number(ft_utoa(n), len, res);
	insert_zeros(res, len);
	insert_space(&flags, res, n);
	fill_number(ft_utoa(n), len, res);
	len = ft_printstr(flags, res);
	free(res);
	return (len);
}
