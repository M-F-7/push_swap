/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:32:44 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/18 15:48:40 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2 && !av[2])
	{
		av = ft_split(av[1], ' ');
		if (!av)
			free(av);
	}
	ft_stack_copy(&a, av);
	if (!a || is_sorted(a))
		return (0);
	if (ac == 3 || ac == 4)
	{
		sort_three(&a);
		return (0);
	}
	ft_sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
