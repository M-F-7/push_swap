/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:21:38 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/21 12:19:16 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*s == 32) || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->previous = last_node;
	}
}

// void	init_stack_a(t_stack_node **a, char **av)
// {
// 	long	n;
// 	int		i;

// 	i = 0;
// 	while (av[i])
// 	{
// 		if (error_syntax(av[i]))
// 			free_errors(a, av);
// 		n = ft_atol(av[i]);
// 		if (n > INT_MAX || n < INT_MIN)
// 			free_errors(a, av);	
// 		if (error_duplicate(*a, (int)n))
// 			free_errors(a, av);	
// 		append_node(a, (int)n);
// 		i++;
// 	}
// }

void	init_stack_a(t_stack_node **a, char **av, int should_free)
{
    long	n;
    int		i;

    i = 0;
    while (av[i])
    {
        if (error_syntax(av[i]))
            free_errors(a, av, should_free);
        n = ft_atol(av[i]);
        if (n > INT_MAX || n < INT_MIN)
            free_errors(a, av, should_free);	
        if (error_duplicate(*a, (int)n))
            free_errors(a, av, should_free);	
        append_node(a, (int)n);
        i++;
    }
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	sort_before_push(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
