/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:22:06 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 18:29:19 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_tree(t_list **stack)
{
	int		nd;
	int		rd;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	nd = (*stack)->next->content;
	rd = (*stack)->next->next->content;
	if ((*stack)->content < nd && (*stack)->content < rd && nd > rd)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if ((*stack)->content < nd && nd > rd && rd < (*stack)->content)
		rra(stack, 1);
	else if ((*stack)->content > nd && rd > nd && (*stack)->content < rd)
		sa(stack, 1);
	else if ((*stack)->content > nd && nd < rd && (*stack)->content > rd)
		ra(stack, 1);
	else if ((*stack)->content > nd && nd > rd)
	{
		ra(stack, 1);
		sa(stack, 1);
	}
	update(stack);
}

int	the_min_index(t_list *chaine)
{
	t_list	*temp;
	int		idx;
	int		min;

	if (!chaine)
		return (-1);
	temp = chaine;
	idx = 1;
	min = temp->content;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->content < min)
		{
			min = temp->content;
			idx = temp->index;
		}
		temp = temp->next;
	}
	return (idx);
}

void	shuffle(t_list **stackA, t_list **stackB)
{
	while (the_min_index(*stackA) != 1)
	{
		if (the_min_index(*stackA) < 4)
			ra(stackA, 1);
		else
			rra(stackA, 1);
	}
	pb(stackA, stackB, 1);
}

void	for_five(t_list	**stackA, t_list **stackB)
{
	shuffle(stackA, stackB);
	shuffle(stackA, stackB);
	for_tree(stackA);
	pa(stackB, stackA, 1);
}

int	find_the_cheaper(t_list **chaineB)
{
	t_list		*temp_b;
	int			temp;
	int			index;

	temp_b = *chaineB;
	index = 1;
	temp = temp_b->index + temp_b->ell.bok_index;
	while (temp_b != NULL)
	{
		if (temp_b->index + temp_b->ell.bok_index < temp)
		{
			temp = temp_b->index + temp_b->ell.bok_index;
			index = temp_b->index;
		}
		temp_b = temp_b->next;
	}
	return (index);
}
