/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:32:44 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/16 21:44:04 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ne pas oublier de traiter les arguments du main si ils sont sous la forme d une str ex de base
//./a   1 2 45 3 6 8 ; ex a traiter ./a " 1 2 35 65 "-> il faut split

// gerer les negtifs; gerer les cas d erreur genre int min et int max,	// autre que des int genre les char

// peut etre fais sous forme de liste

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
	if (!a)
		return (0);
	if (is_sorted(a)==1)
		return (0);
	if (ac == 3 || ac == 4)
	{
		ft_check_number(&a);
		ft_print_stack(&a);
		return (0);
	}
	ft_sort_stack(&a, &b);
	ft_print_stack(&a);
	return (0);
}

void	ft_sort_stack(t_stack_node **stack1, t_stack_node **stack2)
{
	int	size;

	size = ft_stacksize((*stack1));
	while(size > 3)
		pb(stack1, stack2);
	ft_check_number((stack1));
	push_back_to_a(stack1, stack2);
	if (is_sorted((*stack1)) == 1)
		put_min_top_stack((*stack1));
}




void	push_back_to_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *node;

    while (*b)
    {
        init_stack(*a, *b); // met à jour index, target, cost, cheapest
        // Trouver le node marqué cheapest dans B
        node = *b;
        while (node && !node->cheapest)
            node = node->next;
        if (node)
            move_cheapest(a, b, node); // effectue les moves et pa
    }
	if (is_sorted((*a)) == 1)
    	put_min_top_stack(*a);
}



// void	move_cheapest(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
// {
//     int	cost_a = cheapest->cost_a;
//     int	cost_b = cheapest->cost_b;

//     // Rotations combinées
//     while (cost_a > 0 && cost_b > 0)
//     {
//         rr(a, b);
//         cost_a--;
//         cost_b--;
//     }
//     while (cost_a < 0 && cost_b < 0)
//     {
//         rrr(a, b);
//         cost_a++;
//         cost_b++;
//     }
//     // Rotations individuelles
//     while (cost_a > 0)
//     {
//         ra(a);
//         cost_a--;
//     }
//     while (cost_a < 0)
//     {
//         rra(a);
//         cost_a++;
//     }
//     while (cost_b > 0)
//     {
//         rb(b);
//         cost_b--;
//     }
//     while (cost_b < 0)
//     {
//         rrb(b);
//         cost_b++;
//     }
//     pa(a, b);
// }


























// faire une fonction qui s occupe de faire les instructions avec l afichage si possible
// faire une fonction qui free ta lst;
// s occcuper de read et exit;
// faire une fonction qui trouve le min
// faire une fonction qui met min au top
// faire une fonction qui trouve un max

// quick sort : porrais prendre la premier element de av et le choisir comme pivot puis
// comparer av[i++] puis le mettre dans un des deux sous tableau si c est inferieur ou superieur

// printf chaque instruction avec un \n

// turkish sort :
// demarre par push 2 elt vers b (sans check)
// doit calculer le cout de chaque element ------------------- peut etre sans prendre en compte les 3 derniers a part quand il reste que 4 element pour les comparer entre eux.
// doit push l elt le moins cher
// doit push vers b elt qui doit avoir au top de b un nombre plus grand que lui pour rentrer au top de b
// les trois derniers doivent etre range dans l ordre croissant quand il ny a plus qu eux: soit just swap ; soit rota rev et puis swap.
// meme focntionnement pour push back il faut que le top a soit plus grand que l elt a push,	// c est la seule verif a faire sinon on re push vers a. (je ne pense pas qu il faut re calculer les couts)
// last step : mettre le min au top




//push toutes les nodes de a vers b jusqu a ce qu il y en est plus que 3
// sort a
//la target node de la node dans b est l elt le plus petit plus garnd que lui
// si il y en a pas alors c est le plus petit

//len - position