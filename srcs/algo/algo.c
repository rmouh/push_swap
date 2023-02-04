/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:00 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/04 20:36:59 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int before_lst_content (t_list *chaineB)
{
	t_list *temp;
	t_list	*chaine;
	
	chaine = chaineB;
	temp = ft_beforlast(chaine);
	return (temp->content);
}

int lst_content (t_list *chaineB)
{
	t_list *temp;
	t_list	*chaine;
	
	chaine = chaineB;
	temp = ft_lstlast(chaine);
	return (temp->content);
}

int find_position(t_list *chaineB, int value)
{
	t_list	*tmp;
	int		position;
	
	position = 0;
	tmp = chaineB;
	while (tmp->next != NULL)
	{
		if (tmp->content < value)
			return (position);
		position++;
		tmp = tmp->next;
	}
	return (position);
}

// void each_time(t_list **chaine, t_list **chaineB)
// {
// 	int		*sorted;
// 	int		compare;
// 	int		med;
// 	int 	found;
	
// 	sorted = tab_of_list(*chaine, ft_lstsize(*chaine));
// 	sorted = bubble_sort(sorted, tab_size(sorted));
// 	found = 0;
// 	ft_printf("at the start\n");
// 	printl(*chaine);
// 	ft_printf("\n");
// 	med = median(sorted);
// 				ft_printf(">= MEDIANE = %i SIZE %i\n", med, ft_lstsize(*chaine));

// 	while (ft_lstsize(*chaine) > 3)
// 	{
// 		// sleep(2);
// 			if ((*chaine)->content >= med)
// 			{
// 				if ((*chaine)->content == med)
// 				{
// 					found++;
// 					if (found == 2)
// 					{
// 						if (ft_lstsize((*chaineB)) > 0)
// 						{
// 							compare = (*chaineB)->content;
// 							if (compare > (*chaine)->content)
// 								{pb(chaine, chaineB);
// 								ra(chaineB, 1);}
// 							else 
// 								pb(chaine, chaineB);
// 						}
// 						//pb(chaine, chaineB);
// 						sorted = tab_of_list((*chaine), ft_lstsize((*chaine)));
// 						med = median(sorted);
// 						ft_printf(">= MEDIANE = %i SIZE %i\n", med, ft_lstsize(*chaine));
// 						found = 0;
// 						//return ;
// 					}
// 					else
// 						ra(chaine, 1);
// 					ft_printf("the stack B\n");
// 					printl(*chaineB);
// 				}
// 				else
// 				{
// 						if (ft_lstsize((*chaineB)) > 0)
// 						{
// 		    				compare = (*chaineB)->content;
// 							if (compare < (*chaine)->content && (*chaine)->content < lst_content(*chaineB)) // cas : is bigger ->at the top
// 								pb(chaine, chaineB);
// 							else if (compare > (*chaine)->content && (*chaine)->content < lst_content(*chaineB)) //need to find the position
// 								{
// 									int po = find_position(*chaineB, (*chaine)->content);
// 									while (po-- > 0)
// 										rb(chaineB, 1);
// 									pb(chaine, chaineB);
// 								}
// 							else if (compare > (*chaine)->content && (ft_lstsize((*chaineB)) == 1 || lst_content (*chaineB) > (*chaine)->content))
// 							{// is smaller then the last or  2 elements cas 
// 								ft_printf("head of B: %d head of A: %d B size : %d lst element of B: %d\n", compare, (*chaine)->content, ft_lstsize((*chaineB)), lst_content (*chaineB));
// 								pb(chaine, chaineB);
// 								ra(chaineB, 1);
// 							}
// 							else//need to find the position
// 								{
// 									int po = find_position(*chaineB, (*chaine)->content);
// 									while (po-- > 0)
// 										rb(chaineB, 1);
// 									pb(chaine, chaineB);
// 								}
// 						}
// 						else
// 						{
// 							pb(chaine, chaineB);
// 						}
// 					ft_printf("the stack B\n");
// 					printl(*chaineB);
// 				}
// 			}
// 			else
// 				ra(chaine, 1);
// 			ft_printf("the stack A\n");
// 			printl((*chaine));
// 			ft_printf("the stack B\n");
// 			printl(*chaineB);
// 			//pb(chaine, chaineB);
// }
// }

