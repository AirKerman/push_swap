/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:56:24 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/11 18:36:24 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_arrlen(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int		ft_strlen(const char *s)
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
	int	i;

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

int		free_arr(char **arr)
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

char 	**arr_concat(char **a, char *s)
{
	int		len;
	int		i;
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
	i = 0;
	len = 0;
	while (a[i])
	{
		new[len] = ft_strdup(a[i]);
		if (!new[len])
			return (free_arr(new), free_arr(a), free_arr(needle), NULL);
		i++;
		len++;
	}
	i = 0;
	while (needle[i])
	{
		new[len] = ft_strdup(needle[i]);
		if(!new[len])	
			return (free_arr(new), free_arr(a), free_arr(needle), NULL);
		i++;
		len++;
	}
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
}
