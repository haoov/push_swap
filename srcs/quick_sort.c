/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:58:21 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:58:22 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_rotate(t_pile **pa, t_pile **pb, int csize, t_mlist **mlist)
{
	static int		limit = 0;
	static int		i = 0;

	limit += 2 * csize;
	if (list_size(*pa) == 4)
		limit--;
	while (i < limit)
	{
		while ((*pa)->rank > limit)
			if (store(rotate(pa), 'a', mlist) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		(*pa)->range = limit;
		if (store(push(pa, pb), 'b', mlist) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (*pb != NULL && (*pb)->rank <= limit - csize)
		{
			(*pb)->range = limit - csize;
			if (((*pb)->next != (*pb)))
				if (store(rotate(pb), 'b', mlist) == EXIT_FAILURE)
					return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	quick_sort(t_pile **pa, t_pile **pb, t_mlist **mlist)
{
	int		pa_size;
	int		csize;
	int		cnb;

	pa_size = list_size(*pa);
	while (pa_size > 3)
	{
		cnb = 3;
		csize = pa_size / cnb;
		if (push_rotate(pa, pb, csize, mlist) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		pa_size = list_size(*pa);
	}
	return (EXIT_SUCCESS);
}
