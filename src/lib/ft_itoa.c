/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:22:32 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/09 21:06:24 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static size_t	ft_itoa_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_it_strdup(const char *s)
{
	char	*str;
	int		i;	

	str = malloc(ft_itoa_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*dst;
	size_t	len;
	size_t	neg;

	len = ft_intlen(n);
	if (!len)
		return (ft_it_strdup((const char *)"0"));
	if (n == -2147483648)
		return (ft_it_strdup("-2147483648"));
	neg = (n < 0);
	if (n < 0)
		n *= -1;
	dst = malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	dst[len] = '\0';
	while (len > neg)
	{
		dst[--len] = (n % 10) + 48;
		n /= 10;
	}
	if (neg)
		dst[0] = (char) '-';
	return (dst);
}
/*
#include <stdio.h>
int main ()
{
	printf("%s", ft_itoa(-9));
}
*/
