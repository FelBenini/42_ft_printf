/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:02:47 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/26 20:58:51 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_zeros(int *len, t_special_flags *flags, int issig)
{
	int	zeros_printed;
	int	dot_printed;

	zeros_printed = 0;
	dot_printed = 0;
	if (flags->zeros)
	{
		if (flags->dot && *len <= flags->zeros && issig)
			dot_printed = write(1, "0", 1);
		while (zeros_printed + *len < flags->zeros)
			zeros_printed += write(1, "0", 1);
	}
	return (zeros_printed + dot_printed);
}

void	print_blanks(int *len, t_special_flags *flags)
{
	while (*len < flags->right)
		*len += write(1, " ", 1);
}

void	print_sharp(int *len, t_special_flags *flags, int is_upper)
{
	if (flags->sharp)
	{
		if (is_upper)
			*len += write(1, "0X", 2);
		else
			*len += write(1, "0x", 2);
	}
}
