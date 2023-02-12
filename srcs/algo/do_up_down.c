/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_up_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:25:23 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/12 18:46:04 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    fill_ell(t_list *element, int sizeA,int sizeB)
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

void    ft_do_up(t_list **chaine, t_list **chaineB, int nb_of_ra, int nb_of_rb)
{
	int	min;
	int	i;

	i = 0;
	min = ft_min(nb_of_ra, nb_of_rb);
	if (min == nb_of_ra)
	{
		while (min-- > 0)
			rr(chaine, chaineB);	
		while(i++ < nb_of_rb - nb_of_ra)
			rb(chaineB, 1);
	}
	else
	{
		while (min-- > 0)
			rr(chaine, chaineB);	
		while(i++ <nb_of_ra - nb_of_rb)
			ra(chaine, 1);
	}
	pa(chaineB, chaine);
}

void	ft_do_down(t_list **chaine, t_list **chaineB, int nb_of_rra, int nb_of_rrb)
{
	int	min;
	int	i;

	i = 0;
	min = ft_min(nb_of_rra, nb_of_rrb);
	if (min == nb_of_rra)
	{
		while (min-- > 0)
			rrr(chaine, chaineB);	
		while(i++ <nb_of_rrb - nb_of_rra)
			rrb(chaineB, 1);
	}
	else
	{
		while (min-- > 0)
			rrr(chaine, chaineB);	
		while(i++ <nb_of_rra - nb_of_rrb)
			rra(chaine, 1);
	}
	pa(chaineB, chaine);
}

void	ft_do_up_do(t_list **chaine, t_list **chaineB, int nb_of_ra, int nb_of_rrb)
{
	int	i;

	i = 0;
	while (i++ <nb_of_ra)
		ra(chaine, 1);	
	i = 0;
	while(i++ < nb_of_rrb)
		rrb(chaineB, 1);
	pa(chaineB, chaine);
}

void	ft_do_do_up(t_list **chaine, t_list **chaineB, int nb_of_rra, int nb_of_rb)
{
	int	i;

	i = 0;
	while (i++ < nb_of_rra)
		rra(chaine, 1);	
	i = 0;
	while(i++ < nb_of_rb)
		rb(chaineB, 1);
	pa(chaineB, chaine);
}