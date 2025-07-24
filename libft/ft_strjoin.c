/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:17:44 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/16 13:09:40 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*res;

	s1len = getlen(s1);
	s2len = getlen(s2);
	res = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!res)
		return (0);
	s1len = 0;
	while (s1[s1len])
	{
		res[s1len] = s1[s1len];
		s1len++;
	}
	s2len = 0;
	while (s2[s2len])
	{
		res[s1len + s2len] = s2[s2len];
		s2len++;
	}
	return (res[s1len + s2len] = '\0', res);
}
