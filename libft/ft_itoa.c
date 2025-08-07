/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:43:05 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/16 13:09:27 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	res;

	res = 0;
	if (n <= 0)
		res++;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	int		isneg;
	char	ch;

	len = numlen(n);
	isneg = 0;
	if (n < 0)
		isneg = 1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (len > 0)
	{
		ch = (n % 10) + '0';
		if (n < 0)
			ch = -(n % 10) + '0';
		res[--len] = ch;
		n /= 10;
	}
	if (isneg)
		res[0] = '-';
	return (res);
}
