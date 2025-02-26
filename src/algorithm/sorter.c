/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:36:44 by rkerman           #+#    #+#             */
/*   Updated: 2025/02/18 20:34:06 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	print_list(t_stack )

void	ft_sorter(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	while (ft_lstlen(*stack_a) > 3)
		ft_calcul_and_execute(stack_a, stack_b);
	ft_sortmin(stack_a, ft_lstlen(*stack_a));
}

