/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:29:33 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/05 23:12:50 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **chainza, int trigger)
{
	t_stack *tmp;
	t_stack *head;

	if (*chainza && (*chainza)->next)
	{
		tmp = *chainza;
		while (*chainza && (*chainza)->next && (*chainza)->next->next)
			*chainza = (*chainza)->next;
		head = (*chainza)->next;
		head->next = tmp;
		(*chainza)->next = NULL;
		*chainza = head;
		if (trigger)
			write(1, "rra\n", 4);
	}
}

void    rrb(t_stack **chainzb, int trigger)
{
    t_stack *tmp;
    t_stack *head;

    if (*chainzb && (*chainzb)->next)
    {
        tmp = *chainzb;
        while (*chainzb && (*chainzb)->next && (*chainzb)->next->next)
            *chainzb = (*chainzb)->next;
        head = (*chainzb)->next;
        head->next = tmp;
        (*chainzb)->next = NULL;
        *chainzb = head;
		if (trigger)
			write(1, "rrb\n", 4);
    }
}

void	rrr(t_stack **chainza, t_stack **chainzb)
{
	rra(chainza, 0);
	rrb(chainzb, 0);
	write(1, "rrr\n", 4);
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
    rrr(&ppa, &ppa);
    while (ppa)
    {
        printf("%d", ppa->value);
        ppa = ppa->next;
    }
}

