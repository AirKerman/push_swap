/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:41:14 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/09 12:56:07 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	compteur;
	int	neg;

	i = 0;
	compteur = 0;
	neg = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		compteur = (compteur * 10) + (nptr[i] - 48);
		i++;
	}
	return (compteur * neg);
}
/*
#include <stdio.h>

int main()
{
	printf("%d", ft_atoi("   -546"));
	printf("%d", ft_atoi("--546"));
	printf("%d", ft_atoi("+546"));
}
*/
