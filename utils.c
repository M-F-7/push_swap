/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:22:31 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/18 15:45:19 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack_node	*find_lastnode_stack(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_little(t_stack_node *stack)
{
	t_stack_node	*little;

	little = stack;
	while (stack)
	{
		if (stack->content < little->content)
			little = stack;
		stack = stack->next;
	}
	return (little);
}

t_stack_node	*find_big(t_stack_node *stack)
{
	int				max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	put_min_top_stack(t_stack_node **stack)
{
	t_stack_node	*min;
	int				pos;

	get_index(*stack);
	min = find_little((*stack));
	pos = min->index;
	if (pos <= ft_stacksize((*stack)) / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		pos = ft_stacksize((*stack)) - pos;
		while (pos-- > 0)
			rra(stack);
	}
}

// void	ft_print_stack(t_stack_node **stack)
// {
// 	t_stack_node	*tmp;

// 	tmp = *stack;
// 	while (tmp)
// 	{
// 		ft_printf("%d ", tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_printf("\n");
// }