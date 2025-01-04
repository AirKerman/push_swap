/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:16:30 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:51:24 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_join_strlen(const char *s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

static void	ft_join_bzero(void *s, size_t n)
{
	unsigned char	*srccast;

	srccast = (unsigned char *)s;
	while (n--)
		*srccast++ = '\0';
}

static void	*ft_join_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_join_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lenstr;
	char	*res;
	size_t	i;
	size_t	j;

	lenstr = ft_join_strlen(s1) + ft_join_strlen(s2);
	res = ft_join_calloc(1, lenstr + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		res[i] = s1[j];
		j++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main()
{
	printf("%s",ft_strjoin(ft_strjoin("this is", " nyancat "),"456"));
}
*/
