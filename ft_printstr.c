/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:19:34 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/06 21:15:59 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	insert_space(t_special_flags *flags, char *str)
{
	if (flags->right)
		ft_memset(str, ' ', flags->right);
	if (flags->space)
		ft_memset(str, ' ', flags->space);
}

static int	get_len(t_special_flags *flags, char *str)
{
	int	len;

	len = 6;
	if (str)
		len = ft_strlen(str);
	if (flags->dot)
		len = flags->zeros + flags->space + flags->right;
	if (flags->space > len)
		len = flags->space - flags->zeros;
	if (flags->right > len)
		len = flags->right - flags->zeros;
	if ((flags->dot && flags->space) || (flags->dot && flags->right))
		len -= flags->zeros;
	return (len);
}

static void	fill_string(t_special_flags *flags, char *src, char *res, int len)
{
	int	i;
	int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (flags->right)
	{
		while (i < src_len)
		{
			res[i] = src[i];
			i++;
		}
		return ;
	}
	i = src_len - 1;
	ft_strrev(src);
	while (i >= 0)
	{
		res[len - i - 1] = src[i];
		i--;
	}
}

static int	handle_null(t_special_flags *flags)
{
	char	*str;
	int		len;
	char	*res;

	if (flags->dot && flags->zeros < 6)
		str = ft_strdup("");
	else
		str = ft_strdup("(null)");
	len = get_len(flags, str);
	res = ft_calloc(len + 1, sizeof(char));
	insert_space(flags, res);
	fill_string(flags, str, res, len);
	ft_putstr_fd(res, 1);
	free(res);
	free(str);
	return (len);
}

int	ft_printstr(t_special_flags *flags, char *str)
{
	int		len;
	char	*res;
	char	*s_str;

	if (str == NULL)
		return (handle_null(flags));
	if (flags->dot)
		s_str = ft_substr(str, 0, flags->zeros);
	else
		s_str = ft_strdup(str);
	len = get_len(flags, str);
	res = ft_calloc(len + 1, sizeof(char));
	insert_space(flags, res);
	fill_string(flags, s_str, res, len);
	ft_putstr_fd(res, 1);
	free(res);
	free(s_str);
	return (len);
}
