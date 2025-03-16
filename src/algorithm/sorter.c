/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:36:44 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/17 00:48:21 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	target_finder_reverse(t_stack *stack_a, t_stack *stack_b)
{
	int	target;

	while (stack_b)
	{
		if (stack_b->value > stack_a->value)
			break ;
		stack_b = stack_b->next;
	}
	target = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value > stack_a->value && target > stack_b->value)
			target = stack_b->value;
		stack_b = stack_b->next;
	}
	return (target);
}

static void	ft_final_placement(t_stack **stack_b, t_stack **stack_a)
{
	int	target;

	if (is_new_max(*stack_b, *stack_a) || is_new_min(*stack_b, *stack_a))
		target = who_is_min(*stack_a);
	else
		target = target_finder_reverse(*stack_b, *stack_a);
	while (get_pos(*stack_a, target))
	{
		if (get_pos(*stack_a, target) > ft_lstlen(*stack_a) / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	pa(stack_b, stack_a, 1);
}

void	ft_sorter(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	while (ft_lstlen(*stack_a) > 3)
		ft_calcul_and_execute(stack_a, stack_b);
	ft_sortmin(stack_a, ft_lstlen(*stack_a));
	while (get_pos(*stack_b, who_is_max(*stack_b)))
	{
		if (get_pos(*stack_b, who_is_max(*stack_b)) > ft_lstlen(*stack_b) / 2)
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
	while (*stack_b)
		ft_final_placement(stack_b, stack_a);
	while (get_pos(*stack_a, who_is_min(*stack_a)))
	{
		if (get_pos(*stack_a, who_is_min(*stack_a)) > ft_lstlen(*stack_a) / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	ft_freelst(stack_a);
}
