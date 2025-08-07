/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:37:51 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/06 20:55:41 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	get_len(t_special_flags **flags, unsigned int n)
{
	int	len;

	len = ft_intlen(n);
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
	return (len + (*flags)->signal);
}

static void	insert_zeros(t_special_flags *flags, char *res)
{
	int	i;

	i = flags->space;
	while (i < flags->zeros)
	{
		res[i] = '0';
		i++;
	}
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

static void	fill_number(t_special_flags *flags, unsigned int nb,
						int len, char *res)
{
	int		i;
	int		src_len;
	char	*src;

	i = 0;
	src = ft_utoa(nb);
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
	free(src);
}

int	ft_printnbr(t_special_flags *flags, int n)
{
	long int	nb;
	char		sign;
	int			len;
	char		*res;

	nb = n;
	if (n < 0)
	{
		flags->signal = 1;
		nb *= -1;
		sign = '-';
	}
	else
		sign = '+';
	len = get_len(&flags, nb);
	res = ft_calloc(len + 1, sizeof(char));
	insert_zeros(flags, res);
	insert_space(flags, res);
	fill_number(flags, nb, len, res);
	if(flags->signal)
		res[flags->space] = sign;
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}
