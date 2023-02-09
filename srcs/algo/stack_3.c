/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:22:06 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/03 16:39:21 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void for_tree(t_list **stack)
{
	t_list	*chaine;

	chaine = *stack;
	int st;
	int nd;
	int rd;
	if (!chaine || !chaine->next || !chaine->next->next)
		return ;
	st = chaine->content;
	nd = chaine->next->content;
	rd = chaine->next->next->content;
	if (st < nd && st< rd && nd > rd)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (st < nd && nd > rd && rd < st)
		rra(stack, 1);
	else if (st > nd  && rd > nd && st < rd)
		sa(stack, 1);
	else if (st > nd && nd < rd && st > rd)
		ra(stack, 1);	
	else if (st > nd &&  nd > rd)
	{
			ra(stack, 1);
			sa(stack, 1);
	}
	update(stack);
}


int	the_min_index(t_list *chaine)
{
	t_list	*temp;
	int		idx;
	int		min;
	// int		i;

	if (!chaine)
		return(-1);
	temp = chaine;
	idx  = 1;
	// i = 1;
	min = temp->content;
	temp = temp->next;
	while (temp != NULL)
	{
		// i++;
		if (temp->content < min)
		{
			min = temp->content;
			idx = temp->index;
		}
		temp = temp->next;
	}
	return (idx);
	
}

void shuffle(t_list **stackA, t_list **stackB)
{
	
	while  (the_min_index(*stackA) != 1)
	{
		if (the_min_index(*stackA) < 4)
			{ra(stackA, 1);}
		else 
			rra(stackA, 1);
	}
	
	
	// ft_printf("the stack B;\n");
	pb(stackA, stackB);
	// printl(*stackB);
	// ft_printf("the stack A;\n");
	// printl(*stackA);
	// printl(*stackB);
}

void	for_five(t_list	**stackA, t_list **stackB)
{
	//t_list	*temp;

	//temp = *stackA;
	shuffle(stackA, stackB);
	shuffle(stackA, stackB);
	// // ft_printf("the stack Abefor;\n");
	// ft_printf("the stack B;\n");
	// ft_printf("here ;\n");
	//  printl(*stackA);

	for_tree(stackA);
	// // printl(*stackA);
	// // ft_printf("the stack B;\n");
	// // printl(*stackB);
	pa(stackB, stackA);
	pa(stackB, stackA);
}
/*
int main(int argc, char *argv[]){
	
	int *tab;
	t_list	*chaine;
    t_list	*chaineB;
	//t_list	*chaineB = NULL;
	
	if (argc == 1)
		return (write(2, "ERROR nothing to sort\n", 22), 0);
	if (tab_check(argv, argc - 1) == 0)
		return (0);
	else 
	{
		chaine = the_chaine(argc, argv);
		if (chaine == NULL)
			return(0);//erreur du malloc
		printl(chaine);
		//rra(&chaine, 1);
		//for_tree(&chaine);
		for_five(&chaine, &chaineB);
		// //sa(&chaine,1);
		 printl(chaine);
		tab = tab_of_list(chaine, argc - 1);
		for (int i = 0; i < argc - 1; i++)
		{
			ft_printf("%d _ ", tab[i]);
		}
		//  ft_printf("second stack\n");
		//  printl(chaineB);


	}

	// for_five(&chaine, &chaineB);
		
		//printl(chaine);
		//printl(chaineB);

		// if (is_sort(tmp_chaine))
		// 	return (0);
		// if (ft_lstsize(tmp_chaine) == 3)
		// 	for_tree(chaine);
	
}
*/