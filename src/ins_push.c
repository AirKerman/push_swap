/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:57:57 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/05 15:11:23 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stackb, t_stack **stacka)
{
	t_stack *tmp;

	if (*stackb)
	{
		tmp = *stackb;
		*stackb = (*stackb)->next;
		tmp->next = *stacka;
		*stacka = tmp;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmp;

	if (*stacka)
	{
		tmp = *stacka;
		*stacka = (*stacka)->next;
		tmp->next = *stackb;
		*stackb = tmp;
		write(1, "pb\n", 3);
	}
}
