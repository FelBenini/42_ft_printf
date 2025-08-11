/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:37:51 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/07 17:38:05 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

static int	get_len(t_special_flags *flags, unsigned int nb)
{
	int	len;
	int	width;

	len = 0;
	width = 0;
	len = ft_intlen(nb) + flags->signal;
	if (flags->zeros + flags->dot > len)
	{
		len = flags->zeros;
		if (flags->dot && flags->signal)
			len += 1;
	}
	if (flags->space > len)
		width = flags->space - len;
	if (flags->space == 1 && !flags->arithmetic && !flags->signal)
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
						long int nb, char sign)
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
	if ((*flags)->signal)
		res[(*flags)->space] = sign;
	(*flags)->dot = 0;
}

static void	fill_number(char *src, int len, char *res)
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

int	ft_printnbr(t_special_flags *flags, int n)
{
	long int	nb;
	char		sign;
	char		*res;
	int			len;

	nb = n;
	if (flags->dot && !flags->zeros && nb == 0)
		return (ft_printstr(flags, ""));
	if (n < 0)
	{
		flags->signal = 1;
		nb *= -1;
		sign = '-';
	}
	else
		sign = '+';
	len = get_len(flags, nb);
	res = ft_calloc(len + 1, sizeof(char));
	insert_zeros(res, len);
	insert_space(&flags, res, nb, sign);
	fill_number(ft_utoa(nb), len, res);
	len = ft_printstr(flags, res);
	free(res);
	return (len);
}
