/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:32:44 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/19 01:34:19 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (ac < 2)
// 		return (0);
// 	if (ac == 2 && !av[2])
// 	{
// 		av = ft_split(av[1], ' ');
// 		if (!av)
// 			free(av);
// 	}
// 	ft_stack_copy(&a, av);
// 	if (!a || is_sorted(a))
// 	{
// 		free_tab(av);
// 		return (0);
// 	}
// 	if (ac == 3 || ac == 4)
// 	{
// 		sort_three(&a);
// 		return (0);
// 	}
// 	ft_sort_stack(&a, &b);
// 	free_stack(&a);
// 	return (0);
// }

// #include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	t_stack_node *a = NULL;
// 	t_stack_node *b = NULL;
// 	char **args = av + 1;
// 	int split_mode = 0;

// 	split_mode = 0
// 	if (ac < 2)
// 		return (0);
// 	if (ac == 2 && !av[2])
// 	{
// 		args = ft_split(av[1], ' ');
// 		if (!args)
// 			return (1);
// 		split_mode = 1;
// 	}
// 	if (!ft_stack_copy(&a, args))
// 	{
// 		if (split_mode)
// 			free_tab(args);
// 		return (0);
// 	}
// 	if (!a || is_sorted(a))
// 	{
// 		if (split_mode)
// 			free_tab(args);
// 		free_stack(&a);
// 		return (0);
// 	}
// 	if (ft_stacksize(a) <= 3)
// 		sort_three(&a);
// 	else
// 		ft_sort_stack(&a, &b);
// 	free_stack(&a);
// 	if (split_mode)
// 		free_tab(args);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;
	int				split_mode;

	a = NULL;
	b = NULL;
	args = av + 1;
	split_mode = 0;
	if (ac < 2)
		return (0);
	if (ac == 2 && !av[2])
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return (1);
		split_mode = 1;
	}
	if (!ft_stack_copy(&a, args))
	{
		if (split_mode)
			free_tab(args);
		return (0);
	}
	if (!a || is_sorted(a))
	{
		if (split_mode)
			free_tab(args);
		free_stack(&a);
		return (0);
	}
	if (ft_stacksize(a) <= 3)
		sort_three(&a);
	else
		ft_sort_stack(&a, &b);
	free_stack(&a);
	if (split_mode)
		free_tab(args);
	return (0);
}
