/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:27:54 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:57:37 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error(void)
{
	write(2, ERR_MSG, ft_strlen(ERR_MSG));
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_pile	*pa;
	t_pile	*pb;
	t_mlist	*mlist;

	pb = NULL;
	mlist = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (check_args(argc - 1, argv + 1) == EXIT_FAILURE)
		return (error());
	pa = parse(argc - 1, argv + 1);
	if (pa == NULL)
		return (EXIT_FAILURE);
	sort_rank(pa, argc - 1);
	if (sort_check(pa) == EXIT_FAILURE)
		if (sort(&pa, &pb, &mlist) == EXIT_FAILURE)
			return (cleanup(pa, mlist), EXIT_FAILURE);
	print_mlist(mlist);
	cleanup(pa, mlist);
	return (EXIT_SUCCESS);
}
