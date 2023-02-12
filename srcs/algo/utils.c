/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:44:47 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/12 18:10:00 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int the_median(t_list **chaine)
{
	int		*tab;
	int		size_A;
	int		med;
	
	size_A =ft_lstsize(*chaine);
	tab = tab_of_list(*chaine, size_A);
	tab = bubble_sort(tab, size_A);
	med = tab[size_A / 2];
 	//ft_printf(">= MEDIANE = %i SIZE %i\n", med, size_A);
	return (med);
}

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

void find_bok(t_list **chaine, t_list **chaineB)
{
	int			A_value;
	int			B_value;
	t_list		*temp_A;
	t_list		*temp_B;
	int			i;
	
	temp_B = *chaineB;
	temp_A = *chaine;
	while (temp_B != NULL)
	{
		i = 1;
		temp_A = *chaine;
		B_value = temp_B->content;
		temp_B->ell.bok =  the_max_of_a(chaine);
		while (temp_A != NULL)
		{
			
			A_value = temp_A->content;
			if (A_value > B_value && A_value < temp_B->ell.bok)
			{
				//ft_printf("Am I here?????\n");
				temp_B->ell.bok = A_value;
				temp_B->ell.bok_index = i;
			}
			i++;
			temp_A = temp_A->next;
		}
		//ft_printf("index %d \n", i);
		temp_B = temp_B->next;
	}
	update(chaine);
	update(chaineB);
	
}

int find_the_cheaper(t_list **chaineB)
{
	t_list		*temp_B;
	int			temp;
	int			index;
	
	temp_B = *chaineB;
	index = 1;
	temp =  temp_B->index + temp_B->ell.bok_index; 
	while (temp_B != NULL)
	{
		if (temp_B->index + temp_B->ell.bok_index < temp)
		{
			temp =  temp_B->index + temp_B->ell.bok_index;
			index = temp_B->index;
		}
		temp_B = temp_B->next;
	}
	return (index);
}

// int tab_size(int *tab)
// {
// 	int i;
	
// 	i = 0;
// 	while (tab[i] != '*')
// 		i++;
// 	return (i);
// }
// void find_bok(t_list **chaine, t_list **chaineB)
// {
// 	int			A_value;
// 	int			B_value;
// 	t_list		*temp_A;
// 	t_list		*temp_B;
// 	int			i;
	
// 	temp_B = *chaineB;
// 	temp_A = *chaine;
// 	while (temp_B != NULL)
// 	{
// 		i = 1;
// 		temp_A = *chaine;
// 		B_value = temp_B->content;
// 		temp_B->ell.bok =  the_max_of_a(chaine);
// 		while (temp_A != NULL)
// 		{
			
// 			A_value = temp_A->content;
// 			if (A_value > B_value && A_value < temp_B->ell.bok)
// 			{
// 				ft_printf("Am I here?????\n");
// 				temp_B->ell.bok = A_value;
// 				temp_B->ell.bok_index = i;
// 			}
// 			i++;
// 			temp_A = temp_A->next;
// 		}
// 		//ft_printf("index %d \n", i);
// 		temp_B = temp_B->next;
// 	}
// 	update(chaine);
// 	update(chaineB);
	
// }