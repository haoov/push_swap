/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:30 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/24 11:08:05 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_cmd	push(t_pile **pile_from, t_pile **pile_to)
{
	t_pile	*elem;

	if (pile_from == NULL || *pile_from == NULL)
		return (PUSH);
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

	if (pile == NULL || *pile == NULL)
		return (SWAP);
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
	if (pile == NULL || *pile == NULL)
		return (ROTATE);
	*pile = (*pile)->next;
	return (ROTATE);
}

t_cmd	rev_rotate(t_pile **pile)
{
	if (pile == NULL || *pile == NULL)
		return (REV_ROTATE);
	*pile = (*pile)->prev;
	return (REV_ROTATE);
}
