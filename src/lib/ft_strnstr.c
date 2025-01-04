/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:25:40 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:51:58 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	j = 0;
	while (big[j] && j < len)
	{
		i = 0;
		while (big[j + i] == little[i] && (i + j) < len)
		{
			i++;
			if (!little[i])
				return ((char *)&big[j]);
		}
		j++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	const char	*src = "test";
	const char	*find = "s";

	printf("%s", ft_strnstr(src, find, 2));
}*/
