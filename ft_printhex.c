/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:11:12 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/07 12:39:30 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(t_special_flags *flags, char *src)
{
	int	total_len;

	total_len = ft_strlen(src);
	if (flags->zeros > total_len)
		total_len = flags->zeros;
	return (total_len);
}

static void	insert_space(t_special_flags *flags, char *src)
{
	int	i;

	i = 0;
	while (i < flags->space)
	{
		src[i] = ' ';
		i++;
	}
}

static void	fill_hex_number(t_special_flags *flags, char *src,
						int len, char *res)
{
	int		i;
	int		src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (flags->right)
	{
		i = flags->zeros - src_len;
		while (i < src_len)
		{
			res[i] = src[i];
			i++;
		}
		return ;
	}
	i = src_len - 1;
	ft_strrev(src);
	while (i >= 0)
	{
		res[len - i - 1] = src[i];
		i--;
	}
}

int	ft_printhex(unsigned long long n, int is_upper,
				t_special_flags *flags)
{
	const char	*digits = "0123456789abcdef";
	char		src[20];
	int			i;
	int			len;
	char		*res;

	i = 0;
	if (is_upper)
		digits = "0123456789ABCDEF";
	if (n == 0)
		return (ft_printnbr(flags, 0));
	while (n > 0)
	{
		src[i++] = digits[n % 16];
		n /= 16;
	}
	src[i] = '\0';
	ft_strrev(src);
	len = get_len(flags, src);
	res = ft_calloc(len + 1, sizeof(char));
	insert_space(flags, res);
	fill_hex_number(flags, src, len, res);
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}
