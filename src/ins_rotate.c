/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:11:39 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/05 15:28:30 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **chainz, int trigger)
{	
	t_stack *tmp;
	t_stack	*head;

	if (*chainz && (*chainz)->next)
	{
		tmp = *chainz;
		tmp->next = NULL;
		*head = (*chainz)->next;
		while (*chainz && (*chainz)->next)
			*chainz = (*chainz)->next;
		(*chainz)->next = tmp;
		*chainz = head;
		if (trigger)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack **chainz, int trigger)
{
	t_stack *tmp;
	t_stack	*head;

	if (*chainz && (*chainz)->next)
	{
		tmp = *chainz;
		tmp->next = NULL;
		head = (*chainz)->next;
		while (*chainz && (*chainz)->next)
			*chainz = (*chainz)->next;
		(*chainz)->next = tmp;
		*chainz = head;
		if (trigger)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack **chainza, t_stack **chainzb)
{
	ra(chainza, 0);
	rb(chainzb, 0);
	write(1, "rr\n", 3);
}
