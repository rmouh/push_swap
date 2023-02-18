/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mychecker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:47:30 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/02/18 12:48:11 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYCHECKER_H
# define MYCHECKER_H
# include "push_swap.h"

int		issorted(t_list **chaine, t_list **chaineb, char *buf);
void	compare(t_list **chaine, t_list **chaineb, char *buf);
int		myexit(char *buf, t_list **chaine, t_list **chaineb);

#endif
