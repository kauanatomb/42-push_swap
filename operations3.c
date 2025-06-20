/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/18 11:33:36 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_stack *a)
{
	stack_rotate_down(a);
	update_stack_indices(a);
	ft_printf("rra\n");
}

void	op_rrb(t_stack *b)
{
	stack_rotate_down(b);
	update_stack_indices(b);
	ft_printf("rrb\n");
}

void	op_ss(t_stack *a, t_stack *b)
{
	stack_swap_top(a);
	stack_swap_top(b);
	update_stack_indices(a);
	update_stack_indices(b);
	ft_printf("ss\n");
}

void	op_rr(t_stack *a, t_stack *b)
{
	stack_rotate_up(a);
	stack_rotate_up(b);
	update_stack_indices(a);
	update_stack_indices(b);
	ft_printf("rr\n");
}

void	op_rrr(t_stack *a, t_stack *b)
{
	stack_rotate_down(a);
	stack_rotate_down(b);
	update_stack_indices(a);
	update_stack_indices(b);
	ft_printf("rrr\n");
}
