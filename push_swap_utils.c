/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:39:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/18 12:10:52 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**split_args(int argc, char **argv)
{
	char	**tokens;
	int		i;
	int		j;

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

static int	is_valid_integer(const char *str)
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

static int	ft_atoi_safe(const char *str, int *out)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > (long)INT_MAX + 1))
			return (0);
		str++;
	}
	*out = (int)(sign * result);
	return (1);
}

static int	has_duplicate(t_stack *a, int value)
{
	t_node	*current;

	current = a->head;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	parse_args_into_stack(t_stack *a, int argc, char **argv)
{
	char	**tokens;
	int		i;
	int		value;

	tokens = split_args(argc, argv);
	if (!tokens || !tokens[0])
		return (free_split(tokens, -1), ft_putstr_fd("Error\n", 2), 1);
	i = 0;
	value = 0;
	while (tokens[i])
	{
		if (!is_valid_integer(tokens[i]))
			return (free_split(tokens, -1), ft_putstr_fd("Invalid int\n", 2), 1);
		if (!ft_atoi_safe(tokens[i], &value))
			return (free_split(tokens, -1), ft_putstr_fd("Error atoi\n", 2), 1);
		if (has_duplicate(a, value))
			return (free_split(tokens, -1), ft_putstr_fd("Duplicated\n", 2), 1);
		if (!append_to_stack(a, value))
			return (free_split(tokens, -1), ft_putstr_fd("Append\n", 2), 1);
		i++;
	}
	free_split(tokens, i);
	return (0);
}
