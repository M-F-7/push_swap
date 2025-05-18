/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:56:04 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/19 01:44:07 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/gnl/get_next_line.h"
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"
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
	struct s_stack_node	*target_node;
}						t_stack_node;

// utils
int						ft_stacksize(t_stack_node *stack);
void					ft_print_stack(t_stack_node **stack);
t_stack_node			*find_lastnode_stack(t_stack_node *stack);
void					put_min_top_stack(t_stack_node **stack);
t_stack_node			*find_little(t_stack_node *stack);
t_stack_node			*find_big(t_stack_node *stack);

// utils2
void					ft_stack_add_front(t_stack_node **stack,
							t_stack_node *new_node);
void					ft_stack_add_back(t_stack_node **stack,
							t_stack_node *new_node);
int						ft_stack_copy(t_stack_node **stack, char **str);
int						is_number(const char *s);
void					free_stack(t_stack_node **stack);

// errors
int						check_double(const char *str);
int						check_error(t_stack_node **tab, int c);
void					sort_three(t_stack_node **stack);
int						is_valid_int(const char *str);
void					free_tab(char **tab);

// init stcack
void					init_stack(t_stack_node *a, t_stack_node *b);
void					get_index(t_stack_node *stack);
void					set_target_node(t_stack_node *a, t_stack_node *b);
void					nodes_costs(t_stack_node *a, t_stack_node *b);
void					find_cheapest(t_stack_node *stack);

// sort_stack
void					ft_sort_stack(t_stack_node **a, t_stack_node **b);
void					move_cheapest(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					push_back_to_a(t_stack_node **a, t_stack_node **b);
int						is_sorted(t_stack_node *stack);

// commands
void					ft_swap_stack(t_stack_node *a);
void					sa(t_stack_node **stack);
void					sb(t_stack_node **stack);
void					ss(t_stack_node **a, t_stack_node **b);

void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **a, t_stack_node **b);

void					ra(t_stack_node **stack);
void					rb(t_stack_node **stack);
void					rr(t_stack_node **a, t_stack_node **b);

void					rra(t_stack_node **stack);
void					rrb(t_stack_node **stack);
void					rrr(t_stack_node **a, t_stack_node **b);

void					rotate(t_stack_node **stack);
void					r_rotate(t_stack_node **stack);

int						calculate_total_cost(int cost_a, int cost_b);
void					push_initial(t_stack_node **a, t_stack_node **b);

#endif