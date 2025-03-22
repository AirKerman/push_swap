/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:55:26 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/23 00:37:32 by rkerman          ###   ########.fr       */
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

int	ft_format_ins(char *ins)
{
	char	*start;
	int		i;
	char	*instruct;

	i = 0;
	while (ins[i])
	{
		start = &ins[i];
		while (ins[i] != '\n' && ins[i] != '\0')
			i++;
		if (ins[i] == '\n')
			i++;
		instruct = ft_extract_ins(start, &ins[i]);
		if (!ft_isins(instruct))
		{
			free(instruct);
			return (0);
		}
		free(instruct);
	}
	return (1);
}

void	ft_parse_ins(char *ins, t_stack **stack_a, t_stack **stack_b)
{
	char	*start;
	char	*instruct;

	while (*ins)
	{
		start = ins;
		while (*ins != '\n' && *ins != '\0')
			ins++;
		if (*ins == '\n')
			ins++;
		instruct = ft_extract_ins(start, ins);
		ft_exec_ins(instruct, stack_a, stack_b);
		free(instruct);
	}
}

void	checking(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;
	int		error;

	error = 0;
	instruction = get_next_line(0);
	while (instruction)
	{
		if (ft_isins(instruction))
			ft_exec_ins(instruction, stack_a, stack_b);
		else if (ft_format_ins(instruction))
			ft_parse_ins(instruction, stack_a, stack_b);
		else if (!ft_strcmp(instruction, "stop\n"))
			break ;
		else
		{
			error = 1;
			break ;
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	if (error)
		write(2, "Error\n", 6);
	else if (ft_lstissort(*stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stack_b)
		ft_freelst(stack_b);
	if (instruction)
		free(instruction);
	ft_freelst(stack_a);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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
