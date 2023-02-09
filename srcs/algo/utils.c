/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:44:47 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/09 19:33:49 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	median(int *tab)
// {
// 	int	med;
	
// 	med = tab_size(tab);
// 	printf("%i\n", med);
// 	if (med % 2 == 0)
// 		return (tab[(med / 2) - 1]);
// 	else
// 		return (tab[(med / 2)]);
// }

void swap(int *t1, int *t2)
{
	int	temp;

	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

int	*tab_of_list(t_list *chaine, int size)
{
	int	*tab;
	int i;
	t_list *temp;

	temp = chaine;
	i = 0;
	tab = ft_callloc_tab(size);
	while (i < size)
	{
		tab[i] = (temp)->content;
		i++;
		temp = (temp)->next;
	}
	return tab;
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

// int tab_size(int *tab)
// {
// 	int i;
	
// 	i = 0;
// 	while (tab[i] != '*')
// 		i++;
// 	return (i);
// }