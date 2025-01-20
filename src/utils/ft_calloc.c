/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:37:37 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/11 17:47:41 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_cal_bzero(void *s, size_t n)
{
	unsigned char	*srccast;

	srccast = (unsigned char *)s;
	while (n--)
		*srccast++ = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_cal_bzero(ptr, nmemb * size);
	return (ptr);
}
