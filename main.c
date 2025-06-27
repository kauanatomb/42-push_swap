/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:32:28 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/18 11:53:48 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (parse_args_into_stack(a, argc, argv) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	update_stack_indices(a);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
