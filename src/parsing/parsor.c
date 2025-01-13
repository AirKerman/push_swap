/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:56:24 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/13 20:21:19 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

void	arr_cat(char ***arr, char **cpy, int (*del)(char **array), int	*len)
{
	int	i;

	i = 0;
	while (cpy[i])
	{
		(*arr)[*len] = ft_strdup(cpy[i]);
		(*len)++;
		i++;
	}
	if (cpy)
		del(cpy);
}

char	**arr_concat(char **a, char *s)
{
	int		len;
	char	**needle;
	char	**new;

	if (!a)
		return (ft_split(s, ' '));
	needle = ft_split(s, ' ');
	if (!needle)
		return (free_arr(a), NULL);
	len = ft_arrlen(needle) + ft_arrlen(a);
	new = ft_calloc(len + 1, sizeof(char *));
	if (!new)
		return (free_arr(a), free_arr(needle), NULL);
	len = 0;
	arr_cat(&new, a, free_arr, &len);
	arr_cat(&new, needle, free_arr, &len);
	new[len] = NULL;
	return (new);
}

char	**parser(char **v)
{
	int		i;
	char	**arr;

	arr = NULL;
	i = 0;
	while (*v)
	{
		arr = arr_concat(arr, *v);
		if (!arr)
			return (arr);
		v++;
	}
	return (arr);
}
/*
#include "stdio.h"

int	main(int argc, char **argv)
{
	char	**turing1;
	int		i;
	
	argc = 0;
	i = 0;
	argv++;
	turing1 = parser(argv);
	while (turing1[i])
	{
		printf("%s\n", turing1[i]);
		i++;
	}
	free_arr(turing1);
}*/
