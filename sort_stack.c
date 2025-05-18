/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:25:47 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/19 01:12:25 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack_node **stack1, t_stack_node **stack2)
{
	push_initial(stack1, stack2);
	sort_three((stack1));
	push_back_to_a(stack1, stack2);
	put_min_top_stack((stack1));
}

void	push_initial(t_stack_node **a, t_stack_node **b)
{
	while (ft_stacksize(*a) > 3)
		pb(a, b);
}

void	push_back_to_a(t_stack_node **stack1, t_stack_node **stack2)
{
	t_stack_node	*node;

	while (*stack2)
	{
		init_stack(*stack1, *stack2);
		node = *stack2;
		while (node && !node->cheapest)
			node = node->next;
		if (node)
			move_cheapest(stack1, stack2, node);
	}
}

int	is_sorted(t_stack_node *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	move_cheapest(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	int	pos;
	int	safety;

	safety = 0;
	while (*b != cheapest && safety++ < ft_stacksize(*b) + 2)
	{
		get_index(*b);
		pos = cheapest->index;
		if (pos <= ft_stacksize(*b) / 2)
			rb(b);
		else
			rrb(b);
	}
	safety = 0;
	while (*a != cheapest->target_node && safety++ < ft_stacksize(*a) + 2)
	{
		get_index(*a);
		pos = cheapest->target_node->index;
		if (pos <= ft_stacksize(*a) / 2)
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}
