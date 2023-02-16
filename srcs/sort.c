/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:59:04 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:59:05 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_pile *pile)
{
	t_pile	*elem;

	elem = pile;
	while (elem->next != pile)
	{
		if (elem->value > elem->next->value)
			return (EXIT_FAILURE);
		elem = elem->next;
	}
	return (EXIT_SUCCESS);
}

int	sort_small(t_pile **pa, t_mlist **mlist)
{
	if (list_size(*pa) == 2)
	{
		if ((*pa)->rank > (*pa)->next->rank)
			if (store(swap(pa), 'a', mlist) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	}
	else
	{
		while (sort_check(*pa) == EXIT_FAILURE)
			if (store(best_moove(pa), 'a', mlist) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	sort_big(t_pile **pa, t_pile **pb, t_mlist **mlist)
{
	quick_sort(pa, pb, mlist);
	if (sort_check(*pa) == EXIT_FAILURE)
		if (sort_small(pa, mlist) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	if (insert_sort(pa, pb, mlist) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	sort(t_pile **pa, t_pile **pb, t_mlist **mlist)
{
	size_t	pa_size;

	pa_size = list_size(*pa);
	if (pa_size <= 3)
	{
		if (sort_small(pa, mlist) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (sort_big(pa, pb, mlist) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
