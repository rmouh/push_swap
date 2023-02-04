/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:05:14 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/04 20:04:31 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*find the min and return it index */


int	the_min_index(t_list *chaine)
{
	int	idx;
	int min;
	int	i;

	if (!chaine)
		return(-1);
	idx  = 0;
	i = 0;
	min = chaine->content;
	chaine = chaine->next;
	while (chaine != NULL)
	{
		i++;
		if (chaine->content < min)
		{
			min = chaine->content;
			idx = i;
		}
		chaine = chaine->next;
	}
	return (idx);
	
}
int	the_min_value(t_list *chaine)
{
	int min;

	if (!chaine)
		return(-1);
	min = chaine->content;
	chaine = chaine->next;
	while (chaine != NULL)
	{
		if (chaine->content < min)
		{
			min = chaine->content;
		}
		chaine = chaine->next;
	}
	return (min);
	
}

t_list *push(t_list *pushed_out, t_list * pushed_in, int idx)
{
	t_list	*temp;

	while (idx >= 0)
	{
		temp = ft_lstlast_free(pushed_out);
		ft_lstadd_back(&pushed_in, temp);
		idx--;
	}
	return (pushed_in);
}

int	char_in(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}
 

int is_not_integer(char *src)
{
	if (ft_strcontain(src, ".") == 1  || char_in(src) == 1)
	{
		printf("ERROR\n");
		return (1);
	}
	return (0);
}

// void the_min_stack(t_list chaine1, t_list chaine2)
// {
// 	int min;

// 	min = the_min_value(chaine1);
	
	
// }

void triselection(int T[], int n){
    int val;
    int temp;
    int counter= 0;
    for (int i =n-1; i>0 ; i--){
        int index = 0;
        val=T[0];
        for(int j=1;j<=i; j++){
            if (T[j]>val ){
                index=j;
                val =T[j];
            } 
        }temp = index;
        while (temp != i)
        {   
            temp++;
            counter++;

        }
        T[index]=T[temp];
        T[temp]=val;
    }
    printf("\nle %d\n", counter);

}


void for_tree(t_list *chaine)
{
	int st;
	int nd;
	int rd;
	if (!chaine || !chaine->next || !chaine->next->next)
		return ;

	st = chaine->content;
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

t_list	*the_chaine(int argc, char *argv[])
{
	int		nb;
	t_list	*chaine;
	t_list	*track;

	nb = 1;
	chaine = ft_lstnew(ft_atoi(argv[nb]));
	while (++nb < argc)
	{
		if (is_not_integer(argv[nb]))
			return (0);
		track = chaine;
		while (track != NULL)
		{
			if (track->content == ft_atoi(argv[nb]))
			{
				ft_printf("there is a duplicat\n ");
				return (0);
			}
			track = track->next;
		}
		ft_lstadd_back(&chaine, ft_lstnew((ft_atoi(argv[nb]))));
	}
	return(chaine);
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
// int	duplicat(t_list *c)
// {
// 	t_list	*tmp;

// 	tmp = c;
// 	while (c != NULL)
// 	{
// 		while ()
		
// 	}
// }


// int main(int argc, char *argv[]){
	
// 	int *tab;
// 	t_list	*chaine;
// 	t_list	*tmp_chaine;
// 	//t_list	*chaineB = NULL;
	
// 	// if (argc == 1)
// 	// {
// 	// 	printf("Nothing to sort");
// 	// 	return (0);
// 	// }
	
// 	chaine = the_chaine(argc, argv);
// 	if (chaine == NULL)
// 		return(0);
// 	tmp_chaine = chaine;
// 	printl(chaine);
// 	if (is_sort(tmp_chaine))
// 		return (0);
// 	if (ft_lstsize(tmp_chaine) == 3)
// 		for_tree(chaine);
		
		
	//int	tab[ft_lstsize(tmp_chaine)];
	//tab = chaine_to_tab (tmp_chaine, ft_lstsize(tmp_chaine));
	
	// int	i;

	// i = 0;
	// while (tmp_chaine != NULL)
	// {
	// 	tab[i] = (int)(tmp_chaine->content);
	// 	tmp_chaine = tmp_chaine->next;
	// 	i++;
	// }
	// int j =0;
	// while (tab[j])
	// {
	// 	printf("%d\n",tab[j] );
	// 	j++;	
	// }
	//int min = the_min_index(chaine);
	//printf("the min is :%d\n", min);
	// t_list *t =ft_lstlast_free(tmp_chaine);
	// printf("the content of the last element  is :%d\n", t->content);
	// printl(tmp_chaine);
	//printf("the pushed in list\n");
	//printl(push(tmp_chaine, chaineB, min));
	
}