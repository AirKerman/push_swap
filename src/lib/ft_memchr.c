/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:01:11 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:50:42 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	if (n == 0)
		return (NULL);
	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *)&src[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
		char *src = "bonjour";
		int	l = 'o';
	
		printf("%s", (char	*)ft_memchr(src,l,7));
}
*/
