/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:14:37 by rmouhoub          #+#    #+#             */
/*   Updated: 2022/11/11 18:43:17 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_beforlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}