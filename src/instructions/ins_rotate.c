/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:11:39 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/05 23:08:26 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **chainz, int trigger)
{	
	t_stack *tmp;
	t_stack	*head;

	if (*chainz && (*chainz)->next)
	{
		tmp = *chainz;
		head = (*chainz)->next;
		while (*chainz && (*chainz)->next)
			*chainz = (*chainz)->next;
		tmp->next = NULL;
		(*chainz)->next = tmp;
		*chainz = head;
		if (trigger)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack **chainz, int trigger)
{
	t_stack *tmp;
	t_stack	*head;

	if (*chainz && (*chainz)->next)
	{
		tmp = *chainz;
		head = (*chainz)->next;
		while (*chainz && (*chainz)->next)
			*chainz = (*chainz)->next;
		tmp->next = NULL;
		(*chainz)->next = tmp;
		*chainz = head;
		if (trigger)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack **chainza, t_stack **chainzb)
{
	ra(chainza, 0);
	rb(chainzb, 0);
	write(1, "rr\n", 3);
}

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
   	rr(&ppa, &ppa);
	while (ppa)
	{
		printf("%d", ppa->value);
		ppa = ppa->next;
	}
}

