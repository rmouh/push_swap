/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:24:46 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/02 15:01:15 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **chaine, int p)
{
	t_list	*temp;

	if ((*chaine)->next == NULL || *chaine == NULL)
		return (0); // do nothing
	temp = ft_beforlast(*chaine);
	ft_lstadd_front(chaine, ft_lstnew(temp->next->content, 1));
	free(temp->next);
	temp->next = NULL;
	if (p)
		ft_printf("rra\n");
	update(chaine);
	return (1);
}

int	rrb(t_list **chaine, int p)
{
	t_list	*temp;

	if ((*chaine)->next == NULL || *chaine == NULL)
		return (0); // do nothing
	temp = ft_beforlast(*chaine);
	ft_lstadd_front(chaine, ft_lstnew(temp->next->content, 1));
	free(temp->next);
	temp->next = NULL;
	if(p)
		ft_printf("rrb\n");
	update(chaine);
	return (1);
}

int	rrr(t_list **chaineA, t_list **chaineB)
{
	if(rra(chaineA, 0) && rrb(chaineB, 0))
	{
		ft_printf("rrr\n");
		return (0);

	}
	return (0);
}

int	freee(t_list **lst)
{
	t_list	*track;
	t_list	*nextt;

	track = *lst;
	*lst = NULL;
	while (track != NULL)
	{
		nextt = track->next;
		free(track);
		track = nextt;
	}
	return (1);
}
/*
int main(int argc, char *argv[])
{
	t_list *list;
	t_list *list_temp;
	//t_list	*result;


	list = the_chaine(argc, argv);
	list_temp = list;
	printl(list);
	printf("\n");
	rra(&list_temp);
	printl(list_temp);
	//freee(&list);
	freee(&list_temp);
	

	// t_list	*chaine ;
	// chaine = ft_lstnew (1);
	
	// ft_lstadd_back(&chaine, ft_lstnew(2));
	// //printf("%s \n %s", (char *)(chaine->next->content), (char *)chaine->content);
	 
	// ft_lstadd_back(&chaine, ft_lstnew(3));
	// ft_lstadd_back(&chaine, ft_lstnew(4));
	// ft_lstadd_back(&chaine, ft_lstnew(5));
	// ft_lstadd_back(&chaine, ft_lstnew(6));
	// pa(&list_temp, &chaine);
	// printl(list_temp);
	// printf("\n");
	// printl(chaine);


}
*/