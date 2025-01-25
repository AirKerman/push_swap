/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:20:16 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/25 16:03:40 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_lstlen(*stack_a);
	if (!ft_lstissort(*stack_a))
	{
		write(1, "ko", 2);
	}
}

