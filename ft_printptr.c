/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:40:29 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/07 14:03:55 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(t_special_flags *flags, unsigned long long n)
{
	flags->sharp = 1;
	flags->flag = 'x';
	if (!n)
		return (ft_printstr(flags, "(nil)"));
	return (ft_printhex(n, 0, flags));
}
