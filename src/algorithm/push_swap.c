/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:20:16 by rkerman           #+#    #+#             */
/*   Updated: 2025/02/12 12:27:53 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_lstlen(*stack_a);
	if (len > 1 && !ft_lstissort(*stack_a))
	{
		if (len < 4)
			ft_sortmin(stack_a, len);
		else
			ft_sorter(stack_a, stack_b);
	}
}
