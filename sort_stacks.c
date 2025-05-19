/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:19:32 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/19 20:58:59 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	sort_before_push(a, cheapest_node, 'a');
	sort_before_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	sort_before_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
