/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.last                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:26:27 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/16 15:00:41 by mfernand         ###   ########.fr       */
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
	if (value > INT_MAX || value < INT_MIN)
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

void	sort_three(t_stack_node **stack)
{
	int				first;
	int				second;
	t_stack_node	*last_node;
	int				last;

	first = (*stack)->content;
	second = (*stack)->next->content;
	last_node = find_lastnode_stack((*stack));
	last = last_node->content;
	if (last == second)
	{
		if (second < first)
			sa(stack);
	}
	if (first < second && second < last)
		return ;
	if (first > second && second < last && first < last)
		sa(stack);
	else if (first > second && second > last)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < last && first > last)
		ra(stack);
	else if (first < second && second > last && first < last)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > last && first > last)
		rra(stack);
}
