/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:25:47 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/17 20:34:58 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack_node **stack1, t_stack_node **stack2)
{

	push_initial(stack1, stack2);
	sort_three((stack1));
	push_back_to_a(stack1, stack2);
	// if (is_sorted((*stack1)) == 1)
	put_min_top_stack((stack1));
}
void	push_initial(t_stack_node **a, t_stack_node **b)
{
    int	size = ft_stacksize(*a);
    int	chunk = 0;
    //int	chunk_size = size / 8 + 10; // Ajuste ce facteur pour 100 ou 500

    while (ft_stacksize(*a) > 3)
    {
        if ((*a)->content <= chunk || (*a)->content >= size - chunk)
        {
            pb(a, b);
            if ((*b)->content >= size - chunk)
                rb(b); // Place les grands en bas de B
            chunk++;
        }
        else
            ra(a);
    }
}


int	get_min_pos(t_stack_node *a)
{
    int min = a->content;
    int i = 0, min_pos = 0;
    t_stack_node *tmp = a;
    while (tmp)
    {
        if (tmp->content < min)
        {
            min = tmp->content;
            min_pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (min_pos);
}

int	get_max_pos(t_stack_node *a)
{
    int max = a->content;
    int i = 0, max_pos = 0;
    t_stack_node *tmp = a;
    while (tmp)
    {
        if (tmp->content > max)
        {
            max = tmp->content;
            max_pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (max_pos);
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
void	move_cheapest(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    int	cost_a = cheapest->cost_a;
    int	cost_b = cheapest->cost_b;

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