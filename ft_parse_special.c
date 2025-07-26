/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:30:47 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/26 19:14:29 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_parse_signal(t_special_flags **flags, char **s_ptr, int *i)
{
	(*flags)->signal = 0;
	if (ft_strncmp(*s_ptr, "+", 1) == 0)
	{
		(*flags)->signal = 1;
		*i = *i + 1;
		*s_ptr += 1;
	}
}

t_special_flags	*ft_parse_special_flags(char **s_ptr, int *i)
{
	t_special_flags	*flags;
	int				j;
	char			*s;

	s = *s_ptr;
	flags = (t_special_flags *)malloc(sizeof(t_special_flags) * 1);
	j = 0;
	flags->zeros = 0;
	ft_parse_signal(&flags, s_ptr, i);
	s = *s_ptr;
	if (ft_strncmp(s, "0", 1) == 0)
	{
		while (s[j] >= '0' && s[j] <= '9')
		{
			flags->zeros = (flags->zeros * 10) + s[j++] - '0';
			*i = *i + 1;
		}
	}
	*s_ptr += j;
	return (flags);
}
