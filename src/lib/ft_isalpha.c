/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:23:24 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/08 22:30:30 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main()
{
	int number;
	char caractere;

	caractere = 'e';
	number = 5;
	printf("%d\n",isalpha(caractere));
	printf("%d",isalpha(number));
}
*/
