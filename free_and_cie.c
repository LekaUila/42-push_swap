/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_cie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:31:10 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 12:41:00 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_strtab(char **strtab)
{
	int	i;

	i = 0;
	while (strtab[i])
	{
		free(strtab[i]);
		i++;
	}
	free(strtab);
}
