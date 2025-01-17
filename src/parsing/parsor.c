/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:56:24 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/17 01:38:53 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	arr_cat(char ***arr, char **cpy, void (*del)(char **array), int	*len)
{
	int	i;

	i = 0;
	while (*arr && cpy[i])
	{
		(*arr)[*len] = ft_strdup(cpy[i]);
		if (!(*arr)[*len])
		{
			if (*arr)
				del(*arr);
			*arr = NULL;
			del(cpy);
			return (0);
		}
		(*len)++;
		i++;
	}
	if (cpy)
		del(cpy);
	return (1);
}

char	**array_concatenator(char **a, char **n, int len)
{
	int		i;
	char	**new;

	i = 0;
	new = ft_calloc(len + 1, sizeof(char *));
	if (!new || !arr_cat(&new, a, free_arr, &i) || !arr_cat(&new, n, free_arr, &i))
	{
		if (n)
			free_arr(n);
		if (a)
			free(a);
		return (NULL);
	}
	new[i] = NULL;
	return (new);	
}

char	**arr_fusion(char **a, char *s)
{
	int		len;
	char	**needle;

	if (!a)
		return (ft_split(s, ' '));
	needle = ft_split(s, ' ');
	if (!needle)
		return (free_arr(a), NULL);
	len = ft_arrlen(needle) + ft_arrlen(a);
	return (array_concatenator(a, needle, len));
}

int	stack_maker(char **v, t_stack **s)
{
	if (!v || !*v)
		return (0);
	while (format_v(*v))
		return (1);
	return (0);	
}

int	parser(char **value, t_stack **stack)
{
	int		i;
	char	**arr;

	arr = NULL;
	i = 0;
	while (*value)
	{
		arr = arr_fusion(arr, *value);
		if (!arr)
			return (0);
		value++;
	}
	if(!stack_maker(arr, stack))
		return (0);
	return (1);
}

#include "stdio.h"

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	int		i;
	//char	**turing1;	
	
	argc = 0;
	i = 0;
	argv++;
	printf("%d", parser(argv, &stacka));
	/*turing1 = parser(argv);
	while (turing1[i])
	{
		printf("%s\n", turing1[i]);
		i++;
	}*/
	//free_arr(turing1);
}
