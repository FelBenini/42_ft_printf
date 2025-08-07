/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:45:51 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/06 18:16:11 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	insert_right_align(char *str, t_special_flags *flags)
{
	ft_memset(str + 1, ' ', flags->right);
}

static void	insert_space(char *str, t_special_flags *flags)
{
	ft_memset(str, ' ', flags->space);
}

int	ft_printchar(t_special_flags *flags, int c)
{
	int		len;
	char	*res;
	int		i;

	if (flags->flag == '%')
		return (write(1, "%", 1));
	if (flags->space != 0)
		flags->space -= 1;
	if (flags->right != 0)
		flags->right -= 1;
	len = 1 + flags->space + flags->right;
	res = ft_calloc(len + 1, sizeof(char));
	insert_space(res, flags);
	res[flags->space] = c;
	insert_right_align(res, flags);
	i = 0;
	while (i < len)
		ft_putchar_fd(res[i++], 1);
	free(res);
	return (len);
}
