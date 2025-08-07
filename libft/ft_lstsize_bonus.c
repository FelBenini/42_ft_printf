/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:10:47 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/18 17:14:07 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		res;

	current = lst;
	res = 0;
	if (!lst)
		return (0);
	while (current)
	{
		current = current->next;
		res++;
	}
	return (res);
}
