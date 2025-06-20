/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/18 11:32:22 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sb(t_stack *b)
{
	stack_swap_top(b);
	update_stack_indices(b);
	ft_printf("sb\n");
}

void	op_pb(t_stack *a, t_stack *b)
{
	stack_push(a, b);
	update_stack_indices(a);
	update_stack_indices(b);
	ft_printf("pb\n");
}

void	op_pa(t_stack *a, t_stack *b)
{
	stack_push(b, a);
	update_stack_indices(b);
	update_stack_indices(a);
	ft_printf("pa\n");
}

void	op_ra(t_stack *a)
{
	stack_rotate_up(a);
	update_stack_indices(a);
	ft_printf("ra\n");
}

void	op_rb(t_stack *b)
{
	stack_rotate_up(b);
	update_stack_indices(b);
	ft_printf("rb\n");
}
