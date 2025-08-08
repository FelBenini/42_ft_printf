/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:30:47 by fbenini-          #+#    #+#             */
/*   Updated: 2025/08/07 17:39:24 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_parse_space(t_special_flags **flags, char **s_ptr, int *i)
{
	int		j;
	char	*s;

	j = 0;
	s = *s_ptr;
	if (ft_strncmp(*s_ptr, " ", 1) == 0)
	{
		(*flags)->space = 1;
		*i = *i + 1;
		*s_ptr += 1;
	}
	if (ft_isdigit(s[j]) && s[j] != '0')
	{
		(*flags)->arithmetic = 1;
		(*flags)->space = 0;
		while (ft_isdigit(s[j]))
		{
			(*flags)->space = ((*flags)->space * 10) + s[j] - '0';
			j++;
			*i = *i + 1;
		}
	}
	*s_ptr += j;
}

static void	ft_parse_right(t_special_flags **flags, char **s_ptr, int *i)
{
	int		j;
	char	*s;

	j = 0;
	s = *s_ptr;
	(*flags)->right = 0;
	if (ft_strncmp(*s_ptr, "-", 1) == 0)
	{
		j++;
		while (s[j] >= '0' && s[j] <= '9')
		{
			(*flags)->right = ((*flags)->right * 10) + s[j] - '0';
			j++;
			*i = *i + 1;
		}
		*i = *i + 1;
		*s_ptr += j;
	}
}

static void	ft_parse_sharp(t_special_flags **flags, char **s_ptr, int *i)
{
	char	*s;

	s = *s_ptr;
	if (ft_strncmp(s, "#", 1) == 0)
	{
		(*flags)->sharp = 1;
		*i = *i + 1;
		*s_ptr += 1;
	}
}

static void	ft_parse_zeros(t_special_flags **flags, char **s_ptr, int *i)
{
	char	*s;
	int		j;
	int		is_zero;
	int		zeros;

	s = *s_ptr;
	j = 0;
	zeros = 0;
	is_zero = (*flags)->zeros;
	if (ft_strncmp(s, "0", 1) == 0 || ft_strncmp(s, ".", 1) == 0)
	{
		if (ft_strncmp(s, ".", 1) == 0)
			(*flags)->dot = 1;
		j++;
		while (s[j] >= '0' && s[j] <= '9')
			zeros = (zeros * 10) + s[j++] - '0';
		*i = *i + j;
		*s_ptr += j;
	}
	if (is_zero != 0)
		(*flags)->space = is_zero;
	if ((*flags)->space < 0)
		(*flags)->space = 0;
	(*flags)->zeros = zeros;
}

t_special_flags	*ft_parse_special_flags(char **s_ptr, int *i)
{
	t_special_flags	*flags;

	flags = (t_special_flags *)malloc(sizeof(t_special_flags) * 1);
	flags->zeros = 0;
	flags->signal = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->right = 0;
	flags->dot = 0;
	flags->arithmetic = 0;
	while (ft_strchr("0.-+ #", *s_ptr[0]) || ft_isdigit(*s_ptr[0]))
	{
		if (ft_strncmp(*s_ptr, "+", 1) == 0)
		{
			flags->signal = 1;
			*i = *i + 1;
			*s_ptr += 1;
		}
		ft_parse_space(&flags, s_ptr, i);
		ft_parse_sharp(&flags, s_ptr, i);
		ft_parse_right(&flags, s_ptr, i);
		ft_parse_zeros(&flags, s_ptr, i);
	}
	flags->flag = *s_ptr[0];
	return (flags);
}
