/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:08 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/14 13:13:24 by rkerman          ###   ########.fr       */
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

int	cmp_shot(int shot_a, int shot_b)
{
	if (shot_b > shot_a)
		return (shot_b);
	else
		return (shot_a);
}

int	bellow_med(int len_a, int len_b, int pos_target, int pos_bullet)
{
	if ((pos_bullet <= len_a / 2 && pos_target <= len_b / 2)
		|| (pos_bullet <= len_a / 2 && pos_target > len_b / 2
		&& cmp_shot(pos_bullet, pos_target) <= cmp_shot(len_a - pos_bullet, len_b - pos_target)
		&& cmp_shot(pos_bullet, pos_target) <= pos_bullet + (len_b - pos_target))
		|| (pos_target <= len_b / 2 && pos_bullet > len_a / 2
		&& cmp_shot(pos_bullet, pos_target) <= cmp_shot(len_a - pos_bullet, len_b - pos_target)
		&& cmp_shot(pos_bullet, pos_target) <= pos_target + (len_a - pos_bullet))		
		)
		return (cmp_shot(pos_bullet, pos_target) + 1);
	return (0);
}

int	top_med(int len_a, int len_b, int pos_target, int pos_bullet)
{
	if ((pos_bullet > len_a / 2 && pos_target > len_b / 2)
		|| (pos_bullet > len_a / 2 && pos_target <= len_b / 2 
		&& cmp_shot(pos_bullet, pos_target) > cmp_shot(len_a - pos_bullet, len_b - pos_target)
		&& cmp_shot(len_a - pos_bullet, len_b - pos_target) < pos_target + (len_a - pos_bullet))
		|| (pos_target > len_b / 2 && pos_bullet <= len_a / 2 
		&& cmp_shot(pos_bullet, pos_target) > cmp_shot(len_a - pos_bullet, len_b - pos_target)
		&& cmp_shot(len_a - pos_bullet, len_b - pos_target) < pos_bullet + (len_b - pos_target))
		)
		return (cmp_shot(len_a - pos_bullet, len_b - pos_target) + 1);
	return (0);
}

int	shot_calcul(int len_a, int len_b, int pos_target, int i)
{
	int	shot;

	shot = bellow_med(len_a, len_b, pos_target, i);
	if (!shot)
	{
		shot = top_med(len_a, len_b, pos_target, i);
		if (!shot && pos_target <= len_b / 2)
			shot = pos_target + (len_a - i) + 1;
		else if (!shot)
			shot = i + (len_b - pos_target) + 1;
	}
	return (shot);
}

void	is_min_or_max_calcul(t_stack *stack_a, t_stack *stack_b, t_stat *p, int i)
{
	int	shot;

	if (!i && !pos_max(stack_b) && (!p->shotcount || p->shotcount > 1))
		shot = 1;
	else
		shot = shot_calcul(ft_lstlen(stack_a) + i, ft_lstlen(stack_b), pos_max(stack_b), i);
	if (shot < p->shotcount || !p->shotcount)
	{
		p->shotcount = shot;
		p->bullet = stack_a->value;
		p->target = who_is_max(stack_b);
	}
}

int	target_finder(t_stack *stack_a, t_stack *stack_b)
{
	int	target;

	while (stack_b)
	{
		if (stack_b->value < stack_a->value)
			break;
		stack_b = stack_b->next;
	}
	target = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value < stack_a->value && target < stack_b->value )
			target = stack_b->value;
		stack_b = stack_b->next;
	}
	return (target);
}

void	is_random_num_calcul(t_stack *stack_a, t_stack *stack_b, t_stat *p, int i)
{
	int	shot;

	shot = shot_calcul(ft_lstlen(stack_a) + i, ft_lstlen(stack_b), get_pos(stack_b, target_finder(stack_a, stack_b)), i);
	if (shot < p->shotcount || !p->shotcount)
	{
		p->shotcount = shot;
		p->bullet = stack_a->value;
		p->target = target_finder(stack_a, stack_b);
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
		else
			is_random_num_calcul(stack_a, stack_b, panel, ia);
		ia++;
		stack_a = stack_a->next;
	}
}

//3 1 5 4 5435 654 7654

void	ft_execute(t_stack **stack_a, t_stack **stack_b, t_stat *panel)
{
	if (bellow_med(ft_lstlen(*stack_a), ft_lstlen(*stack_b), get_pos(*stack_b, panel->target), get_pos(*stack_a, panel->bullet)))
	{
		while (get_pos(*stack_b, panel->target) && get_pos(*stack_a, panel->bullet))
			rr(stack_a, stack_b, 1);
	}
	else if (top_med(ft_lstlen(*stack_a), ft_lstlen(*stack_b), get_pos(*stack_b, panel->target), get_pos(*stack_a, panel->bullet)))
	{
		while (get_pos(*stack_b, panel->target) && get_pos(*stack_a, panel->bullet))
			rrr(stack_a, stack_b, 1);
	}
	while (get_pos(*stack_a, panel->bullet))
	{
		if (get_pos(*stack_a, panel->bullet) <= ft_lstlen(*stack_a) / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
	while (get_pos(*stack_b, panel->target))
	{
		if (get_pos(*stack_b, panel->target) <= ft_lstlen(*stack_b) / 2)
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
	}
	pb(stack_a, stack_b, 1);
}

void	ft_calcul_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	t_stat panel;

	panel_init(&panel);
	ft_calcul_lowcost(*stack_a, *stack_b, &panel);
	ft_execute(stack_a, stack_b, &panel);
}
