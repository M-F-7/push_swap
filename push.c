/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:32:38 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/17 18:52:05 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void pa(t_stack_node **stack1, t_stack_node **stack2)
{
    t_stack_node *first;

    if (!stack2 || !*stack2)
        return;
    first = *stack2;
    *stack2 = first->next;
    ft_stack_add_front(stack1, first);
    ft_putstr_fd("pa\n", 1);
}

void pb(t_stack_node **stack1, t_stack_node **stack2)
{
    t_stack_node *first;

    if (!stack1 || !*stack1)
        return;
    first = *stack1;
    *stack1 = first->next;
    ft_stack_add_front(stack2, first);
    ft_putstr_fd("pb\n", 1);
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

//     printf("Avant push sa : \n");
//     print_stack(s1);
//     print_stack(s2);

//     pa(&s1, &s2);

//     printf("Après push sa : \n");
//     print_stack(s1);
//     print_stack(s2);

//     printf("Avant push sb : \n");
//     print_stack(s1);
//     print_stack(s2);

//     pb(&s1, &s2);

//     printf("Après push sb : \n");
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