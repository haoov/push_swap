/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:55:54 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:56:00 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_pile *pa, t_mlist *mlist)
{
	t_pile	*p_next;
	t_mlist	*m_next;
	int		p_size;

	p_size = list_size(pa);
	while (p_size)
	{
		p_next = pa->next;
		free(pa);
		pa = p_next;
		p_size--;
	}
	while (mlist != NULL)
	{
		m_next = mlist->next;
		free(mlist);
		mlist = m_next;
	}
}
