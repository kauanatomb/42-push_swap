/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/21 17:15:19 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_rank(t_stack *s)
{
	t_node	*cur;
	int		max;

	cur = s->head;
	max = cur->rank;
	while (cur)
	{
		if (cur->rank > max)
			max = cur->rank;
		cur = cur->next;
	}
	return (max);
}

int	find_position_of_rank(t_stack *s, int target)
{
	t_node	*cur;
	int		pos;

	cur = s->head;
	pos = 0;
	while (cur)
	{
		if (cur->rank == target)
			return (pos);
		pos++;
		cur = cur->next;
	}
	return (-1);
}

static void	push_chunk_range(t_stack *a, t_stack *b,
	int chunk_start, int chunk_size)
{
	int	pushed;
	int	total;
	int	rank;

	pushed = 0;
	total = a->size;
	while (pushed < chunk_size && total > 0)
	{
		rank = a->head->rank;
		if (rank >= chunk_start && rank < chunk_start + chunk_size)
		{
			op_pb(a, b);
			pushed++;
			if (rank < chunk_start + (chunk_size / 2))
				op_rb(b);
		}
		else
			op_ra(a);
		total--;
	}
}

void	push_chunks(t_stack *a, t_stack *b, int chunk_size)
{
	int	size;
	int	chunk_start;

	size = a->size;
	chunk_start = 0;
	while (chunk_start < size)
	{
		push_chunk_range(a, b, chunk_start, chunk_size);
		chunk_start += chunk_size;
	}
}

void	sort_back_to_a(t_stack *a, t_stack *b)
{
	int		max;
	int		pos;

	while (b->size > 0)
	{
		max = find_max_rank(b);
		pos = find_position_of_rank(b, max);
		if (pos <= b->size / 2)
		{
			while (b->head->rank != max)
				op_rb(b);
		}
		else
		{
			while (b->head->rank != max)
				op_rrb(b);
		}
		op_pa(a, b);
	}
}
