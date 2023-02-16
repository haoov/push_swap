/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:39:11 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 14:07:36 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	only_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	no_duplicate(char *value, char **argv, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (!ft_strcmp(value, argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static int	value_ok(char *str)
{
	long	value;
	long	max;
	int		i;

	value = 0;
	i = 0;
	max = INT_MAX;
	if (str[i] == '-')
	{
		i++;
		max = (long)INT_MIN * -1;
	}
	while (str[i])
	{
		value = 10 * value + str[i] - 48;
		i++;
	}
	if (value > max)
		return (0);
	else
		return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!only_digit(argv[i]) || !value_ok(argv[i])
			|| !no_duplicate(argv[i], argv + i, argc - i))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
