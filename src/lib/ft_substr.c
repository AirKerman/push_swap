/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:45:09 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:52:08 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sub_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_sub_bzero(void *s, size_t n)
{
	unsigned char	*srccast;

	srccast = (unsigned char *)s;
	while (n--)
	{
		*srccast++ = 0;
	}
}

static void	*ft_sub_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	ft_sub_bzero(mem, nmemb * size);
	return (mem);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_sub_strlen(s);
	if (start >= s_len)
		return (ft_sub_calloc(1, 1));
	if (start + len > s_len)
		len = s_len - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
int	main()
{
	char	*str = "01234";
	size_t	size = 10;

	printf("%s", ft_substr(str,10,size));
}*/
