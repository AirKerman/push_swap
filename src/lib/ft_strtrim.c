/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:21:11 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:52:04 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char l, const char *sep)
{
	while (*sep)
	{
		if (l == *sep)
			return (1);
		sep++;
	}
	return (0);
}

static void	ft_cal_bzero(void *s, size_t n)
{
	unsigned char	*srccast;

	srccast = (unsigned char *)s;
	while (n--)
		*srccast++ = '\0';
}

static void	*ft_trim_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_cal_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*dst;
	char	*start;
	int		i;

	while (*s1 && is_sep(*s1, s2))
		s1++;
	if (!*s1)
		return (ft_trim_calloc(1, 1));
	start = (char *)s1;
	while (*s1)
		s1++;
	while (s1 && is_sep(*--s1, s2))
		;
	dst = ft_trim_calloc(1, s1 - start + 2);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < s1 - start + 1)
	{
		dst[i] = start[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
int main()
{
	//char	*str = "  test  ";
	//char	*sep = " ";
	char *s1 = "  \t \t \n   \n\n\n\t";

 	char *ret = ft_strtrim(s1, " \n\t");

	printf("%s", ret);
}
*/
