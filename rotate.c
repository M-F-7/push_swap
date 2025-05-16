/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:32:45 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/16 22:30:27 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = *stack;
	*stack = (*stack)->next;
	last = find_lastnode_stack(*stack);
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = *stack;
	*stack = (*stack)->next;
	last = find_lastnode_stack(*stack);
	last->next = first;
	first->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack_node **stack1, t_stack_node **stack2)
{
	ra(stack1);
	rb(stack2);
	ft_printf("rr\n");
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

//     printf("Avant rota sa : \n");
//     print_stack(s1);

//     ra(&s1);

//     printf("Après rota sa : \n");
//     print_stack(s1);

//     printf("Avant rota sb : \n");
//     print_stack(s2);

//     rb(&s2);

//     printf("Après rota sb : \n");
//     print_stack(s2);

//     printf("Avant rota ss : \n");
//     print_stack(s1);
//     print_stack(s2);

//     rr(&s1, &s2);

//     printf("Après rota ss : \n");
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