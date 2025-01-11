/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:56:24 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/11 03:13:11 by rkerman          ###   ########.fr       */
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

int	ft_strlen(char *s)
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
	str[i] = '\0';
	return (str);
}

char **arr_concat(char **a, char *s)
{
	int	len;
	int	i;
	char	**needle;
	char	**new;

	if (!a)
		return (ft_split(s, ' '));
	needle = ft_split(s, ' ');
	if (!needle)
		return (free_arr(a));
	len = ft_arrlen(needle) + ft_arrlen(a);
	new = ft_calloc(len + 1, sizeof(char *));
	if (!new)
		return (free_arr(a) + free_arr(needle));
	i = 0;
	len = 0;
	while (a[i])
	{
		new[len] = ft_strdup(a[i]);
		if (!new[len])
			return (free_arr(new) + free_arr(a) + free_arr(needle));
		i++;
		len++;
	}
	i = 0;
	while (needle[i])
	{
		new[len] = ft_strdup(needle[i]);
		if(!new[len])	
			return (free_arr(new) + free_arr(a) + free_arr(needle));
		i++;
		len++;
	}
	new[len] = '\0';

	return (new);
}

int	parser(char **v, t_stack **a)
{
	int		i;
	char		**arr;


	i = 0;
	while (*v)
	{
		arr = arr_concat(arr, *v);
		if (!arr)
			return (0);
		v++;
	}
	return (1);
}

#include "stdio.h"

int	main(void)
{

	\\printf();

}
