/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:56:40 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:56:44 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	up_range(t_pile *pb)
{
	int		range;
	t_pile	*next;

	range = pb->range;
	next = pb->next;
	while (next != pb)
	{
		if (next->range > range)
			range = next->range;
		next = next->next;
	}
	return (range);
}

int	insert_ok(t_pile *pa, t_pile *sup)
{
	t_pile	*prev;

	prev = pa->prev;
	if ((prev->rank > sup->rank && prev->rank < pa->rank)
		|| pa->rank < sup->rank)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

static t_cmd	moove_a(t_pile **pa, t_pile *elem)
{
	t_pile	*prev;

	prev = (*pa)->prev;
	if (prev->rank < (*pa)->rank && prev->rank > elem->rank)
		return (rev_rotate(pa));
	else
		return (rotate(pa));
}

static t_cmd	moove_b(t_pile **pb, t_pile *elem)
{
	t_pile	*cur;
	int		pb_size;
	int		mnb;

	mnb = 0;
	cur = *pb;
	pb_size = list_size(*pb);
	while (cur != elem)
	{
		mnb++;
		cur = cur->next;
	}
	if (mnb > pb_size / 2)
		return (rev_rotate(pb));
	else
		return (rotate(pb));
}

int	insert_sort(t_pile **pa, t_pile **pb, t_mlist **mlist)
{
	t_pile	*elem;
	int		range;

	while (*pb != NULL)
	{
		range = up_range(*pb);
		elem = min_mooves(*pb, *pa, range);
		while (*pb != elem || insert_ok(*pa, elem) == EXIT_FAILURE)
		{
			if (*pb != elem)
				if (store(moove_b(pb, elem), 'b', mlist) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			if (insert_ok(*pa, elem) == EXIT_FAILURE)
				if (store(moove_a(pa, elem), 'a', mlist) == EXIT_FAILURE)
					return (EXIT_FAILURE);
		}
		if (store(push(pb, pa), 'a', mlist) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (smart_rotate(pa, mlist) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
