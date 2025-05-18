/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:26:27 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/18 15:17:04 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_stack_node **stack, int value)
{
	t_stack_node	*curr;

	curr = *stack;
	while (curr)
	{
		if (value == curr->content)
		{
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}

int	check_error(t_stack_node **stack, int value)
{
	if (!(value > INT_MIN && value < INT_MAX))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!check_double(stack, value))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_big(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}
