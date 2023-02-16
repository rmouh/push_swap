/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_a_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:48:02 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 18:27:37 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_list **chaine, int p)
{
	int	temp;

	if ((*chaine)->next == NULL || *chaine == NULL)
		return (0);
	temp = (*chaine)->content;
	(*chaine)->content = (*chaine)->next->content;
	(*chaine)->next->content = temp;
	if (p)
		ft_printf("sb\n");
	update(chaine);
	return (1);
}

int	sa(t_list **chaine, int p)
{
	int	temp;

	if (*chaine == NULL || (*chaine)->next == NULL)
		return (0);
	temp = (*chaine)->content;
	(*chaine)->content = (*chaine)->next->content;
	(*chaine)->next->content = temp;
	if (p)
		ft_printf("sa\n");
	update(chaine);
	return (1);
}

int	ss(t_list **chaineA, t_list **chaineB, int p)
{
	if (sa(chaineA, 0) && sb(chaineB, 0))
	{
		if (p)
			ft_printf("ss\n");
		return (1);
	}
	return (0);
}
