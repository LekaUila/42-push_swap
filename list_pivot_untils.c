/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pivot_untils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:55:04 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/02 17:34:49 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_copie_nb(void *nb)
{
	int			*nb_m;

	nb_m = malloc(sizeof(int));
	if (nb_m)
	{
		*nb_m = *((int *) nb);
	}
	return (nb_m);
}

void	ft_t1(t_list **list_a, t_list **list_b, int size)
{
	while (size--)
	{
		ft_push_p_to_p(list_a, list_b);
	}
}

void	ft_t2(t_list **list_a, t_list **list_b, int size)
{
	while (size--)
	{
		ft_reverse_rotate_pile(list_a);
		ft_push_p_to_p(list_a, list_b);
	}
}
