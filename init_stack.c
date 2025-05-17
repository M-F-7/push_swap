/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:28:12 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/17 20:42:04 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack_node *stack1, t_stack_node *stack2)
{
	get_index(stack1);
	get_index(stack2);
	set_target_node(stack1, stack2);
	nodes_costs(stack1, stack2);
	find_cheapest(stack2);
}

void	get_index(t_stack_node *stack)
{
	int	median;
	int	i;

	i = 0;
	median = ft_stacksize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	find_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheap;
	int				min_cost;
	int				current_cost;
	t_stack_node	*tmp;

	cheap = stack;
	min_cost = calculate_total_cost(stack->cost_a, stack->cost_b);
	while (stack)
	{
		current_cost = calculate_total_cost(stack->cost_a, stack->cost_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheap = stack;
		}
		stack = stack->next;
	}
	tmp = cheap;
	while (tmp)
	{
		tmp->cheapest = false;
		tmp = tmp->next;
	}
	if (cheap)
		cheap->cheapest = true;
}

void	set_target_node(t_stack_node *stack1, t_stack_node *stack2)
{
	t_stack_node	*curr_a;
	t_stack_node	*best_target;
	int				best_diff;
	int				diff;

	while (stack2)
	{
		curr_a = stack1;
		best_target = NULL;
		best_diff = 2147483647;
		while (curr_a)
		{
			diff = curr_a->content - stack2->content;
			if (diff > 0 && diff < best_diff)
			{
				best_diff = diff;
				best_target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (!best_target)
			stack2->target_node = find_little(stack1);
		else
			stack2->target_node = best_target;
		stack2 = stack2->next;
	}
}

void	nodes_costs(t_stack_node *stack1, t_stack_node *stack2)
{
	int	size_a;
	int	size_b;

	size_a = ft_stacksize(stack1);
	size_b = ft_stacksize(stack2);
	while (stack2)
	{
		if (stack2->index <= size_b / 2)
			stack2->cost_b = stack2->index;
		else
			stack2->cost_b = stack2->index - size_b;
		if (stack2->target_node->index <= size_a / 2)
			stack2->cost_a = stack2->target_node->index;
		else
			stack2->cost_a = stack2->target_node->index - size_a;
		stack2 = stack2->next;
	}
}
int	calculate_total_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else
	{
		if (cost_a < 0)
			cost_a = -cost_a;
		if (cost_b < 0)
			cost_b = -cost_b;
		return (cost_a + cost_b);
	}
}
