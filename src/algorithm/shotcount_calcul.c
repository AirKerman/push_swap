/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shotcount_calcul.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:44:39 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/16 23:41:27 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bellow_med(int len_a, int len_b, int pos_target, int pos_bullet)
{
	if ((pos_bullet <= len_a / 2 && pos_target <= len_b / 2)
		|| (pos_bullet <= len_a / 2 && pos_target > len_b / 2
			&& cmp_shot(pos_bullet, pos_target)
			<= cmp_shot(len_a - pos_bullet, len_b - pos_target)
			&& cmp_shot(pos_bullet, pos_target)
			<= pos_bullet + (len_b - pos_target))
		|| (pos_target <= len_b / 2 && pos_bullet > len_a / 2
			&& cmp_shot(pos_bullet, pos_target)
			<= cmp_shot(len_a - pos_bullet, len_b - pos_target)
			&& cmp_shot(pos_bullet, pos_target)
			<= pos_target + (len_a - pos_bullet)))
		return (cmp_shot(pos_bullet, pos_target) + 1);
	return (0);
}

static int	top_med(int len_a, int len_b, int pos_target, int pos_bullet)
{
	if ((pos_bullet > len_a / 2 && pos_target > len_b / 2)
		|| (pos_bullet > len_a / 2 && pos_target <= len_b / 2
			&& cmp_shot(pos_bullet, pos_target)
			> cmp_shot(len_a - pos_bullet, len_b - pos_target)
			&& cmp_shot(len_a - pos_bullet, len_b - pos_target)
			< pos_target + (len_a - pos_bullet))
		|| (pos_target > len_b / 2 && pos_bullet <= len_a / 2
			&& cmp_shot(pos_bullet, pos_target)
			> cmp_shot(len_a - pos_bullet, len_b - pos_target)
			&& cmp_shot(len_a - pos_bullet, len_b - pos_target)
			< pos_bullet + (len_b - pos_target)))
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

static void	ft_double_rotate(t_stack **sa, t_stack **sb, t_stat *panel)
{
	if (bellow_med(ft_lstlen(*sa), ft_lstlen(*sb),
			get_pos(*sb, panel->target),
			get_pos(*sa, panel->bullet)))
	{
		while (get_pos(*sb, panel->target)
			&& get_pos(*sa, panel->bullet))
			rr(sa, sb, 1);
	}
	else if (top_med(ft_lstlen(*sa), ft_lstlen(*sb),
			get_pos(*sb, panel->target),
			get_pos(*sa, panel->bullet)))
	{
		while (get_pos(*sb, panel->target)
			&& get_pos(*sa, panel->bullet))
			rrr(sa, sb, 1);
	}
}

void	ft_execute(t_stack **stack_a, t_stack **stack_b, t_stat *panel)
{
	ft_double_rotate(stack_a, stack_b, panel);
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
