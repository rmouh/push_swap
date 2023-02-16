/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:59:15 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 13:32:38 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



int	char_in(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (1);
		else if (str[i] == '-' && (str[i+1] < '0' || str[i+1] > '9'))
			return (1);
		else 
			i++;
	}
	return (0);
}
 

int is_not_integer(char *src)
{
	if (ft_strcontain(src, ".") == 1  || char_in(src) == 1)
		return (1);
	return (0);
}

int	is_sort(t_list *c)
{
	while (c->next != NULL)
	{
		if (c->content >= (c->next)->content)
			return (0);
		c = c->next;
	}
	return (1);
}

int is_duplicate(t_list	*chaine, int c)
{
	
	t_list	*track;

	track = chaine;
		while (track != NULL)
		{
			if (track->content == c)
			{
				//ft_printf("there is a duplicat\n ");
				return (1);
			}
			track = track->next;
		}
		return (0);
}

t_list	*the_chaine(int argc, char *argv[])
{
	int		nb;
	t_list	*chaine;
	long int	n;

	nb = 1;
	n = ft_atoi(argv[nb]);
	if(nb < -2147483648 || nb > 2147483647)
		return (write(2, "ERROR\n", 6), NULL);
	chaine = ft_lstnew(ft_atoi(argv[nb]), );
	if (is_not_integer(argv[nb]))
		return (write(2, "ERROR\n", 6), NULL);//doit free
	while (++nb < argc)
	{
		if (is_not_integer(argv[nb]) || is_duplicate(chaine, ft_atoi(argv[nb])))
			return (write(2, "ERROR\n", 6),  NULL);//doit free
		ft_lstadd_back(&chaine, ft_lstnew((ft_atoi(argv[nb]))));
	}
	return(chaine);
}


void for_tree(t_list *chaine)
{
	int st;
	int nd;
	int rd;
	if (!chaine || !chaine->next || !chaine->next->next)
		return ;

	st = (int)chaine->content;
	nd = chaine->next->content;
	rd = chaine->next->next->content;
	if (st < nd && st< rd)
		ft_printf("sa\nra\n");
	else if (st < nd && st > rd)
		ft_printf("rra\n");
	else if (st > nd && st < rd)
			ft_printf("sa\n");
	else if (nd < rd && st > nd)
			ft_printf("ra\n");
	else if (st > nd && nd > rd)
		ft_printf("sa\nrra\n");
}

int	tab_check(char *argv[], int size)
{
	long int tab[size];

	while(size > 0)
	{
		tab[size - 1] = argv[size];
		size--;
	}
}

int main(int argc, char *argv[]){
	
	//int *tab;
	t_list	*chaine;
	t_list	*tmp_chaine;
	//t_list	*chaineB = NULL;
	
	if (argc == 1)
	{
		printf("Nothing to sort");
		return (0);
	}
	
	chaine = the_chaine(argc, argv);
	if (chaine == NULL)
		return(0);//erreur du malloc
	tmp_chaine = chaine;
	printl(chaine);
	if (is_sort(tmp_chaine))
		return (0);
	if (ft_lstsize(tmp_chaine) == 3)
		for_tree(chaine);
}
/*
		//erreur du malloc
		//printl(chaine);
		//rra(&chaine, 1);
		// chaineb = the_chaine(argc, argv);
		// ft_lstadd_front(&chaineb, ft_lstnew( 1, 1));
		// ft_lstadd_front(&chaineb, ft_lstnew( 2, 2));
		// ft_lstadd_front(&chaineb, ft_lstnew( 10, 3));
		// ft_lstadd_front(&chaineb, ft_lstnew( 14, 4));
		// ft_lstadd_front(&chaineb, ft_lstnew( 44, 5));
		// update (&chaineb);
		// find_bok(&chaine, &chaineb);
		// ft_printf("chaine A\n");
		// printl(chaine);
		// ft_printf("chaine B\n");
		// printl(chaineb);
		// printl(chaineb);
		// ft_printf("end\n");

		// ft_printf("the cheaper %d \n", find_the_cheaper(&chaineb));
		// printll(chaineb);
		// find_bok(&chaineb, &chaine);
		// ft_printf("chaine B\n");
		// printl(chaineb);
		// ft_printf("chaine A\n");
		// printl(chaine);
		// ft_printf("chaine after st A\n");
		// printl(chaine);
		// ft_printf("chaine A\n");
		// ft_printf("chaine B\n");
		// printl(chaineb);
		// printl(chaineb);
		// ft_printf("end\n");
		// //sa(&chaine,1);
	//	print_tab(tab, argc - 1);
	//	print_tab(bubble_sort(tab, argc - 1), argc - 1);
		// each_time(&chaine, &chaineb);
		// //for_five(&chaine, &chaineb);
		// for_tree(&chaine);
		// while ( ft_lstsize(chaineb) > 0)
		// 	pa(&chaineb, &chaine);
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
		// freee(&chaineb);
*/
}

