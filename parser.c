/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:32:40 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/22 11:26:01 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_double_in_strtab(int ac, char **av)
{
	int	index1;
	int	index2;

	index1 = 1;
	while (index1 != ac - 1)
	{
		index2 = index1 + 1;
		while (index2 != ac)
		{
			if (!ft_strncmp(av[index1], av[index2], 12))
				return (1);
			index2++;
		}
		index1++;
	}
	return (0);
}

int	*ft_create_pile_content(char *str)
{
	int	nb;
	int	*nb_m;

	if (ft_atoiwo(str, &nb))
		return (NULL);
	nb_m = malloc(sizeof(int));
	if (!nb_m)
		return (NULL);
	*nb_m = nb;
	return (nb_m);
}

void	ft_create_pile(int ac, char **av, t_list **list)
{
	int		i;
	t_list	*list_tempo;
	char	**split;
	int		*nb_m;

	while (ac != 1)
	{
		split = ft_split(av[ac - 1], ' ');
		i = ft_len_split(split);
		while (i-- != 0)
		{
			nb_m = ft_create_pile_content(split[i]);
			list_tempo = ft_lstnew(nb_m);
			if (!list_tempo || !nb_m)
			{
				ft_free_strtab(split);
				ft_lstclear(&list_tempo, free);
				ft_lstclear(list, free);
				ft_error("Error");
			}
			ft_lstadd_front(list, list_tempo);
		}
		ft_free_strtab(split);
		ac--;
	}
}

int	ft_str_is_digit_in_strtab(int ac, char **av)
{
	int		index1;
	int		index2;
	char	c;

	index1 = 1;
	while (index1 != ac)
	{
		index2 = 0;
		c = av[index1][index2];
		while (c)
		{
			if (!(ft_isdigit(c) || c == '-' || c == '+' || c == ' '))
				return (1);
			index2++;
			c = av[index1][index2];
		}
		index1++;
	}
	return (0);
}

void	ft_parsing(int ac, char **av, t_list **list)
{
	if (ac <= 1)
		exit(EXIT_SUCCESS);
	if (ft_double_in_strtab(ac, av))
		ft_error("Error");
	if (ft_str_is_digit_in_strtab(ac, av))
		ft_error("Error");
	ft_create_pile(ac, av, list);
}
