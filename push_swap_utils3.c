/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/21 17:15:19 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_index_of_min(t_stack *a)
{
	t_node	*min;
	t_node	*tmp;

	tmp = a->head;
	min = a->head;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

static void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	t_node	*min;

	min = get_index_of_min(a);
	while (a->head != min)
	{
		if (min->index < a->size / 2)
			op_ra(a);
		else
			op_rra(a);
	}
	op_pb(a, b);
}

void	sort_4(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	sort_3(a);
	op_pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	push_smallest_to_b(a, b);
	sort_3(a);
	if (b->head->value < b->head->next->value)
		op_sb(b);
	op_pa(a, b);
	op_pa(a, b);
}
