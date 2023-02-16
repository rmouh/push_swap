/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mychecker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:58:42 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/16 19:48:47 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mychecker.h"
#include "push_swap.h"


int	issorted(t_list **chaine)
{
	t_list	*temp;
	int		size;
	int		i;

	temp = *chaine;
	while (temp->next != NULL)
	{
		if (temp->next->content < temp->content)
		{
			ft_printf("KO\n");
			return (0);
		}
		temp = temp->next;
	}
	ft_printf("OK\n");
	return (1);
}

void	compare(t_list **chaine, t_list **chaineb, char *buf)
{
	if (ft_strncmp(buf, "ra"))
		ra(chaine, 0);
	else if (ft_strncmp(buf, "rb"))
		rb(chaineb, 0);
	else if (ft_strncmp(buf, "rra"))
		rra(chaine, 0);
	else if (ft_strncmp(buf, "rrb"))
		rrb(chaineb, 0);
	else if (ft_strncmp(buf, "rrr"))
		rrr(chaine, chaineb, 0);
	else if (ft_strncmp(buf, "rr"))
		rr(chaine, chaineb, 0);
	else if (ft_strncmp(buf, "sa"))
		sa(chaine, 0);
	else if (ft_strncmp(buf, "pa"))
		pa(chaine, chaineb, 0);
	else if (ft_strncmp(buf, "pb"))
		pb(chaine, chaineb, 0);
	else
	{
		if (ft_strlen(buf) != 0)
			ft_printf("KO\n");
		else
			issorted(chaine);
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
		{
			freee(chaine);
			return (0);
		}
		buf = get_next_line(0);
		while (buf)
		{
			ft_printf("%s", buf);
			buf = get_next_line(0);
			compare(&chaine, buf);
		}
	}
}
