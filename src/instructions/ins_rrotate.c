/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:29:33 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/23 14:00:49 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		while (*stack && (*stack)->next && (*stack)->next->next)
			*stack = (*stack)->next;
		head = (*stack)->next;
		head->next = tmp;
		(*stack)->next = NULL;
		*stack = head;
	}
}

void	rra(t_stack **stack, int trigger)
{
	reverse_rotate(stack);
	if (trigger)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack, int trigger)
{
	reverse_rotate(stack);
	if (trigger)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int trigger)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (trigger)
		write(1, "rrr\n", 4);
}
