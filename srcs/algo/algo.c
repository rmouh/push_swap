/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:00 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/09 19:51:36 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
	while (tmp != NULL)
	{
		if (tmp->content < value)
			return (position);
		position++;
		tmp = tmp->next;
	}
	return (position);
}


int the_median(t_list **chaine)
{
	int		*tab;
	int		size_A;
	int		med;
	
	size_A =ft_lstsize(*chaine);
	tab = tab_of_list(*chaine, size_A);
	tab = bubble_sort(tab, size_A);
	med = tab[size_A / 2];
 	ft_printf(">= MEDIANE = %i SIZE %i\n", med, size_A);
	return (med);
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
		temp_B->ell.bok = temp_A->content;
		while (temp_A != NULL)
		{
			A_value = temp_A->content;
			if (A_value > B_value && A_value <= temp_B->ell.bok)
			{
				temp_B->ell.bok = A_value;
				temp_B->ell.bok_index = i;
			}
			i++;
			temp_A = temp_A->next;
		}
		ft_printf("index %d \n", i);
		temp_B = temp_B->next;
	}
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

int	ra_cost(t_list **chaineB, int value)
{
	t_list	*track;
	int		size;

	size = ft_lstsize(*chaineB);
	track = *chaineB;
	
	while (track!= NULL)
	{
		track->ell.ra = track->index - 1;
		track->ell.rra = size - track->index;
		track
	}
}



int	the_min_cost(t_list *element, int sizeA, int sizeB, t_list **chaine, t_list **chaineB)
{
	int	up;
	int	down;
	int	up_do;
	int	do_up;
	
	up = ft_cost_of_up(element->ell.bok_index, element->index - 1);
	down = ft_cost_of_down(sizeA - element->ell.bok_index + 1, sizeB - element->index + 1);
	up_do = ft_cost_of_up_do(element->ell.bok_index,  sizeB - element->index + 1);
	do_up = ft_cost_of_do_up(sizeA - element->ell.bok_index + 1, element->index - 1);
	if (up < down && up < up_do && up < do_up)
		ft_do_up(chaine, chaineB, up, ft_min(sizeA - element->ell.bok_index, sizeB - element->index));
	else if (down < up && down < up_do && down < do_up)
		ft_do_down(chaine, chaineB, down, ft_min(element->ell.bok_index, element->index - 1));
	else if (up_do < up && up_do < down && up_do < do_up)
		ft_do_up_do(chaine, chaineB, ,);
	else
		ft_do_do_up();
}

void	ft_do_up(t_list **chaine, t_list **chaineB, int nb_of_ra, int nb_of_rb)
{
	int	min;
	int	i;

	i = 0;
	min = ft_min(nb_of_ra, nb_of_rb);
	if (min == nb_of_ra)
	{
		while (min-- > 0)
			rr(chaine, chaineB);	
		while(i++ < nb_of_rb - nb_of_ra)
			rb(chaineB, 1);
	}
	else
	{
		while (min-- > 0)
			rr(chaine, chaine);	
		while(i++ <nb_of_ra - nb_of_rb)
			ra(chaine, 1);
	}
}

void	ft_do_down(t_list **chaine, t_list **chaineB, int nb_of_rra, int nb_of_rrb)
{
	int	min;
	int	i;

	i = 0;
	min = ft_min(nb_of_rra, nb_of_rrb);
	if (min == nb_of_rra)
	{
		while (min-- > 0)
			rrr(chaine, chaineB);	
		while(i++ <nb_of_rrb - nb_of_rra)
			rrb(chaineB, 1);
	}
	else
	{
		while (min-- > 0)
			rrr(chaine, chaineB);	
		while(i++ <nb_of_rra - nb_of_rrb)
			rra(chaine, 1);
	}
}

// int action(t_list **chaine, t_list *chaineB, int result)
// {
// 	if (result == 1)
// 	{
// 		ft_do_up();
// 	}
// 	else if (result == 2)
// 		ft_do_down();
// 	else if (result == 3)
// 		ft_do_up_do();
// 	else
// 		ft_do_do_up();
// }


