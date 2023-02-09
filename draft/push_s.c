/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:59:15 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/09 16:30:37 by rmouhoub         ###   ########.fr       */
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

