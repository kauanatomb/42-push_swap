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
	t_node	*cur = s->head;
	int		max = cur->rank;

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
	t_node	*cur = s->head;
	int		pos = 0;

	while (cur)
	{
		if (cur->rank == target)
			return (pos);
		pos++;
		cur = cur->next;
	}
	return (-1);
}

void	push_chunks(t_stack *a, t_stack *b, int chunk_size)
{
	int	chunk_start = 0;
	int	chunk_end;
	int	size = a->size;

	while (chunk_start < size)
	{
		chunk_end = chunk_start + chunk_size;
		int pushed = 0;
		int total = a->size;
		
		while (pushed < chunk_size && total > 0)
		{
			int rank = a->head->rank;
			if (rank >= chunk_start && rank < chunk_end)
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
		chunk_start += chunk_size;
	}
}

void	sort_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		int max = find_max_rank(b);
		int pos = find_position_of_rank(b, max);

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
