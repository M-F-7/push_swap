/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.last                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:26:27 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/16 15:00:41 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_stack_node **tab, int last)
{
	t_stack_node	*curr;

	curr = *tab;
	while (curr)
	{
		if (last == curr->content)
		{
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}

int	check_error(t_stack_node **tab, int content)
{
	if (content > INT_MAX || content < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!check_double(tab, content))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}


void	ft_check_number(t_stack_node **stack)
{
    int first;
    int second;
    t_stack_node *last_node;
    int last;
    
    first = (*stack)->content;
    second = (*stack)->next->content;
    last_node = find_lastnode_stack((*stack));
    last = last_node -> content;
    if (last == second)
    {
        if (second < first)
            sa(stack);
    }
    if (first < second && second < last)
        return; 
    if (first > second && second < last && first < last)
        sa(stack);
    else if (first > second && second > last)
    {
        sa(stack);
        rra(stack);
    }
    else if (first > second && second < last && first > last)
        ra(stack);
    else if (first < second && second > last && first < last)
    {
        sa(stack);
        ra(stack);
    }
    else if (first < second && second > last && first > last)
        rra(stack);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*next;

	tmp = *stack;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*stack = NULL;
}

void	ft_print_stack(t_stack_node **stack)
{
	t_stack_node *tmp = *stack;
	while (tmp)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}