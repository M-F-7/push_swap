/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:28:12 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/16 22:46:43 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack_node *stack1, t_stack_node *stack2)
{
	get_index(stack1);
	get_index(stack2);
	find_cheapest(stack2);
	nodes_costs(stack1, stack2);
	set_target_node(stack1, stack2);
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
	t_stack_node *cheap;

	cheap = stack;
	while (stack)
	{
		stack->cheapest = false;
		if (stack->cost < cheap->cost)
			cheap = stack;
		stack = stack->next;
	}
	if (cheap)
		cheap->cheapest = true;
}



// void	set_target_node(t_stack_node *stack1, t_stack_node *stack2)
// {
// 	t_stack_node	*curr_node;
// 	t_stack_node	*target_node;
// 	int				min_max;

// 	target_node = NULL;
// 	curr_node = stack1;
// 	min_max = curr_node->content;
// 	while (stack2)
// 	{
// 		while (stack1)
// 		{
// 			if (curr_node->content < target_node->content
// 				&& target_node->content < min_max)
// 			{
// 				target_node = curr_node;
// 				min_max = curr_node->content;
// 			}
// 			curr_node = curr_node->next;
// 		}
// 		if (!target_node)
// 			stack2->target_node = find_little(stack1);
// 		else
// 			stack2->target_node = target_node;
// 		stack2 = stack2->next;
// 	}
// }


// void	nodes_costs(t_stack_node *stack1, t_stack_node *stack2)
// {
// 	while (stack2)
// 	{
// 		stack2->cost = stack2->index;
// 		if (!(stack2->above_median))
// 			stack2->cost = ft_stacksize(stack2) - stack2->index;
// 		if (stack2->target_node->above_median)
// 			stack2->cost += stack2->target_node->index;
// 		else
// 			stack2->cost += ft_stacksize(stack1) - stack2->target_node->index;
// 		stack2 = stack2->next;
// 	}
// }



// Corrigé : set_target_node
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
		best_diff = 2147483647; // INT_MAX
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

void	nodes_costs(t_stack_node *stack_a, t_stack_node *stack_b)
{
    int	size_a = ft_stacksize(stack_a);
    int	size_b = ft_stacksize(stack_b);

    while (stack_b)
    {
        if (stack_b->index <= size_b / 2)
            stack_b->cost_b = stack_b->index;
        else
            stack_b->cost_b = -(size_b - stack_b->index);
        if (stack_b->target_node->index <= size_a / 2)
            stack_b->cost_a = stack_b->target_node->index;
        else
            stack_b->cost_a = -(size_a - stack_b->target_node->index);

        stack_b = stack_b->next;
    }
}