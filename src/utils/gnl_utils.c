/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:54:30 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/21 15:07:52 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chr_c(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s, char *b)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		s = (char *)ft_calloc(1, sizeof(char));
	if (!s || !b)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(b)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			str[i] = s[i];
	while (b[j] != '\0')
		str[i++] = b[j++];
	str[i] = '\0';
	free(s);
	return (str);
}
