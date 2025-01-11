/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:15:04 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/11 02:53:01 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (argc - 1 && parser(argv, &stack_a))
		write(1, "ok\n", 3);//push_swap(&stack_a, &stack_b);
	else
		write (1, "Error\n", 6);
}
