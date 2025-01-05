/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:01:24 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/05 22:36:45 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack, int trigger)
{
	t_stack *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = (*stack);
		*stack = tmp;
		if (trigger)
			write (1, "sa\n", 3);
	}
}

void	sb(t_stack **stack, int trigger)
{
	t_stack *tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
		if (trigger)
			write (1, "sb\n", 3);
	}
}


void	ss(t_stack **stacka, t_stack **stackb)
{
	sa(stacka, 0);
	sb(stackb, 0);
	write(1, "ss\n", 3);
}


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
	t_stack *pa;
	t_stack *pa1;
	t_stack *pa2;
	t_stack *pa3;
	t_stack	*pb;
	t_stack	*pb1;
	t_stack	*pb2;
	t_stack	*pb3;
	
	pb = ft_lstcreate(5);
	pb1 = ft_lstcreate(6);
	pb2 = ft_lstcreate(7);
	pb3 = ft_lstcreate(8);
	pa = ft_lstcreate(1);
	pa1 = ft_lstcreate(2);
	pa2 = ft_lstcreate(3);
	pa3 = ft_lstcreate(4);

	ft_lstadd_back(&pa, pa1);
	ft_lstadd_back(&pa, pa2);
	ft_lstadd_back(&pa, pa3);
	ft_lstadd_back(&pb, pb1);
	ft_lstadd_back(&pb, pb2);
	ft_lstadd_back(&pb, pb3);
	sa(&pa, 1);
	while (pa)
	{
		printf("%d", pa->value);
		pa = pa->next;
	}
}
