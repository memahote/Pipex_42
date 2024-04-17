/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delfirst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:33:55 by memahote          #+#    #+#             */
/*   Updated: 2023/01/16 14:11:39 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*delfirst(t_list *stack)
{
	t_list	*new_stack;

	new_stack = NULL;
	if (stack != NULL)
	{
		new_stack = stack ->next;
		free(stack);
		return (new_stack);
	}
	return (NULL);
}
