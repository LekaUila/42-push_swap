/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_addon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:32:37 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/02 17:46:15 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstget_elt(int index, t_list *list)
{
	if (index < 0)
		index = ft_lstsize(list) + index;
	if (index < 0 || index >= ft_lstsize(list))
		return (NULL);
	while (index != 0)
	{
		list = list->next;
		index--;
	}
	return (list);
}

int	ft_get_list_value(t_list *list)
{
	return (*((int *)(list->content)));
}

int	ft_lististry(t_list *list)
{
	int	backvalue;

	backvalue = ft_get_list_value(list);
	while (list->next)
	{
		list = list->next;
		if (backvalue > ft_get_list_value(list))
			return (0);
		backvalue = ft_get_list_value(list);
	}
	return (1);
}

int	ft_lstmin(t_list *list)
{
	int	min;

	min = ft_get_list_value(list);
	while (list->next)
	{
		list = list->next;
		if (min > ft_get_list_value(list))
			min = ft_get_list_value(list);
	}
	return (min);
}

int	ft_lstmax(t_list *list)
{
	int	max;

	max = ft_get_list_value(list);
	while (list->next)
	{
		list = list->next;
		if (max < ft_get_list_value(list))
			max = ft_get_list_value(list);
	}
	return (max);
}
