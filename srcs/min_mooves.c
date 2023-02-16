/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_mooves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabbah <rsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:57:45 by rsabbah           #+#    #+#             */
/*   Updated: 2023/01/18 10:57:56 by rsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sum_mvnb(int mvnb_a, int size_a, int mvnb_b, int size_b)
{
	if (mvnb_a > size_a / 2 && mvnb_b > size_b / 2)
	{
		mvnb_a = size_a - mvnb_a;
		mvnb_b = size_b - mvnb_b;
	}
	if (mvnb_a <= size_a / 2 && mvnb_b <= size_b / 2)
	{
		if (mvnb_a >= mvnb_b)
			return (mvnb_a);
		else
			return (mvnb_b);
	}
	else if (mvnb_a > size_a / 2)
		mvnb_a = size_a - mvnb_a;
	else if (mvnb_b > size_b / 2)
		mvnb_b = size_b - mvnb_b;
	return (mvnb_a + mvnb_b);
}

int	total_mvnb(t_pile *elem, t_pile *pb, t_pile *pa)
{
	int	mvnb_b;
	int	mvnb_a;
	int	size_a;
	int	size_b;
	int	sum;

	mvnb_b = 0;
	mvnb_a = 0;
	size_a = list_size(pa);
	size_b = list_size(pb);
	while (pb != elem)
	{
		pb = pb->next;
		mvnb_b++;
	}
	while (insert_ok(pa, elem) == EXIT_FAILURE)
	{
		pa = pa->next;
		mvnb_a++;
	}
	sum = sum_mvnb(mvnb_a, size_a, mvnb_b, size_b);
	return (sum);
}

t_pile	*min_mooves(t_pile *pb, t_pile *pa, int range)
{
	t_pile			*elem;
	t_pile			*target;
	unsigned int	mnb;
	unsigned int	min;

	mnb = UINT_MAX;
	target = pb;
	elem = pb->next;
	if (pb->range == range)
		mnb = total_mvnb(pb, pb, pa);
	min = mnb;
	while (elem != pb)
	{
		if (elem->range == range)
			mnb = total_mvnb(elem, pb, pa);
		if (mnb < min)
		{
			min = mnb;
			target = elem;
		}		
		elem = elem->next;
	}
	return (target);
}
