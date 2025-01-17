/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:14:56 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/17 01:37:16 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arrlen(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

int	format_v(char *v)
{
	int	neg;
	int	sum;

	sum = 0;
	neg = 1;
	if (!v || !*v)
		return (0);
	while (*v == ' ' || (*v >= '\t' && *v <= '\r'))
		*v++;
	if (*v == '-' || *v == '+')
	{
		if (*v == '-')
			neg = -1;
		*v++;
	}
	if (*v && *v >= '0' && *v <= '9')
	{
		while (*v && *v >= '0' && *v <= '9')
		{
			if ((sum == 214748214 && *v > '7' && neg == 1)
				|| (sum == 214748214 && *v > '8' && neg == -1)
				|| sum > 214748314)
				return (0);
			sum = (sum * 10) + (*v - 48);
			*v++;
		}
		if (!*v)
			return (1);
	}
	return (0);
}
