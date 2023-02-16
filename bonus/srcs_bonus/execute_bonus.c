/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:00:27 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/19 11:31:09 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_cmd	get_cmd(char *moove)
{
	if (ft_strcmp(moove, "pa\n") == 0 || ft_strcmp(moove, "pb\n") == 0)
		return (PUSH);
	else if (ft_strcmp(moove, "sa\n") == 0 || ft_strcmp(moove, "sb\n") == 0
		|| ft_strcmp(moove, "ss\n") == 0)
		return (SWAP);
	else if (ft_strcmp(moove, "ra\n") == 0 || ft_strcmp(moove, "rb\n") == 0
		|| ft_strcmp(moove, "rr\n") == 0)
		return (ROTATE);
	else if (ft_strcmp(moove, "rra\n") == 0 || ft_strcmp(moove, "rrb\n") == 0
		|| ft_strcmp(moove, "rrr\n") == 0)
		return (REV_ROTATE);
	else
		return (INVALID_CMD);
}

char	get_pile(char *moove)
{
	if (ft_strchr(moove, 'a'))
		return ('a');
	else if (ft_strchr(moove, 'b'))
		return ('b');
	else
		return ('&');
}

int	do_cmd(t_cmd cmd, char pile, t_pile **pa, t_pile **pb)
{
	t_pile	**p;

	if (cmd == INVALID_CMD)
		return (EXIT_FAILURE);
	if (pile == 'a')
		p = pa;
	else if (pile == 'b')
		p = pb;
	else
		return (do_same(pa, pb, cmd));
	if (pile == 'a' && cmd == PUSH)
		push(pb, pa);
	else if (pile == 'b' && cmd == PUSH)
		push(pa, pb);
	else
	{
		if (cmd == SWAP)
			swap(p);
		else if (cmd == ROTATE)
			rotate(p);
		else
			rev_rotate(p);
	}
	return (EXIT_SUCCESS);
}

int	do_same(t_pile **pa, t_pile **pb, t_cmd cmd)
{
	if (cmd == INVALID_CMD)
		return (EXIT_FAILURE);
	else
	{
		if (do_cmd(cmd, 'a', pa, pb) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (do_cmd(cmd, 'b', pa, pb) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	execute(t_pile **pa, t_pile **pb)
{
	t_cmd	cmd;
	char	*moove;
	char	pile;
	char	buf[1];
	int		n;

	n = 1;
	while (n != 0)
	{
		moove = get_next_line(0);
		if (moove == NULL)
		{
			n = read(0, buf, 1);
			if (n == 0)
				break ;
			else
				return (EXIT_FAILURE);
		}
		cmd = get_cmd(moove);
		pile = get_pile(moove);
		if (do_cmd(cmd, pile, pa, pb) == EXIT_FAILURE)
			return (error());
		free(moove);
	}
	return (EXIT_SUCCESS);
}