void each_time(t_list **chaine, t_list **chaineB)
{
	t_list	*temp;
	int		*tab;
	int		size_A;
	int		med;
	int		headA;
	int		headB;
	int		po;
	int		po2;

	(void )chaineB;
	
	while (ft_lstsize(*chaine) > 3)
	{
		
		tab = tab_of_list(*chaine, ft_lstsize(*chaine));
		tab = bubble_sort(tab, ft_lstsize(*chaine));
		//tab = bubble_sort(tab_of_list(*chaine, ft_lstsize(*chaine)), ft_lstsize(*chaine));
		// med = median(tab, ft_lstsize(*chaine));
		med = tab[ft_lstsize(*chaine) / 2];
		// if (med == 0)
		// 	print_tab(tab, 100);
		//ft_printf(">= MEDIANE = %i SIZE %i\n", med, ft_lstsize(*chaine));

		size_A = ft_lstsize(*chaine);
		temp = *chaine;
		while (size_A-- > 0 && ft_lstsize(*chaine) > 3)
		{
			//ft_printf("the stack A\n");
			//printl((*chaine));
			//ft_printf("the stack B\n");
			//printl(*chaineB);
			if (ft_lstsize(*chaineB) == 0)
				{
					pb(chaine, chaineB);
					//continue;
				}
			else 
			{
				headA = (*chaine)->content;
				headB = (*chaineB)->content;
				if (headA > med) // > med
				{
					if (headA > headB)// at the top
						{
							//ft_printf("the head of A %d the head of B %d\n", headA, headA);
							pb(chaine, chaineB);}
					// else if (headA < headB && (ft_lstsize(*chaineB) == 1 || headA < lst_content(*chaineB))) // at the end 
					// {

					// 	pb(chaine, chaineB);
					// 	rb(chaineB, 1);
					// }
					else //if (headA < headB && headA < lst_content(*chaineB))//find the position 
					{

						po = find_position(*chaineB, headA);
						po2 = po;
						while (po-- > 0)
							rb(chaineB, 1);
						pb(chaine, chaineB);
						while (po2-- > 0)
							rrb(chaineB, 1);
					}
				}
				else //rotate < med
				{
					ra(chaine, 1);	
				}
			}
			temp = (*chaine)->next;			
		}
		free(tab);
	}
	//rrb(chaineB, 1);
	ft_printf("the stack B\n");
			printl(*chaineB);
}

int main(int argc, char *argv[]){
	
	int *tab;
	t_list	*chaine = 0;
	t_list	*chaineB = 0;
	
	if (argc == 1)
		return (write(2, "ERROR nothing to sort\n", 22), 0);
	if (tab_check(argv, argc - 1) == 0)
		return (0);
	else 
	{
		chaine = the_chaine(argc, argv);
		if (chaine == NULL)
			return(0);//erreur du malloc
		//printl(chaine);
		//rra(&chaine, 1);
		//for_tree(&chaine);
		tab = tab_of_list(chaine, argc - 1);

		// //sa(&chaine,1);
		//print_tab(tab, argc - 1);
		//print_tab(bubble_sort(tab, argc - 1), argc - 1);
		each_time(&chaine, &chaineB);
		for_five(&chaine, &chaineB);
		while ( ft_lstsize(chaineB) > 0)
			pa(&chaineB, &chaine);
		ft_printf("end\n");
		printl(chaine);
		
		rra(&chaine, 1);
		rra(&chaine, 1);
		rra(&chaine, 1);
		// rra(&chaine, 1);
		// rra(&chaine, 1);
		ft_printf("end\n");
		printl(chaine);
		free (tab);
		freee(&chaine);
		freee(&chaineB);


}
}

	