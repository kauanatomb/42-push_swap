/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/21 17:19:04 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				rank;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

t_stack	*init_stack(void);
int		parse_args_into_stack(t_stack *a, int argc, char **argv);
int		append_to_stack(t_stack *a, int value);
void	free_split(char **tokens, int n);

//generic
void	stack_swap_top(t_stack *s);
void	stack_push(t_stack *from, t_stack *to);
void	stack_rotate_up(t_stack *s);
void	stack_rotate_down(t_stack *s);

//op
void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_pa(t_stack *a, t_stack *b);
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	update_stack_indices(t_stack *s);

//push swap
void	push_swap(t_stack *a, t_stack *b);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);
void	push_chunks(t_stack *a, t_stack *b, int chunk_size);
void	sort_back_to_a(t_stack *a, t_stack *b);

void	print_stack(t_stack *a);
void	free_stack(t_stack *a);

#endif
