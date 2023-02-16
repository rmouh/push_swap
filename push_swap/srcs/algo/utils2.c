/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:07:28 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 14:21:54 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost_of_up_do(int ra, int rrb)
{
	return (rrb + ra);
}

int	ft_cost_of_do_up(int rra, int rb)
{
	return (rra + rb);
}

int	the_max_of_a(t_list **chaine)
{
	t_list	*temp;
	int		max;

	temp = (*chaine);
	max = temp->content;
	while (temp->next != NULL)
	{
		if (temp->next->content > max)
			max = temp->next->content;
		temp = temp->next;
	}
	return (max);
}

t_list	*the_min_of_b(t_list **chaineb)
{
	t_list	*temp;
	t_list	*min;

	temp = (*chaineb);
	min = (*chaineb);
	while (temp->next != NULL)
	{
		if (temp->next->lower_cost < min->lower_cost)
			min = temp->next;
		temp = temp->next;
	}
	return (min);
}
