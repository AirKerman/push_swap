/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:02:35 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/04 18:27:44 by rkerman          ###   ########.fr       */
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

void	sa(t_stack **stack, int trigger);
void	sb(t_stack **stack, int trigger);
void	ss(t_stack **stacka, t_stack **stackb);


#endif

