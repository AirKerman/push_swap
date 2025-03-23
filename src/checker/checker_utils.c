/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:20:44 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/23 13:44:55 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s, char *d)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] == d[i])
		i++;
	return (s[i] - d[i]);
}

int	ft_isins(char *ins)
{
	if (!ft_strcmp(ins, "sa\n") ||!ft_strcmp(ins, "sb\n")
		|| !ft_strcmp(ins, "ss\n") || !ft_strcmp(ins, "pa\n")
		|| !ft_strcmp(ins, "pb\n") || !ft_strcmp(ins, "ra\n")
		|| !ft_strcmp(ins, "rb\n") || !ft_strcmp(ins, "rr\n")
		|| !ft_strcmp(ins, "rra\n") || !ft_strcmp(ins, "rrb\n")
		|| !ft_strcmp(ins, "rrr\n"))
		return (1);
	return (0);
}

char	*ft_extract_ins(char *start, char *end)
{
	int		len;
	char	*ins;
	int		i;

	i = 0;
	len = end - start;
	ins = ft_calloc(len + 1, sizeof(char));
	if (!ins)
		return (NULL);
	while (i < len)
	{
		ins[i] = start[i];
		i++;
	}
	return (ins);
}

void	ft_exec_ins(char *ins, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(ins, "sa\n") || !ft_strcmp(ins, "sa"))
		sa(stack_a, 0);
	else if (!ft_strcmp(ins, "sb\n") || !ft_strcmp(ins, "sb"))
		sb(stack_b, 0);
	else if (!ft_strcmp(ins, "ss\n") || !ft_strcmp(ins, "ss"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(ins, "pa\n") || !ft_strcmp(ins, "pa"))
		pa(stack_b, stack_a, 0);
	else if (!ft_strcmp(ins, "pb\n") || !ft_strcmp(ins, "pb"))
		pb(stack_a, stack_b, 0);
	else if (!ft_strcmp(ins, "ra\n") || !ft_strcmp(ins, "ra"))
		ra(stack_a, 0);
	else if (!ft_strcmp(ins, "rb\n") || !ft_strcmp(ins, "rb"))
		rb(stack_b, 0);
	else if (!ft_strcmp(ins, "rr\n") || !ft_strcmp(ins, "rr"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(ins, "rra\n") || !ft_strcmp(ins, "rra"))
		rra(stack_a, 0);
	else if (!ft_strcmp(ins, "rrb\n") || !ft_strcmp(ins, "rrb"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(ins, "rrr\n") || !ft_strcmp(ins, "rrr"))
		rrr(stack_a, stack_b, 0);
}
