/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:32:44 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/15 10:50:53 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ne pas oublier de traiter les arguments du main si ils sont sous la forme d une str ex de base
//./a   1 2 45 3 6 8 ; ex a traiter ./a " 1 2 35 65 "-> il faut split

// gerer les negtifs; gerer les cas d erreur genre int min et int max,	// autre que des int genre les char

// peut etre fais sous forme de liste

int	main(int ac, char **av)
{
	size_t	i;
    t_stack_node **a;
    t_stack_node **b;

	a = NULL;
	i = 1;
    if (b)
        return (0);
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[i], ' ');
		if (!av)
			free(av);
		return (0);
	}
	ft_lstadd_back(a, av[i++]);
    
    
}


void	check_error(char **tab)
{
	int	i;
	int	j;
	char	tmp;

	i = 0;
	j = 0;
	tmp = tab[i][j];
	while (tab[i])
	{
        tmp = tab[i][j];
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				ft_printf("Error\n");
			if (tab[i][j] > INT_MAX || tab[i][j] < INT_MIN)
				ft_printf("Error\n");
            if (check_double(tab, tmp, i, j) == 1)
                ft_printf("Error\n");
            j++;
		}
        i++;
	}
}

int	check_double(char **tab, char c, int i, int j)
{
    if (tab[i][j])
        j++;
    else
    {
        i++;
        j = 0;
    }
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (c == tab[i][j])
				return (1);
            j++;
		}
        i++;
        j = 0;
	}
	return (0);
}



// faire une fonction qui s occupe de faire les instructions avec l afichage si possible
// faire une fonction qui free ta lst;
// s occcuper de read et exit;
// faire une fonction qui trouve le min
//faire une fonction qui met min au top
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