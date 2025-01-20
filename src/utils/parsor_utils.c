/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:14:56 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/20 10:01:21 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freelst(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	ft_lstchr(t_stack *lst, int data)
{
	while (lst)
	{
		if (lst->value == data)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_stack	*create_element(int data)
{
	t_stack	*elm;

	elm = malloc(1 * sizeof(t_stack));
	if (!elm)
		return (NULL);
	elm->value = data;
	elm->next = NULL;
	return (elm);
}

void	ft_lstadd_back(t_stack **lst, t_stack *node)
{
	t_stack	*head;

	if (!*lst)
	{
		*lst = node;
		return ;
	}
	head = *lst;
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = node;
	*lst = head;
}
