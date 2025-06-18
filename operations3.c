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

void	op_ra(t_stack *a)
{
	stack_rotate_up(a);
	ft_printf("ra\n");
}

void	op_rb(t_stack *b)
{
	stack_rotate_up(b);
	ft_printf("rb\n");
}

void	op_rra(t_stack *a)
{
	stack_rotate_down(a);
	ft_printf("rra\n");
}

void	op_rrb(t_stack *b)
{
	stack_rotate_down(b);
	ft_printf("rrb\n");
}
