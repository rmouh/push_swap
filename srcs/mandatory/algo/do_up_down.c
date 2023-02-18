/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_up_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:25:23 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 18:34:52 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_ell(t_list *element, int sizeA, int sizeB)
{
	if (element->ell.bok_index == 0)
	{
		element->ell.bok_index = 1;
	}
	element->ell.ra = element->ell.bok_index - 1;
	element->ell.rra = sizeA + 1 - element->ell.bok_index;
	element->ell.rb = element->index - 1;
	element->ell.rrb = sizeB - element->index + 1;
	element->ell.rr = ft_min(element->ell.ra, element->ell.rb);
	element->ell.rrr = ft_min(element->ell.rra, element->ell.rrb);
}

void	ft_do_up(t_list **chaine, t_list **chaineB, int nb_ra, int nb_rb)
{
	int	min;
	int	i;

	i = 0;
	min = ft_min(nb_ra, nb_rb);
	if (min == nb_ra)
	{
		while (min-- > 0)
			rr(chaine, chaineB, 1);
		while (i++ < nb_rb - nb_ra)
			rb(chaineB, 1);
	}
	else
	{
		while (min-- > 0)
			rr(chaine, chaineB, 1);
		while (i++ < nb_ra - nb_rb)
			ra(chaine, 1);
	}
	pa(chaineB, chaine, 1);
}

void	ft_do_down(t_list **chaine, t_list **chaineB, int nb_rra, int nb_rrb)
{
	int	min;
	int	i;

	i = 0;
	min = ft_min(nb_rra, nb_rrb);
	if (min == nb_rra)
	{
		while (min-- > 0)
			rrr(chaine, chaineB, 1);
		while (i++ < nb_rrb - nb_rra)
			rrb(chaineB, 1);
	}
	else
	{
		while (min-- > 0)
			rrr(chaine, chaineB, 1);
		while (i++ < nb_rra - nb_rrb)
			rra(chaine, 1);
	}
	pa(chaineB, chaine, 1);
}

void	ft_do_up_do(t_list **chaine, t_list **chaineB, int nb_ra, int nb_rrb)
{
	int	i;

	i = 0;
	while (i++ < nb_ra)
		ra(chaine, 1);
	i = 0;
	while (i++ < nb_rrb)
		rrb(chaineB, 1);
	pa(chaineB, chaine, 1);
}

void	ft_do_do_up(t_list **chaine, t_list **chaineB, int nb_rra, int nb_rb)
{
	int	i;

	i = 0;
	while (i++ < nb_rra)
		rra(chaine, 1);
	i = 0;
	while (i++ < nb_rb)
		rb(chaineB, 1);
	pa(chaineB, chaine, 1);
}
