/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:08 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/25 18:40:02 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	target_finder(t_stack *stack_a, t_stack *stack_b)
{
	int	target;

	while (stack_b)
	{
		if (stack_b->value < stack_a->value)
			break ;
		stack_b = stack_b->next;
	}
	target = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value < stack_a->value && target < stack_b->value)
			target = stack_b->value;
		stack_b = stack_b->next;
	}
	return (target);
}

static void	ft_num_calcul(t_stack *sa, t_stack *sb, t_stat *p, int i)
{
	int	shot;
	int	target;
	int	min_or_max;

	min_or_max = (is_new_min(sa, sb) || is_new_max(sa, sb));
	if (min_or_max)
		target = who_is_max(sb);
	else
		target = target_finder(sa, sb);
	if (!i && !get_pos(sb, target) && (!p->shotcount || p->shotcount > 1))
		shot = 1;
	else
		shot = shot_calcul(ft_lstlen(sa) + i,
				ft_lstlen(sb), get_pos(sb, target), i);
	if (shot < p->shotcount || !p->shotcount)
	{
		p->shotcount = shot;
		p->bullet = sa->value;
		p->target = target;
	}
}

static void	ft_calcul_lowcost(t_stack *stack_a, t_stack *stack_b, t_stat *panel)
{
	int		i;

	i = 0;
	while (stack_a)
	{
		ft_num_calcul(stack_a, stack_b, panel, i);
		i++;
		stack_a = stack_a->next;
	}
}

void	ft_calcul_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	t_stat	panel;

	panel_init(&panel);
	ft_calcul_lowcost(*stack_a, *stack_b, &panel);
	ft_execute(stack_a, stack_b, &panel);
}
