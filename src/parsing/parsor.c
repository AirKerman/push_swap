/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:56:24 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/18 17:29:20 by rkerman          ###   ########.fr       */
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
	if (!new || !arr_cat(&new, a, free_arr, &i)
		|| !arr_cat(&new, n, free_arr, &i))
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
	int		i;
	int		data;
	t_stack	*elem;

	i = 0;
	if (!v || !v[i])
		return (0);
	while (v[i] && format_v(v[i]))
	{
		data = ft_atoi(v[i]);
		if (ft_lstchr(*s, data))
			break ;
		elem = create_element(data);
		if (!elem)
			break ;
		ft_lstadd_back(s, elem);
		i++;
	}
	if (v[i])
		return (ft_freelst(s), free_arr(v), 0);
	return (free_arr(v), 1);
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
	if (!stack_maker(arr, stack))
		return (0);
	return (1);
}
/*
int	main(int argc, char **argv)
{
	t_stack	*stacka;
	int		i;
	//char	**turing1;	
	
	argc = 0;
	i = 0;
	argv++;
	stacka = NULL;
	printf("%d", parser(argv, &stacka));
	
	while (stacka)
	{
		printf("%d\n", stacka->value);
		stacka = stacka->next;
	}
	//free_arr(turing1);
}
*/
