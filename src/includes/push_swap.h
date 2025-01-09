/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:02:35 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/09 17:37:15 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_list 
{
	int	value;
	struct t_list	*next;

}	t_stack;

#include <unistd.h>
#include <stdlib.h>

/*

	Instructions

*/

void	sa(t_stack **stack, int trigger);
void	sb(t_stack **stack, int trigger);
void	ss(t_stack **stack_a, t_stack **stack_b, int trigger);
void	pa(t_stack **stack_b, t_stack **stack_a, int trigger);
void	pb(t_stack **stack_a, t_stack **stack_b, int trigger);
void	ra(t_stack **stack, int trigger);
void	rb(t_stack **stack, int trigger);
void	rr(t_stack **stack_a, t_stack **stack_b, int trigger);
void	rra(t_stack **stack, int trigger);
void	rrb(t_stack **stack, int trigger);
void	rrr(t_stack **stack_a, t_stack **stack_b, int trigger);

#endif

