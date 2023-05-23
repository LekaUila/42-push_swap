/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_untils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:31:13 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/02 17:31:38 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_push(t_list **list_a, t_list **list_b)
{
	int	to_go;

	while (ft_lstsize(*list_b))
	{
		to_go = ft_next_of_me(ft_get_list_value(*list_b), *list_a);
		if (ft_how_to_go_to(to_go, *list_a))
		{
			while (ft_get_list_value(*list_a) != to_go)
			{
				ft_rotate_pile(list_a);
				ft_putendl_fd("ra", 1);
			}
		}
		else
		{
			while (ft_get_list_value(*list_a) != to_go)
			{
				ft_reverse_rotate_pile(list_a);
				ft_putendl_fd("rra", 1);
			}
		}
		ft_push_p_to_p(list_b, list_a);
		ft_putendl_fd("pa", 1);
	}
}

void	ft_go_to_min(t_list **list_a)
{
	int	to_go;

	to_go = ft_lstmin(*list_a);
	if (ft_how_to_go_to(to_go, *list_a))
	{
		while (ft_get_list_value(*list_a) != to_go)
		{
			ft_rotate_pile(list_a);
			ft_putendl_fd("ra", 1);
		}
	}
	else
	{
		while (ft_get_list_value(*list_a) != to_go)
		{
			ft_reverse_rotate_pile(list_a);
			ft_putendl_fd("rra", 1);
		}
	}
}

void	ft_three_or_less_pile(t_list **list_a)
{
	int	tab[3];

	tab[0] = ft_get_list_value(*list_a);
	tab[1] = ft_get_list_value((*list_a)->next);
	tab[2] = ft_get_list_value(ft_lstlast(*list_a));
	if (tab[1] == ft_lstmax(*list_a) && tab[0] == ft_lstmin(*list_a))
	{
		ft_rotate_pile(list_a);
		ft_putendl_fd("ra", 1);
	}
	else if (tab[0] == ft_lstmax(*list_a) && tab[2] == ft_lstmin(*list_a))
	{
		ft_swap_pile(list_a);
		ft_putendl_fd("sa", 1);
	}
	else
	{
		ft_reverse_rotate_pile(list_a);
		ft_putendl_fd("rra", 1);
	}
	if (!ft_lististry(*list_a))
		ft_three_or_less_pile(list_a);
}

void	ft_sort_little_pile(t_list **list_a, t_list **list_b)
{
	while (ft_lstsize(*list_a) > 3)
	{
		if (ft_get_list_value(*list_a) == ft_lstmin(*list_a))
		{
			ft_rotate_pile(list_a);
			ft_putendl_fd("ra", 1);
		}
		else
		{
			ft_push_p_to_p(list_a, list_b);
			ft_putendl_fd("pb", 1);
		}	
	}
	ft_three_or_less_pile(list_a);
	ft_last_push(list_a, list_b);
	ft_go_to_min(list_a);
}
