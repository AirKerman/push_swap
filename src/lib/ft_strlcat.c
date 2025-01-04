/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:59:19 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:51:35 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = 0;
	srclen = 0;
	while (dst[dstlen] && dstlen < dstsize)
		dstlen++;
	while (src[srclen])
		srclen++;
	if (dstsize == 0 || dstlen >= dstsize)
		return (dstlen + srclen);
	i = dstlen;
	while (i < dstsize - 1 && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dstlen + srclen);
}
/*
#include <stdio.h>

int main()
{
	char dst[20] = "test";
	//int i = 0;
	
	while (i < 5)
	{
		dst[i] = '\0';
		i++;
	}
	const char *src = "Hello World";

	printf("%lu\n", ft_strlcat(dst, src, sizeof(dst)));
	printf("%ld\n", sizeof(dst));
	printf("%s", dst);
}
*/
