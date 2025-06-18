/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/11 10:40:02 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap_top(t_stack *s)
{
    int     tmp_value;

    if (!s || s->size < 2)
        return ;
    tmp_value = s->head->value;
    s->head->value = s->head->next->value;
    s->head->next->value = tmp_value;
}

void    op_sa(t_stack *a)
{
    stack_swap_top(a);
    ft_printf("sa\n");
}

void    op_sb(t_stack *b)
{
    stack_swap_top(b);
    ft_printf("sb\n");
}

static void stack_push(t_stack *from, t_stack *to)
{
    t_node  *top;

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

void    op_pb(t_stack *a, t_stack *b)
{
    stack_push(a, b);
    ft_printf("pb\n");
}

void    op_pa(t_stack *a, t_stack *b)
{
    stack_push(b, a);
    ft_printf("pa\n");
}
