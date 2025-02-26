/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:08 by rkerman           #+#    #+#             */
/*   Updated: 2025/02/26 15:05:25 by rkerman          ###   ########.fr       */
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

void	is_min_calcul(t_stack *stack_a, t_data *p, int i)
{
	if (i == 1)
		p->target = stack_a->value;
	else if (!p->shotcount)
	{
		p->shotcount = i;
		p->target = stack_a->value;
	}
	else if (i < p->shotcount)
	{
		p->shotcount = i;
		p->target = stack_a->value;
	}
}

void	panel_init(t_data *panel)
{
	panel->shotcount = 0;
	panel->target = 0;
	panel->bullet = 0;
}

void	ft_calcul_lowcost(t_stack *stack_a, t_stack *stack_b, t_data *panel)
{
	int		ia;

	ia = 0;
	while (stack_a)
	{
		ia++;
		if (is_min(stack_a, stack_b))
		{
			is_min_calcul(stack_a, panel, ia);
			if (ia == 1)
				break ;
		}
		stack_a = stack_a->next;
	}
}

void	ft_calcul_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	t_data panel;

	panel_init(&panel);
	ft_calcul_lowcost(*stack_a, *stack_b, &panel);
	//ft_execute();
}
