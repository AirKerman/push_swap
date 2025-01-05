/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:29:33 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/05 18:03:15 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **chainza)
{
	t_stack *tmp;
	t_stack *head;

	if (*chainza && (*chainza)->next)
	{
		while (*chainza && (*chainza)->next && (*chainza)->next->next)
			*chainza = (*chainza)->next;
		head = (*chainza)->next;
		(*chainza)->next = NULL;
		
	}
}
