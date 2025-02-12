/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:57:57 by rkerman           #+#    #+#             */
/*   Updated: 2025/02/12 12:44:22 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (stack_a && *stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, int trigger)
{
	push(stack_b, stack_a);
	if (trigger)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int trigger)
{
	push(stack_a, stack_b);
	if (trigger)
		write(1, "pb\n", 3);
}

/*
t_stack *ft_lstcreate(int data)
{
	t_stack	*newlst;
	
	newlst = malloc(1 * sizeof(t_stack));
	if (!newlst)
		return (NULL);
	newlst->value = data;
	newlst->next = NULL;
	return (newlst);
}

void	ft_lstadd_back(t_stack **chainz, t_stack *newnode)
{
	t_stack	*head;

	if (!*chainz)
	{
		*chainz = newnode;
		return ;
	}
	head = *chainz;
	while (*chainz && (*chainz)->next)
		*chainz = (*chainz)->next;
	(*chainz)->next = newnode;
	*chainz = head;
}

int	main(void)
{
	t_stack *ppa;
	t_stack *pa1;
	t_stack *pa2;
	t_stack *pa3;
	t_stack	*ppb;
	t_stack	*pb1;
	t_stack	*pb2;
	t_stack	*pb3;
	

	ppa = ft_lstcreate(1);
	pa1 = ft_lstcreate(2);
	pa2 = ft_lstcreate(3);
	pa3 = ft_lstcreate(4);

	ft_lstadd_back(&ppa, pa1);
	ft_lstadd_back(&ppa, pa2);
	ft_lstadd_back(&ppa, pa3);
	pb(&ppa, &ppb);
}*/
