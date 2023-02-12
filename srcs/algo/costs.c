/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:28:45 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/12 12:11:09 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost_of_up(int ra, int rb)
{
	return (ft_max(ra, rb));
}
int	ft_min(int ra, int rb)
{
	if (ra < rb)
		return (ra);
	return (rb);
}
int	ft_min_of_four(int one, int two, int tree, int four)
{
	if (one < two && one < tree && one < four)
		return (one);
	else if (two < one && two < tree && two < four)
		return (two);
	else if (tree < one && tree < two && tree < four)
		return (tree);
	else
		return (four);
}

int	ft_max(int ra, int rb)
{
	if (ra > rb)
		return (ra);
	return (rb);
}

int	ft_cost_of_down(int rra, int rrb)
{
	return (ft_max(rra, rrb));
}

int	ft_cost_of_up_do(int ra, int rrb)
{
	return (rrb + ra);
}

int	ft_cost_of_do_up(int rra, int rb)
{
	return (rra + rb);
}