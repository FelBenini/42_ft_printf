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

void	print_zeros(int *len, t_special_flags *flags)
{
	if (flags->zeros && *len < flags->zeros)
	{
		while (*len < flags->zeros)
			*len += write(1, "0", 1);
	}
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
