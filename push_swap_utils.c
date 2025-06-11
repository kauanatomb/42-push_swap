/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/11 10:40:02 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(void)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
    return (stack);
}

int parse_args_into_stack(t_stack *a, int argc, char **argv)
{
    char    **tokens;
    int     i;
    int     value;

    tokens = split_args(argc, argv);
    i = 0;
    value = 0;
    while (tokens[i])
    {
        if (!is_valid_integer(tokens[i]))
            return (ft_putstr_fd("Invalid integer\n", 2), 1);
        if (!ft_atoi_safe(tokens[i], &value))
            return (ft_putstr_fd("Error atoi\n", 2), 1);
        if (has_duplicate(a, value))
            return (ft_putstr_fd("Numbers duplicated in stack\n", 2), 1);
        append_to_stack(a, value);
        i++;
    }
    free_split(tokens);
    return (0);
}

char **split_args(int argc, char **argv)
{
    char    **tokens;
    int     i;
    int     j;

    if (argc == 2)
        return (ft_split(argv[1], ' '));
    i = 1;
    j = 0;
    if (argc > 2)
    {
        tokens = malloc(argc * sizeof(char *));
        if (!tokens)
            return (NULL);
        while (argv[i])
        {
            tokens[j] = ft_strdup(argv[i]);
            if (!tokens[j])
                return (free_split(tokens, j), NULL);
            j++;
            i++;
        }
        tokens[j] = NULL;
        return (tokens);
    }
    return (NULL);
}

int is_valid_integer(const char *str)
{
    if (!str || str[0] == '\0')
        return (0);
    if (*str == '-' || *str == '+')
    {
        str++;
        if (!*str)
            return (0);
    }
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (0);
        str++;
    }
    return (1);
}

int ft_atoi_safe(const char *str, int *out);
int has_duplicate(t_stack *a, int value);
int append_to_stack(t_stack *a, int value);

void free_split(char **tokens, int n)
{
    int i = 0;
    while (i < n)
        free(tokens[i++]);
    free(tokens);
}


void print_stack(t_stack *a)

void free_stack(t_stack *a)