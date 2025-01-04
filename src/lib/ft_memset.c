/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:42:01 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:50:52 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*strcast;

	strcast = (unsigned char *)s;
	while (n--)
		*strcast++ = (unsigned char)c;
	return (s);
}
/*
#include <stdio.h>
int	main()
{
	char	arr[5] = "eisu";
	memset(arr + 1, 'A', 4);
	int i = 0;
	while(i < 5)
	{
		printf("%c",arr[i]);
		i++;
	}
}
*/
