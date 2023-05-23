/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_addon_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:32:37 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/02 17:45:03 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_sort(t_list **list)
{
	int	v1a;
	int	v2a;

	while (!ft_lististry(*list))
	{
		v1a = ft_get_list_value(*list);
		v2a = ft_get_list_value(ft_lstget_elt(1, *list));
		if (v1a > v2a && v2a != ft_lstmin(*list))
			ft_swap_pile(list);
		ft_rotate_pile(list);
	}
}
