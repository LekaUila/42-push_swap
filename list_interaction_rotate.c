/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_interaction_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:51:00 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/31 10:36:56 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_pile(t_list **list)
{
	t_list	*tempo;

	tempo = *list;
	*list = tempo->next;
	tempo->next = NULL;
	ft_lstadd_back(list, tempo);
}

void	ft_rotate_all(t_list **list1, t_list **list2)
{
	ft_rotate_pile(list1);
	ft_rotate_pile(list2);
}

void	ft_reverse_rotate_pile(t_list **list)
{
	t_list	*tempo;
	t_list	*new_last;

	tempo = ft_lstlast(*list);
	new_last = ft_lstget_elt(-2, *list);
	if (!new_last)
		return ;
	new_last->next = NULL;
	ft_lstadd_front(list, tempo);
}

void	ft_reverse_rotate_all(t_list **list1, t_list **list2)
{
	ft_reverse_rotate_pile(list1);
	ft_reverse_rotate_pile(list2);
}
