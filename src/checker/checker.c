/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:55:26 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/23 13:36:34 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_format_ins(char *ins)
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

static void	ft_parse_ins(char *ins, t_stack **stack_a, t_stack **stack_b)
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

static void	ft_conclusion_check(t_stack **s_a, t_stack **s_b, int e, char *i)
{
	if (e)
		write(2, "Error\n", 6);
	else if (ft_lstissort(*s_a) && !*s_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (s_b)
		ft_freelst(s_b);
	if (i)
		free(i);
	ft_freelst(s_a);
}

static void	checking(t_stack **stack_a, t_stack **stack_b)
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
	ft_conclusion_check(stack_a, stack_b, error, instruction);
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
