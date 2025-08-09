/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:43:05 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/25 12:29:40 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ulen(unsigned int n)
{
	int	res;

	res = 0;
	if (n == 0)
		res++;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*res;
	char	ch;

	len = ulen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (len > 0)
	{
		ch = (n % 10) + '0';
		res[--len] = ch;
		n /= 10;
	}
	return (res);
}
