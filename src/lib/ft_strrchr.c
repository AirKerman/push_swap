/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:18:20 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:52:00 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;

	src = (char *) s;
	while (*src)
		src++;
	if ((unsigned char)c == '\0')
		return (src);
	while (src >= s)
	{
		if (*src == (unsigned char)c)
			return (src);
		src--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	const char *src = "test";
	char	l = '\0';

	printf("%s", ft_strrchr(src,l));

	 char str[] = "Hello, world!";
    char *result;

    result = ft_strrchr(str, 'o');
    if (result)
        printf("Found 'o' at position: %ld\n", result - str);
    else
        printf("'o' not found\n");

    result = ft_strrchr(str, 'z');
    if (result)
        printf("Found 'z' at position: %ld\n", result - str);
    else
        printf("'z' not found\n");

    result = ft_strrchr(str, '\0');
    if (result)
        printf("Found '\\0' at the end of the string\n");

    return 0;
}*/
