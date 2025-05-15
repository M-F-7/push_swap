/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:32:00 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/15 22:29:59 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack_node **stack)
{
    t_stack_node *second;
    if (ft_stacksize(*stack) < 2)
        return;
    second = (*stack)->next;
    ft_swap_stack(*stack, second);
}

void sb(t_stack_node **stack)
{
    t_stack_node *second;
    if (ft_stacksize(*stack) < 2)
        return;
    second = (*stack)->next;
    ft_swap_stack(*stack, second);
}

void   ss(t_stack_node **stack1,t_stack_node **stack2)
{
    if (ft_stacksize(*stack1) < 2 || ft_stacksize(*stack2) < 2)
        return;
    sa(stack1);
    sb(stack2);
}

int main(void)
{
    t_stack_node *node1 = malloc(sizeof(t_stack_node));
    t_stack_node *node2 = malloc(sizeof(t_stack_node));
    t_stack_node *node3 = malloc(sizeof(t_stack_node));
    t_stack_node *node4 = malloc(sizeof(t_stack_node));
    t_stack_node *node5 = malloc(sizeof(t_stack_node));
    t_stack_node *node6 = malloc(sizeof(t_stack_node));

    node1->content = 5;
    node2->content = 7;
    node3->content = 9;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node4->content = 1;
    node5->content = 2;
    node6->content = 3;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    t_stack_node *s1 = node1;
    t_stack_node *s2 = node4;

    printf("Avant swap sa : \n");
    print_stack(s1);

    sa(&s1);

    printf("Après swap sa : \n");
    print_stack(s1);

    printf("Avant swap sb : \n");
    print_stack(s2);

    sb(&s2);

    printf("Après swap sb : \n");
    print_stack(s2);

    printf("Avant swap ss : \n");
    print_stack(s1);
    print_stack(s2);

    ss(&s1, &s2);

    printf("Après swap ss : \n");
    print_stack(s1);
    print_stack(s2);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);

    return 0;
}