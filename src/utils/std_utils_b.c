/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_utils_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:42:18 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/17 00:17:46 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp_shot(int shot_a, int shot_b)
{
	if (shot_b > shot_a)
		return (shot_b);
	else
		return (shot_a);
}

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

void	panel_init(t_stat *panel)
{
	panel->shotcount = 0;
	panel->target = 0;
	panel->bullet = 0;
}
