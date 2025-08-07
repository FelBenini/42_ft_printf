/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:50:43 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/15 18:53:43 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destp;
	char	*srcp;

	if (dest == NULL && src == NULL)
		return (NULL);
	destp = (char *)dest;
	srcp = (char *)src;
	i = 0;
	while (i < n)
	{
		destp[i] = srcp[i];
		i++;
	}
	return (destp);
}
