/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:04:48 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/03 18:08:11 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"



/*
	movs        
			*/
int		rra(t_list **chaine, int p);
int		rrb(t_list **chaine, int p);
int	    rrr(t_list **chaineA, t_list **chaineB);
int		rb(t_list **chaine, int p);
int		ra(t_list **chaine, int p);
int	    rr(t_list **chaineA, t_list **chaineB);
int		pa(t_list **chaineB, t_list **chaineA);
int	    pb(t_list **chaineA, t_list **chaineB);
int		sb(t_list **chaine, int p);
int		sa(t_list **chaine, int p);
int	    ss(t_list **chaineA, t_list **chaineB);

/*  
	parser
			*/

void	printl(t_list *chaine);
int	    char_in(const char *str);
int     is_not_integer(char *src);
int     is_sort(long long int tab[], int size);
int     is_out_of_range(long long int tab[], int size);
int     is_duplicate(long long int tab[], int size);
int	    tab_check(char *argv[], int size);
void	print_tab(int *tab, int size);





t_list	*the_chaine(int argc, char *argv[]);
int	    freee(t_list **lst);

/*  
	algos
			*/

void	for_five(t_list	**stackA, t_list **stackB);
void	shuffle(t_list **stackA, t_list **stackB);
int		the_min_index(t_list *chaine);
void	for_tree(t_list **chaine);
t_list	*update(t_list **chaine);
int		*tab_of_list(t_list *chaine, int size);
int		median(int *tab);
void 	swap(int *t1, int *t2);
int		*bubble_sort(int *tab, int size);
int 	tab_size(int *tab);
void 	each_time(t_list **chaine, t_list **chaineB);






