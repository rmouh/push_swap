/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:24:46 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 18:26:15 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **chaine, int p)
{
	t_list	*temp;

	if ((*chaine)->next == NULL || *chaine == NULL)
		return (0);
	temp = ft_beforlast(*chaine);
	ft_lstadd_front(chaine, ft_lstnew(temp->next->content, 1));
	free(temp->next);
	temp->next = NULL;
	if (p)
		ft_printf("rra\n");
	update(chaine);
	return (1);
}

int	rrb(t_list **chaine, int p)
{
	t_list	*temp;

	if ((*chaine)->next == NULL || *chaine == NULL)
		return (0);
	temp = ft_beforlast(*chaine);
	ft_lstadd_front(chaine, ft_lstnew(temp->next->content, 1));
	free(temp->next);
	temp->next = NULL;
	if (p)
		ft_printf("rrb\n");
	update(chaine);
	return (1);
}

int	rrr(t_list **chaineA, t_list **chaineB, int p)
{
	if (rra(chaineA, 0) && rrb(chaineB, 0))
	{
		if (p)
			ft_printf("rrr\n");
		return (0);
	}
	return (0);
}

int	freee(t_list **lst)
{
	t_list	*track;
	t_list	*nextt;

	track = *lst;
	*lst = NULL;
	while (track != NULL)
	{
		nextt = track->next;
		free(track);
		track = nextt;
	}
	return (1);
}
