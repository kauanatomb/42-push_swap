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

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack *a)
{
	t_node	*current;
	t_node	*tmp;

	current = a->head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(a);
}

int	append_to_stack(t_stack *a, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	new->prev = a->tail;
	if (a->size == 0)
		a->head = new;
	else
		a->tail->next = new;
	a->tail = new;
	a->size++;
	return (1);
}

void	free_split(char **tokens, int n)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i] && (n == -1 || i < n))
		free(tokens[i++]);
	free(tokens);
}

void	print_stack(t_stack *a)
{
	t_node	*current;

	current = a->head;
	while (current)
	{
		ft_printf("value: %d\n", current->value);
		current = current->next;
	}
}
