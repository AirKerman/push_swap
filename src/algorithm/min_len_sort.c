/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_len_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:17:55 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/16 15:29:55 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	if ((*stack)->value < (*stack)->next->value
		&& (*stack)->value < (*stack)->next->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	if ((*stack)->value < (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value < (*stack)->next->next->value)
		sa(stack, 1);
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value)
		ra(stack, 1);
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
	{
		ra(stack, 1);
		sa(stack, 1);
	}
}

void	ft_sortmin(t_stack **stack, int len)
{
	if (len == 2 && (*stack)->value > (*stack)->next->value)
		ra(stack, 1);
	if (len == 3)
		ft_sort_three(stack);
}
