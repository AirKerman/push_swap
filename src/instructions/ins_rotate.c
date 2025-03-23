/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:11:39 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/23 13:59:53 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		head = (*stack)->next;
		while (*stack && (*stack)->next)
			*stack = (*stack)->next;
		tmp->next = NULL;
		(*stack)->next = tmp;
		*stack = head;
	}
}

void	ra(t_stack **stack, int trigger)
{
	rotate(stack);
	if (trigger)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack, int trigger)
{
	rotate(stack);
	if (trigger)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int trigger)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (trigger)
		write(1, "rr\n", 3);
}
