/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:08 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/03 14:39:37 by rkerman          ###   ########.fr       */
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
	return (0);
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
		if (max_posb >= lst_lenb / 2 && i >= lst_lena / 2)
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
	}
	if (shot < p->shotcount || !p->shotcount)
	{
		p->shotcount = shot;
		p->bullet = stack_a->value;
		p->target = stack_b->value;
	}
}

/*

	La cible est un chiffre qui est plus petit que le chiffre a placer mais plus grand que tout les autres qui son plus petit que la cible
	En gros c est le plus grand des plus petit de la cible

*/


int	count_low(int value, t_stack *stack_b)
{
	int	count;

	count = 0;
	while (stack_b)
	{
		if (value > stack_b->value)
			count++;
		stack_b = stack_b->next;
	}
	return (count);
}

int	target_finder(t_stack *stack_a, t_stack *stack_b)
{
	const t_stack	*save;
	int	*tabint;
	int	i;
	int	target;

	tabint = malloc(count_low(stack_a->value, stack_b) * sizeof(int));
	if (!tabint)
		return (0);
	i = 0;
	save = stack_b;
	while (stack_b)
	{
		if (stack_a->value > stack_b->value)
		{
			tabint[i] = stack_b->value;
			i++;
		}
		stack_b = stack_b->next;
	}
	tabint[i] = 0;
	i = 0;
	target = tabint[i];
	while (i < count_low(stack_a->value, stack_b))
	{
		i++;
		if (target < tabint[i])
			target = tabint[i];
	}
	free(tabint);
	return (target);
}

void	is_random_num_calcul(t_stack *stack_a, t_stack *stack_b/*, t_stat *p, int i*/)
{
	target_finder(stack_a, stack_b);	
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
		else
			is_random_num_calcul(stack_a, stack_b/*, panel, ia*/);
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
