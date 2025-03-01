/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:08 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/01 21:04:52 by rkerman          ###   ########.fr       */
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

int	is_max(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_a < stack_b)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int	pos_max(t_stack *stack)
{
	int	max_pos;
	int	i;
	int	max;

	i = 0;
	max = stack->value;
	while (stack)
	{
		i++;
		if (stack->value > max)
		{
			max = stack->value;
			max_pos = i;
		}
		i++
		stack = stack->next;
	}
	return (max_pos);
}
/*
void	is_min_or_max_calcul(t_stack *stack_a, t_stack *stack_b, t_data *p, int i)
{
	if (is_max(stack_a, stack_b))
	{
		
	}
	else if (is_min(stack_a, stack_b))
	{
		
	}
}
*/
void	panel_init(t_stat *panel)
{
	panel->shotcount = 0;
	panel->target = 0;
	panel->bullet = 0;
}

void	ft_calcul_lowcost(t_stack *stack_a, t_stack *stack_b)
{
	int		ia;
	
	ia = 0;
	while (stack_a)
	{
		if (is_min(stack_a, stack_b) || is_max(stack_a, stack_b))
			return ;//is_min_or_max_calcul(stack_a, stack_b, panel, ia);
		else
		{
			
		}
		ia++;
		stack_a = stack_a->next;
	}
}

void	ft_calcul_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	t_stat panel;

	panel_init(&panel);
	printf("%d\n", pos_max(*stack_a));
	printf("%d\n", pos_max(*stack_b));
	ft_calcul_lowcost(*stack_a, *stack_b);
	//ft_execute();
}
