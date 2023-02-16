/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:08 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/19 17:45:04 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_pile(t_pile *pa)
{
	t_pile	*next;
	int		size;

	size = list_size(pa);
	while (size)
	{
		next = pa->next;
		free(pa);
		pa = next;
		size--;
	}
}

int	error(void)
{
	write(2, ERR_MSG, ft_strlen(ERR_MSG));
	return (EXIT_FAILURE);
}

int	sort_check(t_pile *pile)
{
	t_pile	*elem;

	elem = pile;
	while (elem->next != pile)
	{
		if (elem->value > elem->next->value)
			return (EXIT_FAILURE);
		elem = elem->next;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_pile	*pa;
	t_pile	*pb;

	pb = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (check_args(argc - 1, argv + 1) == EXIT_FAILURE)
		return (error());
	pa = parse(argc - 1, argv + 1);
	if (pa == NULL)
		return (EXIT_FAILURE);
	if (execute(&pa, &pb) == EXIT_FAILURE)
		return (free_pile(pa), EXIT_FAILURE);
	if (sort_check(pa) == EXIT_FAILURE || pb != NULL)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_pile(pa);
	return (EXIT_SUCCESS);
}
