/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:57:49 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/12 14:26:59 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stddef.h>
# include <limits.h>

# define ERR_MSG "Error\n"

typedef struct s_pile
{
	int				value;
	int				rank;
	int				range;
	struct s_pile	*prev;
	struct s_pile	*next;
}t_pile;

typedef enum e_cmd
{
	SWAP,
	ROTATE,
	REV_ROTATE,
	PUSH
}t_cmd;

typedef struct s_mlist
{
	t_cmd			cmd;
	char			pile;
	struct s_mlist	*next;
}t_mlist;

int		main(int argc, char **argv);
int		check_args(int argc, char **argv);
int		list_size(t_pile *list);
int		sort_check(t_pile *pile);
int		insert_ok(t_pile *pa, t_pile *sup);
int		store(t_cmd cmd, char pile, t_mlist **mlist);
int		sort(t_pile **pa, t_pile **pb, t_mlist **mlist);
int		quick_sort(t_pile **pa, t_pile **pb, t_mlist **mlist);
int		insert_sort(t_pile **pa, t_pile **pb, t_mlist **mlist);
int		smart_rotate(t_pile **pa, t_mlist **mlist);
t_pile	*parse(int argc, char **argv);
t_pile	*add_front(t_pile **list, t_pile *elem);
t_pile	*min_mooves(t_pile *pb, t_pile *pa, int range);
void	sort_rank(t_pile *list, int size);
void	print_mlist(t_mlist *mlist);
void	print_cmd(t_cmd cmd, char pile);
void	cleanup(t_pile *pa, t_mlist *mlist);
t_cmd	swap(t_pile **pile);
t_cmd	rotate(t_pile **pile);
t_cmd	rev_rotate(t_pile **pile);
t_cmd	push(t_pile **pile_from, t_pile **pile_to);
t_cmd	best_moove(t_pile **p);

#endif