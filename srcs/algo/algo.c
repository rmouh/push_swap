/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:00 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/12 19:14:57 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	the_min_cost(t_list *element, int sizeA, int sizeB, t_list **chaine, t_list **chaineB)
{
	int	up;
	int	down;
	int	up_do;
	int	do_up;
	
	// ft_printf("This is the comment\n");
	// printl(*chaine);
	fill_ell(element, sizeA, sizeB);
	//ft_printf("This is the comment2\n");
	up = ft_cost_of_up(element->ell.ra,element->ell.rb);
	down = ft_cost_of_down(element->ell.rra, element->ell.rrb);
	up_do = ft_cost_of_up_do(element->ell.ra,  element->ell.rrb);
	do_up = ft_cost_of_do_up(element->ell.rra, element->ell.rb);
	//printl(*chaine);
	if (up < down && up < up_do && up < do_up)
		ft_do_up(chaine, chaineB, element->ell.ra, element->ell.rb);
	else if (down < up && down < up_do && down < do_up)
		ft_do_down(chaine, chaineB, element->ell.rra, element->ell.rrb);
	else if (up_do < up && up_do < down && up_do < do_up)
		ft_do_up_do(chaine, chaineB, element->ell.ra, element->ell.rrb);
	else
		ft_do_do_up(chaine, chaineB, element->ell.rra, element->ell.rb);
}

int	the_costs(t_list *element, int sizeA, int sizeB)
{
	int	up;
	int	down;
	int	up_do;
	int	do_up;
	
	fill_ell(element, sizeA, sizeB);
	up = ft_cost_of_up(element->ell.ra,element->ell.rb);
	down = ft_cost_of_down(element->ell.rra, element->ell.rrb);
	up_do = ft_cost_of_up_do(element->ell.ra,  element->ell.rrb);
	do_up = ft_cost_of_do_up(element->ell.rra, element->ell.rb);
	element->lower_cost = ft_min_of_four(up, down, up_do, do_up);
	if (up < down && up < up_do && up < do_up)
		return (1);
	else if (down < up && down < up_do && down < do_up)
		return (2);
	else if (up_do < up && up_do < down && up_do < do_up)
		return (3);
	else
		return (4);
}

void action(t_list **chaine, t_list **chaineB, int result, t_list *element)
{
	if (result == 1)
		ft_do_up(chaine, chaineB, element->ell.ra, element->ell.rb);
	else if (result == 2)
		ft_do_down(chaine, chaineB, element->ell.rra, element->ell.rrb);
	else if (result == 3)
		ft_do_up_do(chaine, chaineB, element->ell.ra, element->ell.rrb);
	else
		ft_do_do_up(chaine, chaineB, element->ell.rra, element->ell.rb);
}

void the_median_algo(t_list **chaine, t_list **chaineB)
{
	int	med;
	int	found;
	
	found  = 0;
	med = the_median(chaine);
	// ft_printf("chaine A\n");
	// 	printll(*chaine);
	// 	ft_printf("chaine B\n");
	// 	printll(*chaineB);
	while (ft_lstsize(*chaine) > 3)
	{
		if ((*chaine)->content == med)
		{
			found++;
			if (found == 2)
			{
				pb(chaine, chaineB);
				med = the_median(chaine);
				found = 0;
			}
			else 
				ra(chaine, 1);
		}
		else if ((*chaine)->content < med)
			pb(chaine, chaineB);
		else
			ra(chaine, 1);
		// 			ft_printf("chaine A\n");
		// printll(*chaine);
		// ft_printf("chaine B\n");
		// printll(*chaineB);
	}
}

t_list	*the_min_of_b(t_list **chaineB)
{
	t_list 	*temp;
	t_list	*min;
	
	temp = (*chaineB);
	min = (*chaineB);
	while (temp->next != NULL)
	{
		if (temp->next->lower_cost < min->lower_cost)
			min = temp->next;
		temp = temp->next;
	}
	return (min);
}

int the_max_of_a(t_list **chaine)
{
	t_list 	*temp;
	int	max;
	
	temp = (*chaine);
	max = temp->content;
	while (temp->next != NULL)
	{
		if (temp->next->content > max)
			max = temp->next->content;
		temp = temp->next;
	}
	return (max);
}

int the_min_of_a(t_list **chaine)
{
	t_list 	*temp;
	int	max;
	
	temp = (*chaine);
	max = temp->content;
	while (temp->next != NULL)
	{
		if (temp->next->content < max)
			max = temp->next->content;
		temp = temp->next;
	}
	return (max);
}

