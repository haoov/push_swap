/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:57:21 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:57:22 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*add_front(t_pile **list, t_pile *elem)
{
	if (!list)
		return (NULL);
	if (*list != NULL)
	{
		elem->next = *list;
		elem->prev = (*list)->prev;
		elem->next->prev = elem;
		elem->prev->next = elem;
	}
	*list = elem;
	return (*list);
}

int	list_size(t_pile *list)
{
	int		size;
	t_pile	*elem;

	size = 1;
	if (list == NULL)
		return (0);
	elem = list->next;
	while (elem != list)
	{
		size++;
		elem = elem->next;
	}
	return (size);
}
