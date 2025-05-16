/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:32:42 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/16 22:30:25 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **stack)
{
	t_stack_node	*before_last;
	t_stack_node	*last;

	before_last = *stack;
	last = find_lastnode_stack(*stack);
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("rra\n");
}

void	rrb(t_stack_node **stack)
{
	t_stack_node	*before_last;
	t_stack_node	*last;

	before_last = *stack;
	last = find_lastnode_stack(*stack);
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack1, t_stack_node **stack2)
{
	rra(stack1);
	rrb(stack2);
	ft_printf("rrr\n");
}

// int main(void)
// {
//     t_stack_node *node1 = malloc(sizeof(t_stack_node));
//     t_stack_node *node2 = malloc(sizeof(t_stack_node));
//     t_stack_node *node3 = malloc(sizeof(t_stack_node));
//     t_stack_node *node4 = malloc(sizeof(t_stack_node));
//     t_stack_node *node5 = malloc(sizeof(t_stack_node));
//     t_stack_node *node6 = malloc(sizeof(t_stack_node));

//     node1->content = 5;
//     node2->content = 7;
//     node3->content = 9;
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     node4->content = 1;
//     node5->content = 2;
//     node6->content = 3;
//     node4->next = node5;
//     node5->next = node6;
//     node6->next = NULL;

//     t_stack_node *s1 = node1;
//     t_stack_node *s2 = node4;

//     printf("Avant rev_rota sa : \n");
//     print_stack(s1);

//     rra(&s1);

//     printf("Après rev_rota sa : \n");
//     print_stack(s1);

//     printf("Avant rev_rota sb : \n");
//     print_stack(s2);

//     rrb(&s2);

//     printf("Après rev_rota sb : \n");
//     print_stack(s2);

//     printf("Avant rev_rota ss : \n");
//     print_stack(s1);
//     print_stack(s2);

//     rrr(&s1, &s2);

//     printf("Après rev_rota ss : \n");
//     print_stack(s1);
//     print_stack(s2);

//     free(node1);
//     free(node2);
//     free(node3);
//     free(node4);
//     free(node5);
//     free(node6);

//     return (0);
// }