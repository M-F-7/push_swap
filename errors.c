/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:26:27 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/19 01:26:30 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(const char *str)
{
	int	i;
	int	value;

	i = 0;
	value = ft_atoi(&str[0]);
	while (str[i])
	{
		if (value == ft_atoi(&str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_big(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

int	is_valid_int(const char *str)
{
	long long	nb;
	int			sign;
	int			i;

	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if ((sign == 1 && nb > INT_MAX) || (sign == -1 && (-nb) < INT_MIN))
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

// void	free_tab(char **tab)
// {
// 	size_t	i;

// 	i = 0;
// 	while (tab && tab[i])
// 		free(tab[i++]);
// 	free(tab);
// }