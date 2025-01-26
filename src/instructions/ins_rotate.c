/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:11:39 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/26 14:39:47 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		head = (*stack)->next;
		while (*stack && (*stack)->next)
			*stack = (*stack)->next;
		tmp->next = NULL;
		(*stack)->next = tmp;
		*stack = head;
	}
}

void	ra(t_stack **stack, int trigger)
{
	rotate(stack);
	if (trigger)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack, int trigger)
{
	rotate(stack);
	if (trigger)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int trigger)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (trigger)
		write(1, "rr\n", 3);
}
/*
t_stack *ft_lstcreate(int data)
{
    t_stack *newlst;

    newlst = malloc(1 * sizeof(t_stack));
    if (!newlst)
        return (NULL);
    newlst->value = data;
    newlst->next = NULL;
    return (newlst);
}

void    ft_lstadd_back(t_stack **chainz, t_stack *newnode)
{
    t_stack *head;

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

#include <stdio.h>

int main(void)
{
    t_stack *ppa;
    t_stack *pa1;
    t_stack *pa2;
    t_stack *pa3;
    t_stack *ppb;
    t_stack *pb1;
    t_stack *pb2;
    t_stack *pb3;


    ppa = ft_lstcreate(1);
    pa1 = ft_lstcreate(2);
    pa2 = ft_lstcreate(3);
    pa3 = ft_lstcreate(4);

    ft_lstadd_back(&ppa, pa1);
    ft_lstadd_back(&ppa, pa2);
    ft_lstadd_back(&ppa, pa3);
   	rr(&ppa, &ppa, 1);
	while (ppa)
	{
		printf("%d", ppa->value);
		ppa = ppa->next;
	}
}*/
