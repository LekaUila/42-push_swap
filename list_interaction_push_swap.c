/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_interaction_push_swap.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:31:03 by lflandri          #+#    #+#             */
/*   Updated: 2022/10/28 19:55:41 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_pile(t_list	**list)
{
	t_list	*tempo;

	tempo = *list;
	*list = tempo->next;
	tempo->next = (*list)->next;
	(*list)->next = tempo;
}

void	ft_swap_all(t_list **list1, t_list **list2)
{
	ft_swap_pile(list1);
	ft_swap_pile(list2);
}

void	ft_push_p_to_p(t_list **listsrc, t_list **listdest)
{
	t_list	*tempo;

	tempo = *listsrc;
	*listsrc = tempo->next;
	ft_lstadd_front(listdest, tempo);
}