int main(int argc, char *argv[]){
	
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
		chaineB = the_chaine(argc, argv);
		ft_lstadd_front(&chaineB, ft_lstnew( 1, 1));
		ft_lstadd_front(&chaineB, ft_lstnew( 2, 2));
		ft_lstadd_front(&chaineB, ft_lstnew( 10, 3));
		ft_lstadd_front(&chaineB, ft_lstnew( 14, 4));
		ft_lstadd_front(&chaineB, ft_lstnew( 44, 5));
		update (&chaineB);


		find_bok(&chaine, &chaineB);
		printl(chaine);
		ft_printf("end\n");

		printl(chaineB);
		ft_printf("end\n");

		ft_printf("the cheaper %d \n", find_the_cheaper(&chaineB));


		// //sa(&chaine,1);
	//	print_tab(tab, argc - 1);
	//	print_tab(bubble_sort(tab, argc - 1), argc - 1);
		// each_time(&chaine, &chaineB);
		// //for_five(&chaine, &chaineB);
		// for_tree(&chaine);
		// while ( ft_lstsize(chaineB) > 0)
		// 	pa(&chaineB, &chaine);
		// ft_printf("end\n");
		// printl(chaine);
		
		// rra(&chaine, 1);
		// rra(&chaine, 1);
		// rra(&chaine, 1);
		// // rra(&chaine, 1);
		// // rra(&chaine, 1);
		// ft_printf("end\n");
		// printl(chaine);
		// freee(&chaine);
		// freee(&chaineB);


}
}
/*
void each_time(t_list **chaine, t_list **chaineB)
{
	int		*tab;
	int		size_A;
	int		med;
	int		headA;
	int		headB;
	t_list	*tmp;
	// int		po;
	// int		po2;

	//(void )chaineB;
		tmp = *chaine;
	
	while (ft_lstsize(*chaine) > 3)
	{
		
		tab = tab_of_list(*chaine, ft_lstsize(*chaine));
		tab = bubble_sort(tab, ft_lstsize(*chaine));
		//tab = bubble_sort(tab_of_list(*chaine, ft_lstsize(*chaine)), ft_lstsize(*chaine));
		// med = median(tab, ft_lstsize(*chaine));
		med = tab[ft_lstsize(*chaine) / 2];
		
		// if (med == 0)
		// 	print_tab(tab, 100);

		size_A = ft_lstsize(*chaine);
		tmp = *chaine;
		while (size_A-- > 0 && ft_lstsize(*chaine) > 3)
		{
			// ft_printf("the stack A\n");
			// printl((*chaine));
			// ft_printf("the stack B\n");
			// printl(*chaineB);
			headA = (*chaine)->content;
			//ft_printf("the head of A %d\n", headA);
			if (headA > med) // > med
			{
				if (ft_lstsize(*chaineB) == 0)
				{
					//ft_printf("hererererereA\n");

					pb(chaine, chaineB);
					headB = (*chaineB)->content;

				}
				else if (headA > headB)// at the top
				{
					pb(chaine, chaineB);
					headB = (*chaineB)->content;

				}
				else if (headA < lst_content(*chaineB)) // at the end 
				{
					//ft_printf("the head of B %d\n", headB);
				
					pb(chaine, chaineB);
					rb(chaineB, 1);
				headB = (*chaineB)->content;
				}
				 //if (headA < headB && headA < lst_content(*chaineB))//find the position 
				else
				{
					headB = (*chaineB)->content;

					ra_or_rra(headA, ft_lstsize(*chaineB), chaine, chaineB);
					headB = (*chaineB)->content;
					//ft_printf("the head of A %d the head of B %d\n", headA, headB);
					
				}
			}
			else //rotate < med
				ra(chaine, 1);
			tmp = (*chaine)->next;			
		}
		free(tab);
	}
	//rrb(chaineB, 1);
	// ft_printf("the stack B\n");
	// 		printl(*chaineB);
}

void ra_or_rra(int headA, int size, t_list **chaine,  t_list **chaineB)
{
	int	po;
	int	po2;
	int track;

	po = find_position(*chaineB, headA);
	
	po2 = po;
	
	if(po2 <= size / 2)//faire des rra
	{
	//ft_printf("the position of  A %d  and the size of b %d\n", po, size );
		track = po;
		while (po-- > 0)
			rb(chaineB, 1);
		pb(chaine, chaineB);
		while (track-- > 0)
			rrb(chaineB, 1);
	}
	else//fqire des rra
	{
	//ft_printf("ttttttttttttthe position of  A %d  and the size of b %d\n", po, size );
		
		track = po;
		while (po++ < size)
			rrb(chaineB, 1);
		pb(chaine, chaineB);
		while (track++ <= size)
			rb(chaineB, 1);
	}
	
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
	*/