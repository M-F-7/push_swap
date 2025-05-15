/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:22:31 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/15 22:23:21 by mfernand         ###   ########.fr       */
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

void	ft_swap_stack(t_stack_node *a, t_stack_node *b)
{
	int	tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

t_stack_node	*find_lastnode_stack(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_stack_add_front(t_stack_node **lst, t_stack_node *new)
{
	new->next = *lst;
	*lst = new;
}
