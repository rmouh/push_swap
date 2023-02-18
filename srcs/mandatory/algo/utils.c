/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:44:47 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 14:01:58 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *t1, int *t2)
{
	int	temp;

	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

int	*tab_of_list(t_list *chaine, int size)
{
	int		*tab;
	int		i;
	t_list	*temp;

	temp = chaine;
	i = 0;
	tab = ft_callloc_tab(size);
	while (i < size)
	{
		tab[i] = (temp)->content;
		i++;
		temp = (temp)->next;
	}
	return (tab);
}

int	*bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	min;
	int	index;

	min = tab[0];
	index = 0;
	i = 0;
	while (i < size)
	{
		j = i;
		min = tab[i];
		while (j < size)
		{
			if (tab[j] < min)
			{
				index = j;
				min = tab[j];
			}
			j++;
		}
		swap(&tab[index], &tab[i]);
		index = ++i;
	}
	return (tab);
}

void	find_bok(t_list **chaine, t_list **chaineB)
{
	int			a_value;
	int			b_value;
	t_list		*temp_a;
	t_list		*temp_b;
	int			i;

	temp_b = *chaineB;
	temp_a = *chaine;
	while (temp_b != NULL)
	{
		i = 1;
		temp_a = *chaine;
		b_value = temp_b->content;
		temp_b->ell.bok = the_max_of_a(chaine);
		while (temp_a != NULL)
		{		
			a_value = temp_a->content;
			if_do(a_value, b_value, temp_b, i);
			i++;
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}

void	if_do(int a_value, int b_value, t_list *temp_b, int i)
{
	if (a_value > b_value && a_value < temp_b->ell.bok)
	{
		temp_b->ell.bok = a_value;
		temp_b->ell.bok_index = i;
	}
}
