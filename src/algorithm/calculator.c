/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:08 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/02 21:58:26 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_new_min(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_a->value > stack_b->value)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int	is_new_max(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_a->value < stack_b->value)
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
	max_pos = i;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (max_pos);
}

int	who_is_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_pos(t_stack *stack, int data)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == data)
			return (i);
		stack = stack->next;
		i++;
	}
}

void	is_min_or_max_calcul(t_stack *stack_a, t_stack *stack_b, t_stat *p, int i)
{
	int	max_posb;
	int	lst_lenb;
	int	lst_lena;
	int	shot;

	if (!i && !pos_max(stack_b) && (!p->shotcount || p->shotcount > 1))
		shot = 1;
	else
	{
		lst_lena = ft_lstlen(stack_a) + i;
		max_posb = pos_max(stack_b);
		lst_lenb = ft_lstlen(stack_b);
		if (max_posb > lst_lenb / 2 && i > lst_lena / 2)
		{
			if ((lst_lena - i) > (lst_lenb - max_posb))
				shot = lst_lena - i + 1;
			else
				shot = lst_lenb - max_posb + 1;
		}
		else if (max_posb < lst_lenb / 2 && i < lst_lena / 2)
		{
			if (i > max_posb)
				shot = i + 1;
			else
				shot = max_posb + 1;
		}
		else if (max_posb < lst_lenb / 2 && i >= lst_lena / 2)
			shot = max_posb + (lst_lena - i) + 1;
		else
			shot = i + (lst_lenb - max_posb) + 1;
		if (shot < p->shotcount || !p->shotcount)
		{
			p->shotcount = shot;
			p->bullet = stack_a->value;
			p->target = stack_b->value;
		}
	}
}

void	panel_init(t_stat *panel)
{
	panel->shotcount = 0;
	panel->target = 0;
	panel->bullet = 0;
}

void	ft_calcul_lowcost(t_stack *stack_a, t_stack *stack_b, t_stat *panel)
{
	int		ia;
	
	ia = 0;
	while (stack_a)
	{
		if (is_new_min(stack_a, stack_b) || is_new_max(stack_a, stack_b))
			is_min_or_max_calcul(stack_a, stack_b, panel, ia);
		ia++;
		stack_a = stack_a->next;
	}
}

void	ft_calcul_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	t_stat panel;

	panel_init(&panel);
	ft_calcul_lowcost(*stack_a, *stack_b, &panel);
	//ft_execute();
}
