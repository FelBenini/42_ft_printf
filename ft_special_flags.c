/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:02:47 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/26 18:03:38 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zeros(int	*len, t_special_flags *flags)
{
	if (flags->zeros && *len < flags->zeros)
	{
		while (*len < flags->zeros)
			*len += write(1, "0", 1);
	}
}
