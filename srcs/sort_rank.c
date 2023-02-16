/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:58:37 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:58:38 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	*list_rank(t_pile *list, int rank)
{
	if (list == NULL)
		return (NULL);
	if (list->rank == rank)
		return (list);
	return (list_rank(list->next, rank));
}

static void	swap_rank(t_pile *elem1, t_pile *elem2)
{
	int	mem;

	mem = elem1->rank;
	elem1->rank = elem2->rank;
	elem2->rank = mem;
}

void	sort_rank(t_pile *list, int size)
{
	t_pile	*elem;
	t_pile	*cmp;
	int		i;
	int		j;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		elem = list_rank(list, i);
		while (j <= size)
		{
			cmp = list_rank(list, j);
			if (elem->value > cmp->value)
			{
				swap_rank(cmp, elem);
				elem = cmp;
			}
			j++;
		}
		i++;
	}
}
