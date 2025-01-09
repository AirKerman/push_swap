/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:56:24 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/09 22:33:00 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **arr_concat(char **a, char **n)
{
	
	if (!a && n)
		return (n);
	if (!n)
	{
		
	}
		

	
}

int	parser(char	**v, t_stack **a, t_stack **b)
{
	int		i;
	char	**arr;


	i = 0;
	while (*v)
	{
		arr = arr_concat(arr, ft_split(*v, ' '));
		if (!arr)
			return (0);
		v++;
	}
	return (1);
}
