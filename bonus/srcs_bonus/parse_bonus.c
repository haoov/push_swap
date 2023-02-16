/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:37 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 11:12:38 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_pile	*new_elem(int value)
{
	t_pile	*elem;

	elem = ft_calloc(1, sizeof(t_pile));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->rank = 1;
	elem->range = 0;
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}

t_pile	*parse(int argc, char **argv)
{
	t_pile	*list;
	t_pile	*elem;

	list = NULL;
	while (argc > 0)
	{
		elem = new_elem(ft_atoi(argv[argc - 1]));
		if (!elem)
			return (free_pile(list), NULL);
		list = add_front(&list, elem);
		if (list->next != list)
			list->rank = list->next->rank + 1;
		argc--;
	}
	return (list);
}
