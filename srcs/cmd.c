/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:56:27 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:56:28 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(t_cmd cmd, char pile)
{
	if (pile == 'c')
	{
		if (cmd == SWAP)
			ft_printf("ss\n");
		else if (cmd == ROTATE)
			ft_printf("rr\n");
		else if (cmd == REV_ROTATE)
			ft_printf("rrr\n");
	}
	else if (cmd == PUSH)
		ft_printf("p%c\n", pile);
	else if (cmd == SWAP)
		ft_printf("s%c\n", pile);
	else if (cmd == ROTATE)
		ft_printf("r%c\n", pile);
	else if (cmd == REV_ROTATE)
		ft_printf("rr%c\n", pile);
}

void	print_mlist(t_mlist *mlist)
{
	t_mlist	*m;
	t_mlist	*n;

	m = mlist;
	while (m != NULL)
	{
		n = m->next;
		if (n != NULL && m->cmd == n->cmd && m->pile != n->pile)
		{
			print_cmd(m->cmd, 'c');
			m->next = n->next;
			m = n->next;
			free(n);
		}
		else
		{
			print_cmd(m->cmd, m->pile);
			m = n;
		}
	}
}
