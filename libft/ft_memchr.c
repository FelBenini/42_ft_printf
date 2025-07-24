/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:08:47 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/19 18:36:59 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*sptr;

	i = 0;
	ch = (unsigned char)c;
	sptr = (unsigned char *)s;
	while (i < n)
	{
		if (sptr[i] == ch)
			return ((char *)&sptr[i]);
		i++;
	}
	return (0);
}
