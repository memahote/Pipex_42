/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:31:13 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:25:01 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list **lst)
{
	int		i;
	t_list	*head;

	head = (*lst);
	i = 0;
	while ((*lst) != NULL)
	{
		i++;
		(*lst) = (*lst)->next;
	}
	return ((*lst) = head, i);
}
