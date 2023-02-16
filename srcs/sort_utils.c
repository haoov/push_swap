/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:58:48 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:58:49 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	best_moove(t_pile **p)
{
	if ((*p)->rank > (*p)->next->rank && (*p)->rank > (*p)->prev->rank)
		return (rotate(p));
	if ((*p)->rank > (*p)->next->rank && (*p)->rank < (*p)->prev->rank)
		return (swap(p));
	else
		return (rev_rotate(p));
}

int	smart_rotate(t_pile **pa, t_mlist **mlist)
{
	t_pile	*elem;
	int		mvnb;

	elem = *pa;
	mvnb = 0;
	while (elem->next != *pa)
	{
		if (elem->rank == 1)
			break ;
		elem = elem->next;
		mvnb++;
	}
	if (mvnb > list_size(*pa) / 2)
	{
		while (*pa != elem)
			if (store(rev_rotate(pa), 'a', mlist) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	}
	else if (mvnb != 0)
	{
		while (*pa != elem)
			if (store(rotate(pa), 'a', mlist) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
