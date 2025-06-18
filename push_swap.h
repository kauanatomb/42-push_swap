/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:21:12 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/11 10:21:22 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft.h"

typedef struct s_node {
    int             value;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

typedef struct s_stack {
    t_node *head;
    t_node *tail;
    int     size;
} t_stack;

t_stack *init_stack(void);
int parse_args_into_stack(t_stack *a, int argc, char **argv);
char **split_args(int argc, char **argv);
int is_valid_integer(const char *str);
int ft_atoi_safe(const char *str, int *out);
int has_duplicate(t_stack *a, int value);
int append_to_stack(t_stack *a, int value);
void free_split(char **tokens, int n);

//op
void    op_sa(t_stack *a);
void    op_pb(t_stack *a, t_stack *b);
void    op_pa(t_stack *a, t_stack *b);
void    op_ra(t_stack *a);

void print_stack(t_stack *a);
void free_stack(t_stack *a);

#endif