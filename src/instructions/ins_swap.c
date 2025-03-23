/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:01:24 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/23 14:01:30 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = (*stack);
		*stack = tmp;
	}
}

void	sa(t_stack **stack, int trigger)
{
	swap(stack);
	if (trigger)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack, int trigger)
{
	swap(stack);
	if (trigger)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int trigger)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (trigger)
		write(1, "ss\n", 3);
}
