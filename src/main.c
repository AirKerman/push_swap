/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:15:04 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/20 17:27:21 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;	
	if (argc - 1 && parser(&argv[1], &stack_a))
		write(1, "ok\n", 3);//push_swap(&stack_a, &stack_b);
	else
		write (2, "Error\n", 6);
}
