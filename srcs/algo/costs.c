/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:28:45 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/09 19:46:42 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost_of_up(int ra, int rb)
{
	if (ra > rb)
		return (ra);
	return (rb);
}
int	ft_min(int ra, int rb)
{
	if (ra < rb)
		return (ra);
	return (rb);
}

int	ft_cost_of_down(int rra, int rrb)
{
	if (rra > rrb)
		return (rra);
	return (rrb);
}

int	ft_cost_of_up_do(int ra, int rrb)
{
	return (rrb + ra);
}

int	ft_cost_of_do_up(int rra, int rb)
{
	return (rra + rb);
}