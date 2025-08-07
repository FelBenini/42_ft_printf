/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:05:31 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/18 21:02:30 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	free_arr(char **res, int n)
{
	while (n)
	{
		free(res[--n]);
	}
	free(res);
	res = 0;
}

static int	insert_into_arr(char **res, char c, char const *s)
{
	int		pos;
	int		i;
	int		start;
	char	*str;

	pos = 0;
	i = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			str = ft_substr(s, start, i - start);
			if (!str)
				return (free_arr(res, pos), 0);
			res[pos++] = str;
		}
		else
			i++;
	}
	return (res[pos] = 0, 1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		count;

	count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (0);
	insert_into_arr(res, c, s);
	return (res);
}
