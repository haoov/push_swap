/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:16:19 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/19 11:14:27 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (cleanup(list, NULL), NULL);
		list = add_front(&list, elem);
		if (list->next != list)
			list->rank = list->next->rank + 1;
		argc--;
	}
	return (list);
}
