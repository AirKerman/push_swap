/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:04:15 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:50:47 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*srccast;
	unsigned char		*destcast;

	srccast = (const unsigned char *)src;
	destcast = (unsigned char *)dest;
	if (n == 0 || (!dest && !src))
		return (dest);
	while (n--)
		*destcast++ = *srccast++;
	return (dest);
}
/*
#include <stdio.h>
int	main()
{
	//char *string1 = "test";
	//char *string = string1;

	printf("%p", ft_memcpy((void *)0, (void*)0, 4));	
}
*/