t_list	*cost_loop_and_min(t_list **chaine, t_list **chaineB)
{
	t_list	*track;

	track = *chaineB;
	
	// printl(*chaineB);
	// ft_printf("chaine A\n");
	// printl(*chaine);
	find_bok(chaine, chaineB);
	while (track != NULL)
	{
		the_costs(track, ft_lstsize(*chaine), ft_lstsize(*chaineB));
		track = track->next;
	}
	return (the_min_of_b(chaineB));
}

void the_algo(t_list **chaine, t_list **chaineB)
{
	 t_list	*min;
	if (!*chaine)
		return ;
	the_median_algo(chaine, chaineB); // evry thing pushed to B
	for_tree(chaine);
	while (ft_lstsize(*chaineB) > 0)
	{
		min = cost_loop_and_min(chaine, chaineB);	// cost for all B + min cost
		//ft_printf(" MIN : [%d],it index [%d] the bok [%d], the bok index [%d] \n", min->content, min->index, min->ell.bok, min->ell.bok_index);
		the_min_cost(min, ft_lstsize(*chaine), ft_lstsize(*chaineB), chaine, chaineB);// act on the min 
		
	//printll(*chaine);
		//ft_printf("the size [%d]\n", ft_lstsize(*chaineB));
	}
	//stabilizer(chaine);
	// ft_printf("chainerrr A\n");
	// printll(*chaine);
	// ft_printf("chaine B\n");
	// printll(*chaineB);
}

void stabilizer(t_list **chaine)
{
	t_list *temp;
	int		before;
	int		after;
	int		size;
	int		i;

	temp = *chaine;
	while (temp->next != NULL)
	{
		before = temp->content;
		after = temp->next->content;
		if (after < before)
			break ;
		temp = temp->next;
	}
	size = ft_lstsize(temp);
	i = 0;
	if (size > (ft_lstsize(*chaine) / 2))
	{	
		while (i++ <= ft_lstsize(*chaine) - size)
			{
				ra(chaine, 1);}
	}
	else 
	{
		while (i++ < size - 1)
			rra(chaine, 1);
	}
	
}


int main(int argc, char *argv[]){
	
	t_list	*chaine ;
	t_list	*chaineB = NULL;
	
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
		// chaineB = the_chaine(argc, argv);
		// ft_lstadd_front(&chaineB, ft_lstnew( 1, 1));
		// ft_lstadd_front(&chaineB, ft_lstnew( 2, 2));
		// ft_lstadd_front(&chaineB, ft_lstnew( 10, 3));
		// ft_lstadd_front(&chaineB, ft_lstnew( 14, 4));
		// ft_lstadd_front(&chaineB, ft_lstnew( 44, 5));
		// update (&chaineB);


		// find_bok(&chaine, &chaineB);
		// ft_printf("chaine A\n");
		// printl(chaine);
		// ft_printf("chaine B\n");
		// printl(chaineB);
		// printl(chaineB);
		// ft_printf("end\n");

		// ft_printf("the cheaper %d \n", find_the_cheaper(&chaineB));
		the_algo(&chaine, &chaineB);
		
		// printll(chaineB);
		// find_bok(&chaineB, &chaine);
		// ft_printf("chaine B\n");
		
		// printl(chaineB);
		// ft_printf("chaine A\n");
		// printl(chaine);
		stabilizer(&chaine);
		// ft_printf("chaine after st A\n");
		// printl(chaine);
		// ft_printf("chaine A\n");
		// ft_printf("chaine B\n");
		// printl(chaineB);


		// printl(chaineB);
		// ft_printf("end\n");
		
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
// int	ra_cost(t_list **chaineB, int value)
// {
// 	t_list	*track;
// 	int		size;

// 	size = ft_lstsize(*chaineB);
// 	track = *chaineB;
	
// 	while (track!= NULL)
// 	{
// 		track->ell.ra = track->index - 1;
// 		track->ell.rra = size - track->index;
// 		track
// 	}
// }
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
// int before_lst_content (t_list *chaineB)
// {
// 	t_list *temp;
// 	t_list	*chaine;
	
// 	chaine = chaineB;
// 	temp = ft_beforlast(chaine);
// 	return (temp->content);
// }

// int lst_content (t_list *chaineB)
// {
// 	t_list *temp;
// 	t_list	*chaine;
	
// 	chaine = chaineB;
// 	temp = ft_lstlast(chaine);
// 	return (temp->content);
// }

// int find_position(t_list *chaineB, int value)
// {
// 	t_list	*tmp;
// 	int		position;
	
// 	position = 0;
// 	tmp = chaineB;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->content < value)
// 			return (position);
// 		position++;
// 		tmp = tmp->next;
// 	}
// 	return (position);
// }
	*/