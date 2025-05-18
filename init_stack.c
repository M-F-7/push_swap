/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:28:12 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/18 15:29:03 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack_node *a, t_stack_node *b)
{
	get_index(a);
	get_index(b);
	set_target_node(a, b);
	nodes_costs(a, b);
	find_cheapest(b);
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
	int				cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_a;
	t_stack_node	*best_target;
	int				best_diff;
	int				diff;

	while (b)
	{
		curr_a = a;
		best_diff = INT_MAX;
		while (curr_a)
		{
			diff = curr_a->content - b->content;
			if (diff > 0 && diff < best_diff)
			{
				best_diff = diff;
				best_target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (!best_target)
			b->target_node = find_little(a);
		else
			b->target_node = best_target;
		b = b->next;
	}
}

void	nodes_costs(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stacksize(a);
	len_b = ft_stacksize(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = len_a - (a->index);
		if (a->target_node)
		{
			if (a->target_node->above_median)
				a->cost += a->target_node->index;
			else
				a->cost += len_b - (a->target_node->index);
		}
		a = a->next;
	}
}
