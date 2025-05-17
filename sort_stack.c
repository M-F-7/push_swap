/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:25:47 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/17 18:09:33 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include "push_swap.h"

void	ft_sort_stack(t_stack_node **stack1, t_stack_node **stack2)
{
	int	size;

	size = ft_stacksize((*stack1));
	while (size-- > 3)
		pb(stack1, stack2);
	sort_three((stack1));
	push_back_to_a(stack1, stack2);
	// if (is_sorted((*stack1)) == 1)
	put_min_top_stack((stack1));
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
	if (is_sorted((*stack1)) == 1)
		put_min_top_stack(stack1);
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

void	move_cheapest(t_stack_node **stack1, t_stack_node **stack2,
t_stack_node *cheapest)
{
    int	cost_a = cheapest->cost_a;
    int	cost_b = cheapest->cost_b;

    // Rotations combinées
    while (cost_a > 0 && cost_b > 0)
    {
        rr(stack1, stack2);
        cost_a--;
        cost_b--;
    }
    while (cost_a < 0 && cost_b < 0)
    {
        rrr(stack1, stack2);
        cost_a++;
        cost_b++;
    }
    while (cost_a > 0)
    {
        ra(stack1);
        cost_a--;
    }
    while (cost_a < 0)
    {
        rra(stack1);
        cost_a++;
    }
    while (cost_b > 0)
    {
        rb(stack2);
        cost_b--;
    }
    while (cost_b < 0)
    {
        rrb(stack2);
        cost_b++;
    }
    pa(stack1, stack2);
}
