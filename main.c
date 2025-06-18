/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:32:28 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/11 10:32:32 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (ft_putstr_fd("Error args\n", 2), 0);
    a = init_stack();
    b = init_stack();
    if (parse_args_into_stack(a, argc, argv) != 0)
    {
        ft_putstr_fd("Error parsing\n", 2);
        free_stack(a);
        return (1);
    }
    op_rra(a);
    ft_printf("Stack A\n");
    print_stack(a);
    // ft_printf("Stack B\n");
    // print_stack(b);
    return (0);
}
