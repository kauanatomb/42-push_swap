/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/21 17:15:19 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_values(t_stack *a)
{
	int		*arr;
	t_node	*current;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	current = a->head;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}

static void	sort_int_array(int *arr, int size)
{
	int	i;
	int	tmp;
	int	swapped;

	if (!arr || size < 2)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

static void	assign_ranks(t_stack *a, int *arr, int size)
{
	t_node	*tmp;
	int		i;

	tmp = a->head;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == arr[i])
			{
				tmp->rank = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static void	radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		i;
	int		j;
	int		size;

	size = a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->head->rank >> i) & 1) == 0)
				op_pb(a, b);
			else
				op_ra(a);
			j++;
		}
		while (b->size > 0)
			op_pa(a, b);
		i++;
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	int		*arr;

	arr = copy_values(a);
	if (!arr)
		return ;
	sort_int_array(arr, a->size);
	assign_ranks(a, arr, a->size);
	free(arr);
	radix_sort(a, b);
}
