/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:45:44 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:51:54 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
		i++;
	}
	return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
}
/*
#include <stdio.h>

int main()
{
	const char	*str = "test\200";
	const char	*str2 = "test\0";

	printf("%d", ft_strncmp(str, str2, 6));
}*/
