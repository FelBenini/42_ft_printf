/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:18:15 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/17 20:54:00 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_little_len(const char *little)
{
	int	i;

	i = 0;
	while (little[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	j = 0;
	little_len = get_little_len(little);
	if (little_len == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (j < little_len && j + i < len)
		{
			if (big[j + i] != little[j])
				break ;
			j++;
		}
		if (j == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
