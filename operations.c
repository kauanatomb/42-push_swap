/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/18 11:51:45 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap_top(t_stack *s)
{
	int	tmp_value;

	if (!s || s->size < 2)
		return ;
	tmp_value = s->head->value;
	s->head->value = s->head->next->value;
	s->head->next->value = tmp_value;
}

void	stack_push(t_stack *from, t_stack *to)
{
	t_node	*top;

	if (!from || !to || from->size < 1)
		return ;
	top = from->head;
	from->head = top->next;
	if (from->head == NULL)
		from->tail = NULL;
	else
		from->head->prev = NULL;
	top->next = to->head;
	top->prev = NULL;
	if (to->head == NULL)
		to->tail = top;
	else
		to->head->prev = top;
	to->head = top;
	from->size--;
	to->size++;
}

void	stack_rotate_up(t_stack *s)
{
	t_node	*top;

	if (!s || s->size < 2)
		return ;
	top = s->head;
	s->head = top->next;
	s->head->prev = NULL;
	top->prev = s->tail;
	top->next = NULL;
	s->tail->next = top;
	s->tail = top;
}

void	stack_rotate_down(t_stack *s)
{
	t_node	*bottom;

	if (!s || s->size < 2)
		return ;
	bottom = s->tail;
	s->tail = bottom->prev;
	s->tail->next = NULL;
	bottom->next = s->head;
	bottom->prev = NULL;
	s->head->prev = bottom;
	s->head = bottom;
}

void	op_sa(t_stack *a)
{
	stack_swap_top(a);
	ft_printf("sa\n");
}
