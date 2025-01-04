/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:16:34 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:50:45 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && src1[i] == src2[i])
		i++;
	return (src1[i] - src2[i]);
}
/*
#include <stdio.h>
int main()
{
	const char *src1 = "test";
	const char *src2 = "tfst";

	printf("%d", ft_memcmp(src1,src2,5));
	char s[] = {-128, 0, 127, 0};
        char sCpy[] = {-128, 0, 127, 0};
        char s2[] = {0, 0, 127, 0};
        char s3[] = {0, 0, 42, 0};
	
}
*/
