/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:41:54 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/18 20:58:23 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	sub_len;

	sub_len = ft_strlen(s);
	if (!s)
		return (0);
	if (sub_len < start)
		return (ft_strdup(""));
	if (start + len > sub_len)
		len = sub_len - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
