/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:22:31 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/16 15:56:31 by mfernand         ###   ########.fr       */
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


void	put_min_top_stack(t_stack_node *stack)
{
	t_stack_node	*min;

	min = NULL;
	min -> content = stack -> content;
	while (stack->next)
	{
		if (stack -> content < min -> content)
				min -> content = stack -> content;
		stack = stack->next;
	}
	ft_stack_add_front(&stack, min);
}

int	is_sorted(t_stack_node *stack)
{
	while(stack -> next)
	{
		if (stack -> content > stack -> next -> content)
			return (0);
		stack = stack -> next;
	}
	return (1);
}