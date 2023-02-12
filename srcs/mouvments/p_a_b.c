/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_a_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:50:42 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/12 13:23:29 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int	pa(t_list **chaineB, t_list **chaineA)
{
	t_list	*temp;

	if (*chaineB == NULL)
		return (0);// B empty
	if ((*chaineB)->next == NULL)
	{
		ft_lstadd_front(chaineA, ft_lstnew((*chaineB)->content, 1));
		free(*(chaineB));
		*(chaineB) = NULL;
	}
	else
	{
		temp = *chaineB;
		ft_lstadd_front(chaineA, ft_lstnew(temp->content, 1));
		*chaineB = (*chaineB)->next;
		free(temp);
	}
	ft_printf("pa\n");
	update(chaineA);
	update(chaineB);
	return (1);
}

int	pb(t_list **chaineA, t_list **chaineB)
{
	t_list	*temp;

	if (*chaineA == NULL)
		return (0);// B empty
	if ((*chaineA)->next == NULL)
	{
		ft_lstadd_front(chaineB, ft_lstnew((*chaineA)->content, 1));
		free(*(chaineA));
		*(chaineA) = NULL;
	}
	else
	{
		temp = *chaineA;
		ft_lstadd_front(chaineB, ft_lstnew(temp->content, 1));
		*chaineA = (*chaineA)->next;
		 free(temp);
	}
	ft_printf("pb\n");
	update(chaineA);
	update(chaineB);
	return (1);
}
