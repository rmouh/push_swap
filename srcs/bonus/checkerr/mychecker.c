/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mychecker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:58:42 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/18 19:37:58 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker.h"
#include "push_swap.h"

// void test(t_list *ptr)
// {
// 	t_list	*temp;

// 	while (ptr)
// 	{
// 		temp = ptr -> next;
// 		free(ptr);
// 		ptr = temp;
// 	}
// }

int	myexit(char *buf, t_list **chaine, t_list **chaineb)
{
	//test(*chaine);
	//test(*chaineb);
	// printl(*chaine);
	ft_printf("ptr: %p\n", *chaine);
	freee(chaine);
	freee(chaineb);
	free(buf);
	exit(0);
}

int	issorted(t_list **chaine, t_list **chaineb, char *buf)
{
	t_list	*temp;

	temp = *chaine;
			printl(*chaine);
	while (temp && temp->next != NULL)
	{
		if (temp->next->content < temp->content)
		{
			ft_printf("KO\n");
			myexit(buf, chaine, chaineb);
		}
		temp = temp->next;
	}
	ft_printf("OK\n");
	myexit(buf, chaine, chaineb);
	return (1);
}

void	compare(t_list **chaine, t_list **chaineb, char *buf)
{
	if (ft_strncmp(buf, "ra\n"))
		ra(chaine, 0);
	else if (ft_strncmp(buf, "rb\n"))
		rb(chaineb, 0);
	else if (ft_strncmp(buf, "rra\n"))
		rra(chaine, 0);
	else if (ft_strncmp(buf, "rrb\n"))
		rrb(chaineb, 0);
	else if (ft_strncmp(buf, "rrr\n"))
		rrr(chaine, chaineb, 0);
	else if (ft_strncmp(buf, "rr\n"))
		rr(chaine, chaineb, 0);
	else if (ft_strncmp(buf, "sa\n"))
		sa(chaine, 0);
	else if (ft_strncmp(buf, "pa\n"))
		pa(chaineb, chaine, 0);
	else if (ft_strncmp(buf, "pb\n"))
		pb(chaine, chaineb, 0);
	else
	{
		if (buf && *buf)
		{
			ft_printf("tettenejkwef\n");
			get_next_line(1, 1);
			myexit (buf, chaine, chaineb);
		}
	}
}

int	main(int argc, char *argv[])
{
	char	*buf;
	t_list	*chaine;
	t_list	*chaineb;

	chaineb = NULL;
	if (argc == 1)
		return (write(2, "ERROR\n", 6), 0);
	if (tab_check(argv, argc - 1) == 0)
		return (0);
	else
	{
		chaine = the_chaine(argc, argv);
		if (chaine == NULL)
			return (0);
		buf = get_next_line(0, 0);
		while (buf)
		{
			//ft_printf("%s", buf);
			compare(&chaine, &chaineb, buf);
			free(buf);
			buf = get_next_line(0, 0);
			// freee(&chaine);
		}
		get_next_line(1,1);
		issorted(&chaine, &chaineb, buf);
		//test(chaine);
		//free(buf);
	}
}
