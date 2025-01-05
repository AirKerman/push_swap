/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:57:57 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/05 22:24:35 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **stackb, t_stack **stacka)
{
	t_stack *tmp;

	if (*stackb && stackb)
	{
		tmp = *stackb;
		*stackb = (*stackb)->next;
		tmp->next = *stacka;
		*stacka = tmp;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmp;

	if (*stacka && stackb)
	{
		tmp = *stacka;
		*stacka = (*stacka)->next;
		tmp->next = *stackb;
		*stackb = tmp;
		write(1, "pb\n", 3);
	}
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
}
