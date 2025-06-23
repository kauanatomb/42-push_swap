/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/21 17:12:13 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*curr;

	curr = a->head;
	while (curr && curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		sort_big(a, b);
}

void	sort_2(t_stack *a)
{
	if (a->head->value > a->head->next->value)
		op_sa(a);
}

void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->head->value;
	y = a->head->next->value;
	z = a->tail->value;
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

t_node	*get_index_of_min(t_stack *a)
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

void	push_smallest_to_b(t_stack *a, t_stack *b)
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

void	update_stack_indices(t_stack *s)
{
	t_node	*current;
	int		idx;

	idx = 0;
	current = s->head;
	while (current)
	{
		current->index = idx++;
		current = current->next;
	}
}
