/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:30:49 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/22 11:07:27 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./LIBFT/libft.h"

void	ft_parsing(int ac, char **av, t_list **list);
int		ft_atoiwo(char *str, int *n);
t_list	*ft_lstget_elt(int index, t_list *list);
int		ft_get_list_value(t_list *list);
int		ft_lististry(t_list *list);
int		ft_lstmin(t_list *list);
int		ft_lstmax(t_list *list);
void	ft_lst_sort(t_list **list);

void	ft_rotate_pile(t_list **list);
void	ft_rotate_all(t_list **list1, t_list **list2);
void	ft_reverse_rotate_pile(t_list **list);
void	ft_reverse_rotate_all(t_list **list1, t_list **list2);
void	ft_swap_pile(t_list	**list);
void	ft_swap_all(t_list **list1, t_list **list2);
void	ft_push_p_to_p(t_list **listsrc, t_list **listdest);
int		ft_before_waste_in_b(t_list **list_a);
int		ft_ct(t_list **la, int s, void (ft)(t_list **la, t_list **lb, int s));
void	ft_transfert_test(t_list **list_a, t_list **list_b, int size);
void	ft_t1(t_list **list_a, t_list **list_b, int size);
void	ft_t2(t_list **list_a, t_list **list_b, int size);
int		ft_next_of_me(int me, t_list *list);
int		ft_how_to_go_to(int nb, t_list *list);
int		ft_len_split(char **split);
void	ft_last_push(t_list **list_a, t_list **list_b);
void	ft_go_to_min(t_list **list_a);
void	ft_three_or_less_pile(t_list **list_a);
void	ft_sort_little_pile(t_list **list_a, t_list **list_b);
void	*ft_copie_nb(void *nb);

void	ft_free_strtab(char **strtab);
void	ft_sort_for_hero(t_list **list_a, t_list **list_b);
#endif