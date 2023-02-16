/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:58:05 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:58:06 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	push(t_pile **pile_from, t_pile **pile_to)
{
	t_pile	*elem;

	elem = *pile_from;
	if (elem->next == elem)
		*pile_from = NULL;
	else
		*pile_from = elem->next;
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	elem->next = elem;
	elem->prev = elem;
	add_front(pile_to, elem);
	return (PUSH);
}

t_cmd	swap(t_pile **pile)
{
	int	v_mem;
	int	r_mem;

	v_mem = (*pile)->value;
	r_mem = (*pile)->rank;
	(*pile)->value = (*pile)->next->value;
	(*pile)->next->value = v_mem;
	(*pile)->rank = (*pile)->next->rank;
	(*pile)->next->rank = r_mem;
	return (SWAP);
}

t_cmd	rotate(t_pile **pile)
{
	*pile = (*pile)->next;
	return (ROTATE);
}

t_cmd	rev_rotate(t_pile **pile)
{
	*pile = (*pile)->prev;
	return (REV_ROTATE);
}
