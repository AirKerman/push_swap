/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:14:56 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/18 19:16:51 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

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

int	ft_atoi(char *s)
{
	int	i;
	int	neg;
	int	sum;

	sum = 0;
	neg = 1;
	i = 0;
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		sum = (sum * 10) + (s[i] - 48);
		i++;
	}
	return (sum * neg);
}

void	ft_freelst(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	ft_lstchr(t_stack *lst, int data)
{
	while (lst)
	{
		if (lst->value == data)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_stack	*create_element(int data)
{
	t_stack	*elm;

	elm = malloc(1 * sizeof(t_stack));
	if (!elm)
		return (NULL);
	elm->value = data;
	elm->next = NULL;
	return (elm);
}

void	ft_lstadd_back(t_stack **lst, t_stack *node)
{
	t_stack	*head;

	if (!*lst)
	{
		*lst = node;
		return ;
	}
	head = *lst;
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = node;
	*lst = head;
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
	if (v[i] && v[i] >= '0' && v[i] <= '9')
	{
		while (v[i] && v[i] >= '0' && v[i] <= '9')
		{
			if ((sum == 214748364 && v[i] > '7' && neg == 1)
				|| (sum == 214748364 && v[i] > '8' && neg == -1)
				|| sum > 214748364)
				return (0);
			sum = (sum * 10) + (v[i] - 48);
			i++;
		}
		if (!v[i])
			return (1);
	}
	return (0);
}
