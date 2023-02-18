/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:24:46 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/18 14:22:48 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printl(t_list *chaine)
{
	while (chaine != NULL)
	{
		ft_printf("[%d] --> %d\n ", chaine->index, (int)(chaine->content));
		ft_printf("{ ra: %d, rb: %d", chaine->ell.ra, chaine->ell.rb);
		ft_printf(", rra: %d, rrb: ", chaine->ell.rra, chaine->ell.rrb);
		ft_printf(", rr: %d, rrr: %d,", chaine->ell.rr, chaine->ell.rrr);
		ft_printf(" bok:%d, ind: %d}\n", chaine->ell.bok, chaine->ell.bok_index);
		chaine = chaine->next;
	}
}

void	printll(t_list *chaine)
{
	while (chaine != NULL)
	{
		ft_printf("[%d] --> %d\n ", chaine->index, (int)(chaine->content));
		chaine = chaine->next;
	}
}

int	char_in(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (1);
		else if (str[i] == '-' && (str[i + 1] < '0' || str[i + 1] > '9'))
			return (1);
		else
			i++;
	}
	return (0);
}

int	is_not_integer(char *src)
{
	if (ft_strcontain(src, ".") == 1 || char_in(src) == 1)
		return (1);
	return (0);
}

t_list	*update(t_list **chaine)
{
	t_list	*temp;
	int		counter;

	counter = 1;
	temp = *chaine;
	while (temp != NULL)
	{
		temp->index = counter;
		counter++;
		temp = temp->next;
	}
	return (*chaine);
}
