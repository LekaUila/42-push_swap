/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:10:14 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/22 11:38:30 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_waste_in_b(t_list **list_a, t_list **list_b, int num)
{
	int	v1a;
	int	count;

	count = 0;
	while (!ft_lististry(*list_a))
	{
		v1a = ft_get_list_value(*list_a);
		if (v1a != ft_lstmin(*list_a))
		{
			ft_push_p_to_p(list_a, list_b);
			ft_putendl_fd("pb", 1);
			if (ft_get_list_value(*list_b) < num)
			{
				ft_rotate_pile(list_b);
				ft_putendl_fd("rb", 1);
				count++;
			}
		}
		else
		{
			ft_rotate_pile(list_a);
			ft_putendl_fd("ra", 1);
		}
	}
	return (count);
}

int	ft_go_to_sup(t_list **listsrc, t_list **listdest, int num, int size)
{
	int	count;
	int	save;

	count = 0;
	while (size--)
	{
		ft_push_p_to_p(listsrc, listdest);
		ft_putendl_fd("pa", 1);
		if (ft_get_list_value(*listdest) > num)
		{
			ft_rotate_pile(listdest);
			ft_putendl_fd("ra", 1);
		}
		else
			count++;
	}
	save = count;
	while (count--)
	{
		ft_rotate_pile(listdest);
		ft_putendl_fd("ra", 1);
	}
	return (save);
}

int	ft_go_to_inf(t_list **listsrc, t_list **listdest, int num, int size)
{
	int	count;
	int	save;

	count = 0;
	while (size--)
	{
		ft_reverse_rotate_pile(listsrc);
		ft_putendl_fd("rra", 1);
		ft_push_p_to_p(listsrc, listdest);
		ft_putendl_fd("pb", 1);
		if (ft_get_list_value(*listdest) < num)
		{
			ft_rotate_pile(listdest);
			ft_putendl_fd("rb", 1);
		}
		else
			count++;
	}
	save = count;
	while (count--)
	{
		ft_rotate_pile(listdest);
		ft_putendl_fd("rb", 1);
	}
	return (save);
}

void	ft_card_sort(t_list **list_a, t_list **list_b)
{
	int	num ;
	int	wastemin;
	int	tab[4];
	int	i;

	i = 0;
	num = ft_ct(list_a, ft_lstsize(*list_a) - 3, ft_t1);
	wastemin = ft_waste_in_b(list_a, list_b, num);
	tab[1] = ft_lstsize(*list_b) - wastemin;
	num = ft_ct(list_b, ft_lstsize(*list_b) - wastemin, ft_t1);
	tab[0] = ft_go_to_sup(list_b, list_a, num, ft_lstsize(*list_b) - wastemin);
	tab[1] = tab[1] - tab[0];
	tab[3] = wastemin;
	num = ft_ct(list_b, wastemin, ft_t1);
	tab [2] = ft_go_to_sup(list_b, list_a, num, wastemin);
	tab[3] = tab[3] - tab[2];
	while (i != 4)
	{
		num = ft_ct(list_a, tab[i], ft_t2);
		ft_go_to_inf(list_a, list_b, num, tab[i]);
		i++;
	}
	ft_last_push(list_a, list_b);
	ft_go_to_min(list_a);
}

int	main(int ac, char **av)
{
	t_list	**list_a;
	t_list	*null1;
	t_list	**list_b;
	t_list	*null2;

	null1 = NULL;
	list_a = &null1;
	null2 = NULL;
	list_b = &null2;
	ft_parsing(ac, av, list_a);
	if (ft_lstsize(*list_a) <= 1 || ft_lististry(*list_a))
	{
		ft_lstclear(list_a, free);
		return (1);
	}
	if (ft_lstsize(*list_a) <= 3)
		ft_three_or_less_pile(list_a);
	else if (ft_lstsize(*list_a) <= 8)
		ft_sort_little_pile(list_a, list_b);
	else if (ft_lstsize(*list_a) <= 250)
		ft_sort_for_hero(list_a, list_b);
	else
		ft_card_sort(list_a, list_b);
	ft_lstclear(list_a, free);
	return (1);
}
