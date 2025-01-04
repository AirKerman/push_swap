/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:00:38 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/08 22:26:42 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*srccast;

	srccast = (unsigned char *)s;
	while (n--)
		*srccast++ = '\0';
}
/*
#include <stdio.h>
//#include <strings.h>
int	main()
{
	char string[5] = "teste";
	int	i = 0;
;
	bzero(string, 5);
	while (i < 5)
	{
		printf("%d", string[i]);
		i++;
	}
}
*/
