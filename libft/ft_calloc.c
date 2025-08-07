/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:04:23 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/17 12:49:48 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dest;
	size_t	i;

	if (size == 0 || nmemb == 0)
		return (malloc(1));
	if (size > ((size_t)-1) / nmemb)
		return (0);
	dest = (char *)malloc(sizeof(char) * nmemb * size);
	if (!dest)
		return (0);
	i = 0;
	while (i < size * nmemb)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
