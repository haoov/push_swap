/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:59:13 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/19 11:16:57 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_mlist	*new_moove(t_cmd cmd, char pile)
{
	t_mlist	*moove;

	moove = ft_calloc(1, sizeof (t_mlist));
	if (moove == NULL)
		return (NULL);
	moove->cmd = cmd;
	moove->pile = pile;
	moove->next = NULL;
	return (moove);
}

static t_mlist	*last_moove(t_mlist *mlist)
{
	if (mlist == NULL)
		return (NULL);
	if (mlist->next == NULL)
		return (mlist);
	return (last_moove(mlist->next));
}

void	add_moove(t_mlist *moove, t_mlist **mlist)
{
	t_mlist	*last;

	last = last_moove(*mlist);
	if (last == NULL)
		*mlist = moove;
	else
		last->next = moove;
}

int	store(t_cmd cmd, char pile, t_mlist **mlist)
{
	t_mlist	*moove;

	if (mlist == NULL)
		return (EXIT_FAILURE);
	moove = new_moove(cmd, pile);
	if (moove == NULL)
		return (EXIT_FAILURE);
	add_moove(moove, mlist);
	return (EXIT_SUCCESS);
}
