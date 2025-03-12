/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:36:44 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/12 16:31:54 by rkerman          ###   ########.fr       */
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
	while (*stack_a)
		ft_calcul_and_execute(stack_a, stack_b);
	ft_sortmin(stack_a, ft_lstlen(*stack_a));

	//ft_printlst(*stack_b);
	while (pos_max(*stack_b))
	{
		rb(stack_b, 1);
	}
	while (*stack_b)
		pa(stack_a, stack_b, 1);
	ft_printlst(*stack_a);
}


