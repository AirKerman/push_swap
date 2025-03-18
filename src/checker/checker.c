/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:55:26 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/18 23:58:39 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

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

void	ft_exec_ins(char *ins, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(ins, "sa\n"))
		sa(stack_a, 1);
	else if (!ft_strcmp(ins, "sb\n"))
                sb(stack_b, 1);
	else if (!ft_strcmp(ins, "ss\n"))
                ss(stack_a, stack_b, 1);
	else if (!ft_strcmp(ins, "pa\n"))
                pa(stack_b, stack_a, 1);
	else if (!ft_strcmp(ins, "pb\n"))
                pb(stack_a, stack_b, 1);
	else if (!ft_strcmp(ins, "ra\n"))
                ra(stack_a, 1);
	else if (!ft_strcmp(ins, "rb\n"))
                rb(stack_b, 1);
	else if (!ft_strcmp(ins, "rr\n"))
                rr(stack_a, stack_b, 1);
	else if (!ft_strcmp(ins, "rra\n"))
                rra(stack_a, 1);
	else if (!ft_strcmp(ins, "rrb\n"))
                rrb(stack_b, 1);
	else if (!ft_strcmp(ins, "rrr\n"))
                rrr(stack_a, stack_b, 1);
}

void    checking(t_stack **stack_a, t_stack **stack_b)
{
	char instruction[100000];
	int	error;

	error = 0;
	while (read(1, instruction, 100000))
	{
		if (ft_isins(instruction))
			ft_exec_ins(instruction, stack_a, stack_b);
		else if (!ft_strcmp(instruction, "stop\n"))
			exit(1);
		else
		{
			error = 1;
			exit(1);
		}
		ft_bzero(instruction, 5);
	}
	if (error)
		write(2, "Error\n", 6);
	else if (ft_lstissort(*stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stack_b)
		ft_freelst(stack_b);
	ft_freelst(stack_a);
}


int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
	if (argc - 1)
	{
		if (parser(&argv[1], &stack_a))
			checking(&stack_a, &stack_b);
		else
			write(2, "Error\n", 6);
	}
}
