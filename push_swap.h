/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:56:04 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/16 21:37:22 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					content;
	int					cost;
	int					cost_a;
	int					cost_b;
	int					cheapest;
	int					index;
	struct s_stack_node	*next;
	bool				above_median;
	// struct s_stack_node	*previous;
	struct s_stack_node	*target_node;
}						t_stack_node;

int						ft_stacksize(t_stack_node *stack);
void					ft_swap_stack(t_stack_node *a, t_stack_node *b);
void					ft_print_stack(t_stack_node **stack);
t_stack_node			*find_lastnode_stack(t_stack_node *stack);
void					ft_stack_add_front(t_stack_node **stack,
							t_stack_node *new_node);
void					ft_stack_add_back(t_stack_node **stack,
							t_stack_node *new_node);
void					ft_stack_copy(t_stack_node **stack, char **str);
void					free_stack(t_stack_node **stack);

int						check_double(t_stack_node **tab, int c);
int						check_error(t_stack_node **tab, int c);

void					ft_check_number(t_stack_node **stack);
int						ft_content_cmp(t_stack_node *node1,
							t_stack_node *node2);

void					sa(t_stack_node **stack);
void					sb(t_stack_node **stack);
void					ss(t_stack_node **stack1, t_stack_node **stack2);

void					pa(t_stack_node **stack1, t_stack_node **stack2);
void					pb(t_stack_node **stack1, t_stack_node **stack2);

void					ra(t_stack_node **stack);
void					rb(t_stack_node **stack);
void					rr(t_stack_node **stack1, t_stack_node **stack2);

void					rra(t_stack_node **stack);
void					rrb(t_stack_node **stack);
void					rrr(t_stack_node **stack1, t_stack_node **stack2);

void					put_min_top_stack(t_stack_node *stack);
int						is_sorted(t_stack_node *stack);

void					ft_sort_stack(t_stack_node **stack1,
							t_stack_node **stack2);

int						is_number(const char *s);



void    init_stack(t_stack_node *stack1, t_stack_node *stack2);
void   get_index(t_stack_node *stack);
void    set_target_node(t_stack_node *stack1, t_stack_node *stack2);
t_stack_node *find_little(t_stack_node *stack);
void nodes_costs(t_stack_node *stack1, t_stack_node *stack2);
void find_cheapest(t_stack_node *stack);


void	move_cheapest(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void	push_back_to_a(t_stack_node **a, t_stack_node **b);


#endif