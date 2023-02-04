/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:24:46 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/04 18:48:06 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printl(t_list *chaine)
{
	t_list	*temp;
	
	temp = chaine;
	while (temp != NULL)
	{
		printf("            [%d] --> %d\n", temp->index, (int)(temp->content));
		temp = temp->next;
	}
}

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
	if (ft_strcontain(src, ".") == 1 || char_in(src) == 1)
		return (1);
	return (0);
}
t_list	*update(t_list **chaine)
{
	t_list	*temp;
	int		counter;

	counter = 1;
	temp = *chaine;
	while (temp != NULL)
	{
		temp->index = counter;
		counter++;
		temp = temp->next;
	}
	return (*chaine);
	
}
void print_tab(int *tab, int size)
{
	for (int i = 0; i < size; i++)
		{
			ft_printf("t[%d] = %d \n", i, tab[i]);
		}
}


// int main(int argc, char *argv[]){
	
// 	//int *tab;
// 	t_list	*chaine;
// 	t_list	*tmp_chaine;
// 	//t_list	*chaineB = NULL;
	
// 	if (argc == 1)
// 		return (write(2, "ERROR nothing to sort\n", 22), 0);
// 	if (tab_check(argv, argc - 1) == 0)
// 		return (0);
// 	else 
// 	{
// 		chaine = the_chaine(argc, argv);
// 		if (chaine == NULL)
// 			return(0);//erreur du malloc
// 		tmp_chaine = chaine;
// 		printl(tmp_chaine);
// 		// if (is_sort(tmp_chaine))
// 		// 	return (0);
// 		// if (ft_lstsize(tmp_chaine) == 3)
// 		// 	for_tree(chaine);
// 	}
// }