/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:36:44 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/15 21:06:06 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_printlst(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

void	ft_sorter(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	while (ft_lstlen(*stack_a) > 3)
		ft_calcul_and_execute(stack_a, stack_b);
	ft_sortmin(stack_a, ft_lstlen(*stack_a));
	while (pos_max(*stack_b))
	{
		if (pos_max(*stack_b) > ft_lstlen(*stack_b) / 2)
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
	while (*stack_b)
		ft_final_placement(stack_b, stack_a);
	while (get_pos(*stack_a, who_is_min(*stack_a)))
	{
		if (get_pos(*stack_a, who_is_min(*stack_a)) > ft_lstlen(*stack_a) / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	//ft_printlst(*stack_a);
}