/*
// int	ra_cost(t_list **chaineb, int value)
// {
// 	t_list	*track;
// 	int		size;

// 	size = ft_lstsize(*chaineb);
// 	track = *chaineb;
	
// 	while (track!= NULL)
// 	{
// 		track->ell.ra = track->index - 1;
// 		track->ell.rra = size - track->index;
// 		track
// 	}
// }
void each_time(t_list **chaine, t_list **chaineb)
{
	int		*tab;
	int		size_A;
	int		med;
	int		headA;
	int		headB;
	t_list	*tmp;
	// int		po;
	// int		po2;

	//(void )chaineb;
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
			// printl(*chaineb);
			headA = (*chaine)->content;
			//ft_printf("the head of A %d\n", headA);
			if (headA > med) // > med
			{
				if (ft_lstsize(*chaineb) == 0)
				{
					//ft_printf("hererererereA\n");

					pb(chaine, chaineb);
					headB = (*chaineb)->content;

				}
				else if (headA > headB)// at the top
				{
					pb(chaine, chaineb);
					headB = (*chaineb)->content;

				}
				else if (headA < lst_content(*chaineb)) // at the end 
				{
					//ft_printf("the head of B %d\n", headB);
				
					pb(chaine, chaineb);
					rb(chaineb, 1);
				headB = (*chaineb)->content;
				}
				 //if (headA < headB && headA < lst_content(*chaineb))//find the position 
				else
				{
					headB = (*chaineb)->content;

					ra_or_rra(headA, ft_lstsize(*chaineb), chaine, chaineb);
					headB = (*chaineb)->content;
					//ft_printf("the head of A %d the head of B %d\n", headA, headB);
					
				}
			}
			else //rotate < med
				ra(chaine, 1);
			tmp = (*chaine)->next;			
		}
		free(tab);
	}
	//rrb(chaineb, 1);
	// ft_printf("the stack B\n");
	// 		printl(*chaineb);
}

void ra_or_rra(int headA, int size, t_list **chaine,  t_list **chaineb)
{
	int	po;
	int	po2;
	int track;

	po = find_position(*chaineb, headA);
	
	po2 = po;
	
	if(po2 <= size / 2)//faire des rra
	{
	//ft_printf("the position of  A %d  and the size of b %d\n", po, size );
		track = po;
		while (po-- > 0)
			rb(chaineb, 1);
		pb(chaine, chaineb);
		while (track-- > 0)
			rrb(chaineb, 1);
	}
	else//fqire des rra
	{
	//ft_printf("ttttttttttttthe position of  A %d  and the size of b %d\n", po, size );
		
		track = po;
		while (po++ < size)
			rrb(chaineb, 1);
		pb(chaine, chaineb);
		while (track++ <= size)
			rb(chaineb, 1);
	}
	
}
// void each_time(t_list **chaine, t_list **chaineb)
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
// 						if (ft_lstsize((*chaineb)) > 0)
// 						{
// 							compare = (*chaineb)->content;
// 							if (compare > (*chaine)->content)
// 								{pb(chaine, chaineb);
// 								ra(chaineb, 1);}
// 							else 
// 								pb(chaine, chaineb);
// 						}
// 						//pb(chaine, chaineb);
// 						sorted = tab_of_list((*chaine), ft_lstsize((*chaine)));
// 						med = median(sorted);
// 						ft_printf(">= MEDIANE = %i SIZE %i\n", med, ft_lstsize(*chaine));
// 						found = 0;
// 						//return ;
// 					}
// 					else
// 						ra(chaine, 1);
// 					ft_printf("the stack B\n");
// 					printl(*chaineb);
// 				}
// 				else
// 				{
// 						if (ft_lstsize((*chaineb)) > 0)
// 						{
// 		    				compare = (*chaineb)->content;
// 							if (compare < (*chaine)->content && (*chaine)->content < lst_content(*chaineb)) // cas : is bigger ->at the top
// 								pb(chaine, chaineb);
// 							else if (compare > (*chaine)->content && (*chaine)->content < lst_content(*chaineb)) //need to find the position
// 								{
// 									int po = find_position(*chaineb, (*chaine)->content);
// 									while (po-- > 0)
// 										rb(chaineb, 1);
// 									pb(chaine, chaineb);
// 								}
// 							else if (compare > (*chaine)->content && (ft_lstsize((*chaineb)) == 1 || lst_content (*chaineb) > (*chaine)->content))
// 							{// is smaller then the last or  2 elements cas 
// 								ft_printf("head of B: %d head of A: %d B size : %d lst element of B: %d\n", compare, (*chaine)->content, ft_lstsize((*chaineb)), lst_content (*chaineb));
// 								pb(chaine, chaineb);
// 								ra(chaineb, 1);
// 							}
// 							else//need to find the position
// 								{
// 									int po = find_position(*chaineb, (*chaine)->content);
// 									while (po-- > 0)
// 										rb(chaineb, 1);
// 									pb(chaine, chaineb);
// 								}
// 						}
// 						else
// 						{
// 							pb(chaine, chaineb);
// 						}
// 					ft_printf("the stack B\n");
// 					printl(*chaineb);
// 				}
// 			}
// 			else
// 				ra(chaine, 1);
// 			ft_printf("the stack A\n");
// 			printl((*chaine));
// 			ft_printf("the stack B\n");
// 			printl(*chaineb);
// 			//pb(chaine, chaineb);
// }
// }
// int before_lst_content (t_list *chaineb)
// {
// 	t_list *temp;
// 	t_list	*chaine;
	
// 	chaine = chaineb;
// 	temp = ft_beforlast(chaine);
// 	return (temp->content);
// }

// int lst_content (t_list *chaineb)
// {
// 	t_list *temp;
// 	t_list	*chaine;
	
// 	chaine = chaineb;
// 	temp = ft_lstlast(chaine);
// 	return (temp->content);
// }

// int find_position(t_list *chaineb, int value)
// {
// 	t_list	*tmp;
// 	int		position;
	
// 	position = 0;
// 	tmp = chaineb;
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








































// int	*chaine_to_tab(t_list *chaine, int l_size)
// {
// 	int	tab[l_size];
// 	int	i;

// 	i = 0;
// 	while (chaine != NULL)
// 	{
// 		tab[i] = (int)(chaine->content);
// 		chaine = chaine->next;
// 		i++;
// 	}
// 	return (tab);
// }

