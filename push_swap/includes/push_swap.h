/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:23:30 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 18:40:56 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

/*
	movs        
			*/
int		rra(t_list **chaine, int p);
int		rrb(t_list **chaine, int p);
int		rb(t_list **chaine, int p);
int		ra(t_list **chaine, int p);
int		sa(t_list **chaine, int p);
int		sb(t_list **chaine, int p);
int		rr(t_list **chaineA, t_list **chaineB, int p);
int		pa(t_list **chaineB, t_list **chaineA, int p);
int		pb(t_list **chaineA, t_list **chaineB, int p);
int		ss(t_list **chaineA, t_list **chaineB, int p);
int		rrr(t_list **chaineA, t_list **chaineB, int p);

/*  
	parser
			*/

t_list	*the_chaine(int argc, char *argv[]);

void	printl(t_list *chaine);
void	printll(t_list *chaine);
void	print_tab(int *tab, int size);

int		is_not_integer(char *src);
int		char_in(const char *str);
int		tab_check(char *argv[], int size);
int		is_sort(long long int tab[], int size);
int		is_duplicate(long long int tab[], int size);
int		is_out_of_range(long long int tab[], int size);
int		freee(t_list **lst);

/*  
	algos_Utils
				*/

void	shuffle(t_list **stackA, t_list **stackB);
int		the_min_index(t_list *chaine);
t_list	*update(t_list **chaine);
int		*tab_of_list(t_list *chaine, int size);
int		the_median(t_list **chaine);
void	swap(int *t1, int *t2);
int		*bubble_sort(int *tab, int size);
int		tab_size(int *tab);
void	each_time(t_list **chaine, t_list **chaineB);
void	ra_or_rra(int headA, int size, t_list **chaine, t_list **chaineB);
void	find_bok(t_list **chaine, t_list **chaineB);
int		find_the_cheaper(t_list **chaineB);
void	action(t_list **chaine, t_list **chaineB,
			int result, t_list *element);
void	the_median_algo(t_list **chaine, t_list **chaineB);
t_list	*the_min_of_b(t_list **chaineB);
int		the_max_of_a(t_list **chaine);
void	stabilizer(t_list **chaine);
void	if_do(int a_value, int b_value, t_list *temp_b, int i);
/*  
	algos
				*/
void	for_tree(t_list **chaine);
void	for_five(t_list	**stackA, t_list **stackB);
void	the_algo(t_list **chaine, t_list **chaineB);

/*  
	costs
			*/

int		ft_min(int ra, int rb);
int		ft_max(int ra, int rb);
int		ft_cost_of_up(int ra, int rb);
int		ft_cost_of_down(int rra, int rrb);
int		ft_cost_of_up_do(int ra, int rrb);
int		ft_cost_of_do_up(int rra, int rb);
int		the_costs(t_list *element, int sizeA, int sizeB);
int		ft_min_of_four(int one, int two, int tree, int four);
t_list	*cost_loop_and_min(t_list **chaine, t_list **chaineB);
void	the_min_cost(t_list *element, t_list **chaine, t_list **chaineB);
/*  
	down_up
			*/

void	fill_ell(t_list *element, int sizeA, int sizeB);
void	ft_do_up(t_list **chaine, t_list **chaineB, int nb_of_ra, int nb_rb);
void	ft_do_down(t_list **chaine, t_list **chaineB, int nb_rra, int nb_rrb);
void	ft_do_up_do(t_list **chaine, t_list **chaineB, int nb_ra, int nb_rrb);
void	ft_do_do_up(t_list **chaine, t_list **chaineB, int nb_rra, int nb_rb);

#endif
