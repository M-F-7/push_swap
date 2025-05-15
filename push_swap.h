/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:56:04 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/15 22:25:15 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
#include "../libft/gnl/get_next_line.h"

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_stack_node
{
	int					content;
	// int					cost;
	// int					cheapest;
	// int					index;
	struct s_stack_node	*next;
	// struct s_stack_node	*previous;
	// struct s_stack_node	*target_node;
}						t_stack_node;

int	ft_stacksize(t_stack_node *stack);
void	ft_swap_stack(t_stack_node *a, t_stack_node *b);
void print_stack(t_stack_node *stack);
t_stack_node	*find_lastnode_stack(t_stack_node *lst);
void	ft_stack_add_front(t_stack_node **lst, t_stack_node *new);

#endif