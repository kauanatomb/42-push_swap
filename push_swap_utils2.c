/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/18 12:10:52 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	// else
	// 	sort_big(a, b); // etapa futura
}

void    sort_2(t_stack *a)
{
    if (a->head->value > a->head->next->value)
        op_sa(a);
}

void	sort_3(t_stack *a)
{
	int x = a->head->value;
	int y = a->head->next->value;
	int z = a->tail->value;

	if (x < y && y > z && x > z)
		op_rra(a);
	else if (x > y && y > z)
	{
		op_sa(a);
		op_rra(a);
	}
	else if (x > y && y < z && x < z)
		op_sa(a);
	else if (x < y && y > z && x < z)
	{
		op_sa(a);
		op_ra(a);
	}
	else if (x > y && y < z && x > z)
		op_ra(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	t_node	*min;
	t_node	*tmp;
	int		idx;

	min = a->head;
	tmp = a->head;
	idx = min->index;
	while (tmp)
	{
		if (min->value > tmp->value)
		{
			min = tmp;
			idx = tmp->index;
		}
		tmp = tmp->next;
	}
	while (a->head->value != min->value)
	{
		if (idx < a->size - idx)
			op_ra(a);
		else
			op_rra(a);
	}
	op_pb(a, b);
	sort_3(a);
	op_pa(a, b);
}

void update_stack_indices(t_stack *s)
{
    t_node *current = s->head;
    int idx = 0;

    while (current)
    {
        current->index = idx++;
        current = current->next;
    }
}
