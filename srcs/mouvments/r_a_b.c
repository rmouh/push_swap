/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_a_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:03:18 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/12 18:48:23 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int	ra(t_list **chaine, int p)
{
	t_list	*temp;

	temp = *chaine;
	if ((*chaine)->next == NULL || *chaine == NULL)
		return (0); // do nothing
	ft_lstadd_back(chaine, ft_lstnew((*chaine)->content, 1));
	temp = *chaine;
	*chaine = (*chaine)->next;
	free(temp);
	temp = NULL;
	if (p)
		ft_printf("ra\n");
	update(chaine);
	return (1);
}

int	rb(t_list **chaine, int p)
{
	t_list	*temp;

	if ((*chaine)->next == NULL || *chaine == NULL)
		return (0); // do nothing
	ft_lstadd_back(chaine, ft_lstnew((*chaine)->content, 1));
	temp = *chaine;
	*chaine = (*chaine)->next;
	free(temp);
	temp = NULL;
	if (p)
		ft_printf("rb\n");
	update(chaine);

	return (1);
}

int	rr(t_list **chaineA, t_list **chaineB)
{
	if (ra(chaineA, 0) && rb(chaineB, 0))
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}
