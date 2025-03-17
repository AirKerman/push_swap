/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:29:10 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/17 14:56:40 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checking()
{

}

int	main(char **argv, int argc)
{
	t_stack *stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	if (argc - 1)
	{
		if (parser(&argv[1], &stack_a))
			checking(&stack_a, &stack_b);
		else
			write(2, "Error\n", 6);
	}
}
