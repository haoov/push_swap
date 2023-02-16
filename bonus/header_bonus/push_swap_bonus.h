/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:59:44 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/19 10:53:35 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
	PUSH,
	INVALID_CMD
}t_cmd;

int		main(int argc, char **argv);
int		check_args(int argc, char **argv);
int		list_size(t_pile *list);
int		sort_check(t_pile *pile);
int		execute(t_pile **pa, t_pile **pb);
int		do_same(t_pile **pa, t_pile **pb, t_cmd cmd);
int		error(void);
t_pile	*parse(int argc, char **argv);
t_pile	*add_front(t_pile **list, t_pile *elem);
t_pile	*parse(int argc, char **argv);
t_cmd	swap(t_pile **pile);
t_cmd	rotate(t_pile **pile);
t_cmd	rev_rotate(t_pile **pile);
t_cmd	push(t_pile **pile_from, t_pile **pile_to);
void	free_pile(t_pile *pa);

#endif