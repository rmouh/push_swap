/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:03:00 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/18 19:23:08 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_median_algo(t_list **chaine, t_list **chaineb)
{
	int	med;
	int	found;

	found = 0;
	med = the_median(chaine);
	while (ft_lstsize(*chaine) > 3)
	{
		if ((*chaine)->content == med)
		{
			found++;
			if (found == 2)
			{
				pb(chaine, chaineb, 1);
				med = the_median(chaine);
				found = 0;
			}
			else
				ra(chaine, 1);
		}
		else if ((*chaine)->content < med)
			pb(chaine, chaineb, 1);
		else
			ra(chaine, 1);
	}
}

t_list	*cost_loop_and_min(t_list **chaine, t_list **chaineb)
{
	t_list	*track;

	track = *chaineb;
	find_bok(chaine, chaineb);
	while (track != NULL)
	{
		the_costs(track, ft_lstsize(*chaine), ft_lstsize(*chaineb));
		track = track->next;
	}
	return (the_min_of_b(chaineb));
}

void	the_algo(t_list **chaine, t_list **chaineb)
{
	t_list	*min;

	if (!*chaine)
		return ;
	the_median_algo(chaine, chaineb);
	for_tree(chaine);
	while (ft_lstsize(*chaineb) > 0)
	{
		min = cost_loop_and_min(chaine, chaineb);
		the_min_cost(min, chaine, chaineb);
	}
}

void	stabilizer(t_list **chaine)
{
	t_list	*temp;
	int		size;
	int		i;

	temp = *chaine;
	while (temp->next != NULL)
	{
		if (temp->next->content < temp->content)
			break ;
		temp = temp->next;
	}
	size = ft_lstsize(temp);
	i = 0;
	if (size > (ft_lstsize(*chaine) / 2))
	{	
		while (i++ <= ft_lstsize(*chaine) - size)
			ra(chaine, 1);
	}
	else
	{
		while (i++ < size - 1)
			rra(chaine, 1);
	}
}

// int	main(int argc, char *argv[])
// {
// 	t_list	*chaine ;
// 	t_list	*chaineb;

// 	chaineb = NULL;
// 	if (argc == 1)
// 		return (write(2, "ERROR\n", 6), 0);
// 	if (tab_check(argv, argc - 1) == 0)
// 		return (0);
// 	else
// 	{
// 		chaine = the_chaine(argc, argv);
// 		if (chaine == NULL)
// 			return (write(2, "ERROR\n", 6), 0);
// 		the_algo(&chaine, &chaineb);
// 		stabilizer(&chaine);
// 		freee(&chaine);
// 	}
// }
