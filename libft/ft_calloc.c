/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:10:42 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/03 20:02:33 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_callloc(int nmemb)
{
	t_list	*buf;
	t_list	*temp;

	buf = malloc(sizeof(t_list) * nmemb);
	if (!buf)
		return (NULL);
	temp = buf;
	while(nmemb-- > 0)
	{
		buf->content = 0;
		buf = buf->next;
	}
	return (temp);
}

int	*ft_callloc_tab(int nmemb)
{
	int	*buf;
	int	i;

	i = 0;
	buf = malloc(sizeof(int) * (nmemb + 1));
	if (!buf)
		return (NULL);
	while(i < nmemb)
	{
		buf[i] = 0;
		i++;
	}
	buf[i] = '*';
	return (buf);
}
