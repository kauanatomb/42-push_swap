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

void    op_sa(t_stack *a)
{
    int     tmp_value;

    if (!a || a->size < 2)
        return ;
    tmp_value = a->head->value;
    a->head->value = a->head->next->value;
    a->head->next->value = tmp_value;
    ft_printf("sa\n");
}

void    op_pb(t_stack *a, t_stack *b)
{
    t_node  *top;

    if (!a || !b || a->size < 1)
        return ;
    top = a->head;
    a->head = top->next;
    if (a->head == NULL)
        a->tail = NULL;
    else
        a->head->prev = NULL;
    top->next = b->head;
    top->prev = NULL;
    if (b->head == NULL)
        b->tail = top;
    else
        b->head->prev = top;
    b->head = top;
    a->size--;
    b->size++;
    ft_printf("pb\n");
}

void    op_pa(t_stack *a, t_stack *b)
{
    t_node  *top;

    if (!a || !b || b->size < 1)
        return ;
    top = b->head;
    b->head = top->next;
    if (b->head == NULL)
        b->tail = NULL;
    else
        b->head->prev = NULL;
    top->next = a->head;
    top->prev = NULL;
    if (a->size < 1)
        a->tail = top;
    else
        a->head->prev = top;
    a->head = top;
    a->size++;
    b->size--;
    ft_printf("pa\n");
}

void    op_ra(t_stack *a)
{
    t_node  *top;

    if (!a || a->size < 2)
        return ;
    top = a->head;
    a->head = top->next;
    a->head->prev = NULL;
    top->prev = a->tail;
    top->next = NULL;
    a->tail->next = top;
    a->tail = top;
    ft_printf("ra\n");
}