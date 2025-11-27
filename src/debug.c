/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 05:14:51 by mfernand          #+#    #+#             */
/*   Updated: 2025/11/27 05:32:57 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack_node **stack)
{
	t_stack_node	*node;

	node = *stack;
	while (node)
	{
		fprintf(stderr, "%d", node->value);
		if (node->next)
			fprintf(stderr, " ");
		node = node->next;
	}
	fprintf(stderr, "\n");
}

void	check_sorted(t_stack_node **stack)
{
	if (is_sorted(*stack))
		printf("🟩\n");
	else
		printf("❌\n");
}

void	print_index(t_stack_node **a)
{
	t_stack_node	*node;

	node = *a;
	while (node)
	{
		printf("INDEX : %d, VALUE : %d\n", node->index, node->value);
		node = node->next;
	}
}
