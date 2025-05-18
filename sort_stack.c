/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:25:47 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/17 21:39:30 by mfernand         ###   ########.fr       */
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
	int	size;
	int	chunk;

	size = ft_stacksize(*a);
	chunk = 0;
	while (ft_stacksize(*a) > 3)
	{
		if ((*a)->content <= chunk || (*a)->content >= size - chunk)
		{
			pb(a, b);
			if ((*b)->content >= size - chunk)
				rb(b);
			chunk++;
		}
		else
			ra(a);
	}
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
	int cost_a = cheapest->cost_a;
	int cost_b = cheapest->cost_b;

	// Rotations combinées
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}

	// Rotations individuelles
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}

	// Push l'élément dans A
	pa(a, b);
}