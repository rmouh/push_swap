/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:29:00 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 14:42:05 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_min_cost(t_list *element, t_list **chaine, t_list **chaineb)
{
	int	up;
	int	down;
	int	up_do;
	int	do_up;

	fill_ell(element, ft_lstsize(*chaine), ft_lstsize(*chaineb));
	up = ft_cost_of_up(element->ell.ra, element->ell.rb);
	down = ft_cost_of_down(element->ell.rra, element->ell.rrb);
	up_do = ft_cost_of_up_do(element->ell.ra, element->ell.rrb);
	do_up = ft_cost_of_do_up(element->ell.rra, element->ell.rb);
	if (up < down && up < up_do && up < do_up)
		ft_do_up(chaine, chaineb, element->ell.ra, element->ell.rb);
	else if (down < up && down < up_do && down < do_up)
		ft_do_down(chaine, chaineb, element->ell.rra, element->ell.rrb);
	else if (up_do < up && up_do < down && up_do < do_up)
		ft_do_up_do(chaine, chaineb, element->ell.ra, element->ell.rrb);
	else
		ft_do_do_up(chaine, chaineb, element->ell.rra, element->ell.rb);
}

int	the_costs(t_list *element, int sizeA, int sizeB)
{
	int	up;
	int	down;
	int	up_do;
	int	do_up;

	fill_ell(element, sizeA, sizeB);
	up = ft_cost_of_up(element->ell.ra, element->ell.rb);
	down = ft_cost_of_down(element->ell.rra, element->ell.rrb);
	up_do = ft_cost_of_up_do(element->ell.ra, element->ell.rrb);
	do_up = ft_cost_of_do_up(element->ell.rra, element->ell.rb);
	element->lower_cost = ft_min_of_four(up, down, up_do, do_up);
	if (up < down && up < up_do && up < do_up)
		return (1);
	else if (down < up && down < up_do && down < do_up)
		return (2);
	else if (up_do < up && up_do < down && up_do < do_up)
		return (3);
	else
		return (4);
}

void	action(t_list **chaine, t_list **chaineb, int result, t_list *element)
{
	if (result == 1)
		ft_do_up(chaine, chaineb, element->ell.ra, element->ell.rb);
	else if (result == 2)
		ft_do_down(chaine, chaineb, element->ell.rra, element->ell.rrb);
	else if (result == 3)
		ft_do_up_do(chaine, chaineb, element->ell.ra, element->ell.rrb);
	else
		ft_do_do_up(chaine, chaineb, element->ell.rra, element->ell.rb);
}

int	the_median(t_list **chaine)
{
	int		*tab;
	int		size_a;
	int		med;

	size_a = ft_lstsize(*chaine);
	tab = tab_of_list(*chaine, size_a);
	tab = bubble_sort(tab, size_a);
	med = tab[size_a / 2];
	free (tab);
	return (med);
}
