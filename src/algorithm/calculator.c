/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:08 by rkerman           #+#    #+#             */
/*   Updated: 2025/02/19 14:35:24 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_min(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_a->value > stack_b->value)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int	position(t_stack *)

void	ft_calcul_lowcost(t_stack *stack_a, t_stack *stack_b, int *t)
{
	int		current;
	int		shotcount;

	while (stack_a)
	{
		if (is_min)
		{
			
		}
	}
}

void	ft_calcul_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	int	target;

	ft_calcul_lowcost(*stack_a, *stack_b, &target);
	//ft_execute();
}
