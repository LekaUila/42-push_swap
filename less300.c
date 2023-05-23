/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less300.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:27 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/22 11:37:15 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_middle(t_list **list)
{
	t_list	**list_bis;
	t_list	*null;
	int		num;

	null = NULL;
	list_bis = &null;
	null = ft_lstmap(*list, ft_copie_nb, free);
	ft_lst_sort(list_bis);
	num = ft_lstsize(*list_bis) / 2;
	num = ft_get_list_value(ft_lstget_elt(num, *list_bis));
	ft_lstclear(list_bis, free);
	return (num);
}

int	ft_get_quart3(t_list **list)
{
	t_list	**list_bis;
	t_list	*null;
	int		num;

	null = NULL;
	list_bis = &null;
	null = ft_lstmap(*list, ft_copie_nb, free);
	ft_lst_sort(list_bis);
	num = ft_lstsize(*list_bis) / 4;
	num = ft_get_list_value(ft_lstget_elt(num * 3, *list_bis));
	ft_lstclear(list_bis, free);
	return (num);
}

static void	ft_first_stape(t_list **list_a, t_list **list_b, int mid)
{
	int	quart3;
	int	start;

	mid = ft_get_middle(list_a);
	quart3 = ft_get_quart3(list_a);
	start = mid + 1;
	while (start == mid + 1 || ft_get_list_value(*list_a) != start)
	{
		if (ft_get_list_value(*list_a) > mid)
		{
			ft_push_p_to_p(list_a, list_b);
			ft_putendl_fd("pb", 1);
			if (ft_get_list_value(*list_b) < quart3)
				ft_putendl_fd("rb", 1);
			if (ft_get_list_value(*list_b) < quart3)
				ft_rotate_pile(list_b);
		}
		else
		{
			if (start == mid + 1)
				start = ft_get_list_value(*list_a);
			ft_rotate_pile(list_a);
			ft_putendl_fd("ra", 1);
		}
	}
}

static void	ft_seconde_stape(t_list **list_a, t_list **list_b)
{
	int	mid;
	int	min;

	mid = ft_get_middle(list_a);
	min = ft_lstmin(*list_a);
	while (ft_lstsize(*list_a) != 1)
	{
		if (ft_get_list_value(*list_a) != min)
		{
			ft_push_p_to_p(list_a, list_b);
			ft_putendl_fd("pb", 1);
			if (ft_get_list_value(*list_b) > mid)
			{
				ft_rotate_pile(list_b);
				ft_putendl_fd("rb", 1);
			}
		}
		else
		{
			ft_rotate_pile(list_a);
			ft_putendl_fd("ra", 1);
		}
	}
}

void	ft_sort_for_hero(t_list **list_a, t_list **list_b)
{
	ft_first_stape(list_a, list_b, 0);
	ft_seconde_stape(list_a, list_b);
	ft_last_push(list_a, list_b);
	ft_go_to_min(list_a);
}
