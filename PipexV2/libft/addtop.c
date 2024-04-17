/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:49:59 by memahote          #+#    #+#             */
/*   Updated: 2023/03/30 09:07:59 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*addtop(t_list *stack, t_list *stack2)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		exit(0);
	new ->content = stack2 ->content;
	new ->next = stack;
	return (new);
}

// t_list	*addtop(t_list *stack, t_list *stack2)
// {
// 	t_list	*new;

// 	new = ft_lstnew(stack2->content);
// 	if (!new)
// 		exit(0);
// 	new->next = stack;
// 	return (new);
// }
