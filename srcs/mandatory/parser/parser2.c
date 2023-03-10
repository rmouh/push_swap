/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:19:01 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/18 19:03:07 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(long long int tab[], int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] >= tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_out_of_range(long long int tab[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] < -2147483648 || tab[i] > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

t_list	*the_chaine(int argc, char *argv[])
{
	int		nb;
	t_list	*chaine;

	nb = 1;
	chaine = ft_lstnew(ft_atoi(argv[nb]), nb);
	if (!chaine)
		return (NULL);
	if (argv[nb][0] == '\0')
	{
		freee (&chaine);
		return (0);
	}
	while (++nb < argc)
	{
		if (argv[nb][0] == '\0')
		{
			freee(&chaine);
			return (0);
		}
		ft_lstadd_back(&chaine, ft_lstnew(ft_atoi(argv[nb]), nb));
	}
	return (chaine);
}

int	is_duplicate(long long int tab[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	tab_check(char *argv[], int size)
{
	long long int	*tab;
	int				i;

	i = 0;
	tab = ft_calloc_tab(size, sizeof(long long int));
	while (i < size)
	{
		if (is_not_integer(argv[i + 1]))
			return (free (tab), write(2, "ERROR\n", 6), 0);
		tab[i] = ft_atoi_long(argv[i + 1], tab);
		i++;
	}
	if (is_out_of_range(tab, size) || is_duplicate(tab, size))
		return (free (tab), write(2, "ERROR\n", 6), 0);
	if (is_sort(tab, size))
	{
		free (tab);
		exit(1);
	}
	free (tab);
	return (1);
}
