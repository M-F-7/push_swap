/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:18:15 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/17 20:41:57 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_front(t_stack_node **stack, t_stack_node *new_node)
{
	new_node->next = *stack;
	*stack = new_node;
}

void	ft_stack_add_back(t_stack_node **stack, t_stack_node *new_node)
{
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	while ((*stack)->next)
		stack = &(*stack)->next;
	(*stack)->next = new_node;
}

void	ft_stack_copy(t_stack_node **stack, char **str)
{
	t_stack_node	*curr;
	int				i;
	int				value;

	i = 0;
	while (str[++i])
	{
		if (!is_number(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack);
			return ;
		}
		value = ft_atoi(str[i]);
		if (!check_error(stack, value))
		{
			free_stack(stack);
			return ;
		}
		curr = malloc(sizeof(t_stack_node));
		if (!curr)
			return ;
		curr->content = value;
		curr->next = NULL;
		ft_stack_add_back(stack, curr);
	}
}

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node *tmp;
	t_stack_node *next;

	tmp = *stack;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*stack = NULL;
}