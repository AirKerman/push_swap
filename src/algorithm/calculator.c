/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:08 by rkerman           #+#    #+#             */
/*   Updated: 2025/02/20 15:42:18 by rkerman          ###   ########.fr       */
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

void	is_min_calcul(t_stack *stack_a, int i, int *sc, int *t)
{
	if (*i == 1)
		*t = stack_a->value;
	else if (!shotcount)
	{
		shotcount = ia;
		*t = stack_a->value;
	}
	else if (*i < *sc)
	{
		*sc = *i;
		*t = stack_a->value;
	}
}

void	ft_calcul_lowcost(t_stack *stack_a, t_stack *stack_b, int *t)
{
	int		shotcount;
	int		ia;
	//int		ib;

	ia = 0;
	shotcount = 0;
	while (stack_a)
	{
		ia++;
		if (is_min(stack_a, stack_b))
		{
			is_min_calcul(stack_a, ia, &shotcount, t);
			if (ia == 1)
				break ;
		}
		/*
		if (is_min(stack_a, stack_b))
		{
			is_min_calcul(stack_a, ia, &shotcount, t);
			
			if (ia == 1)
			{
				*t = stack_a->value;
				shotcount = ia;
				break ;
			}
			else if (!shotcount)
			{
				shotcount = ia;
				*t = stack_a->value;
			}
			else if (ia < shotcount)
			{
				shotcount = ia;
				*t = stack_a->value;
			}
		}*/
		stack_a = stack_a->next;
	}
}

void	ft_calcul_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	int	bullet;
	int	target;
	
	target = 0;
	ft_calcul_lowcost(*stack_a, *stack_b, &target);
	//ft_execute();
}
