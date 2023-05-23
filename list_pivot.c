/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:55:04 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 12:40:23 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_little_waste_in_b(t_list **list_a, t_list **list_b)
{
	int	v1a;
	int	v2a;

	while (!ft_lististry(*list_a))
	{
		v1a = ft_get_list_value(*list_a);
		v2a = ft_get_list_value(ft_lstget_elt(1, *list_a));
		if (v1a > v2a && v2a != ft_lstmin(*list_a))
		{
			ft_push_p_to_p(list_a, list_b);
		}
		else
		{
			ft_rotate_pile(list_a);
		}
	}
}

int	ft_before_waste_in_b(t_list **list_a)
{
	t_list	**list_a_bis;
	t_list	*null1;
	t_list	**list_b_bis;
	t_list	*null2;
	int		num;

	null1 = NULL;
	list_a_bis = &null1;
	null2 = NULL;
	list_b_bis = &null2;
	null1 = ft_lstmap(*list_a, ft_copie_nb, free);
	ft_little_waste_in_b(list_a_bis, list_b_bis);
	ft_lst_sort(list_b_bis);
	num = ft_lstsize(*list_b_bis) / 2;
	num = ft_get_list_value(ft_lstget_elt(num, *list_b_bis));
	return (num);
}

int	ft_ct(t_list **la, int s, void (ft)(t_list **la, t_list **lb, int s))
{
	t_list	**list_a_bis;
	t_list	*null1;
	t_list	**list_b_bis;
	t_list	*null2;
	int		num;

	if (!s)
		return (0);
	null1 = NULL;
	list_a_bis = &null1;
	null2 = NULL;
	list_b_bis = &null2;
	null1 = ft_lstmap(*la, ft_copie_nb, free);
	(ft)(list_a_bis, list_b_bis, s);
	ft_lst_sort(list_b_bis);
	num = s / 2;
	num = ft_get_list_value(ft_lstget_elt(num, *list_b_bis));
	if (*list_a_bis)
		ft_lstclear(list_a_bis, free);
	ft_lstclear(list_b_bis, free);
	return (num);
}

int	ft_how_to_go_to(int nb, t_list *list)
{
	int	count_r;
	int	count_rr;

	count_r = 0;
	count_rr = 0;
	while (ft_get_list_value(list) != nb)
	{
		list = list->next;
		count_r++;
	}
	while (list)
	{
		list = list->next;
		count_rr++;
	}
	if (count_rr > count_r)
		return (1);
	return (0);
}

int	ft_next_of_me(int me, t_list *list)
{
	int	min;
	int	before;
	int	after;

	min = ft_lstmin(list);
	if (ft_lstsize(list) == 1)
		return (ft_get_list_value(list));
	before = ft_get_list_value(ft_lstlast(list));
	after = ft_get_list_value(list);
	while (1)
	{
		if (before < me && (me < after || after == min))
			return (after);
		else
		{
			before = after;
			list = list->next;
			after = ft_get_list_value(list);
		}
	}
}
