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

    if (argc < 2)
        return (0);
    a = init_stack();
    if (!parse_args_into_stack(a, argc, argv))
    {
        ft_putstr_fd("Error parsing\n", 2);
        free_stack(a);
        return (1);
    }
    print_stack(a);
    free_stack(a);
    return (0);
}
