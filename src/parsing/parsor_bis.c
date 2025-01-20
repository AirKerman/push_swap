/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:52:36 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/20 10:08:07 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_formatint(char *s, int *i)
{
	if (v[*i] && v[*i] >= '0' && v[*i] <= '9')
	{
		while (v[*i] && v[*i] >= '0' && v[i] <= '9')
		{
			if ((sum == 214748364 && v[*i] > '7' && neg == 1)
				|| (sum == 214748364 && v[*i] > '8' && neg == -1)
				|| sum > 214748364)
				return (0);
			sum = (sum * 10) + (v[i] - 48);
			(*i)++;
		}
		if (!v[*i])
			return (1);
	}
	return (0);
}

int	format_v(char *v)
{
	int	neg;
	int	sum;
	int	i;

	i = 0;
	sum = 0;
	neg = 1;
	if (!v || !v[i])
		return (0);
	while (v[i] == ' ' || (v[i] >= '\t' && v[i] <= '\r'))
		i++;
	if (v[i] == '-' || v[i] == '+')
	{
		if (v[i] == '-')
			neg = -1;
		i++;
	}
	return (is_formatint(v, &i));
}
