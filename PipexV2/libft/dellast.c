/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dellast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:30:39 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:12:25 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dellast(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next->next != NULL)
	{
		tmp = tmp ->next;
	}
	free(tmp ->next);
	tmp->next = NULL;
}
