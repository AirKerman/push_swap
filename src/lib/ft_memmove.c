/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <rkerman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:18:57 by rkerman           #+#    #+#             */
/*   Updated: 2024/11/10 14:50:50 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*srccast;
	unsigned char		*destcast;

	srccast = (const unsigned char *) src;
	destcast = (unsigned char *) dest;
	if (dest || src)
	{
		if (destcast > srccast)
		{
			while (n)
			{
				destcast[n - 1] = srccast[n - 1];
				n--;
			}
		}
		else
		{
			while (n)
			{
				*destcast++ = *srccast++;
				n--;
			}
		}
	}
	return (dest);
}
/*
#define ELEMENT_COUNT 10
#include <stdio.h>
int	main()
{
	unsigned char	dest[13] = "Hello World";
	const void	*src = "hello world";
	int	i;
	
	memmove(dest + 2, src, 11);
	i = 0;
	while(i < 13)
	{
		printf("%c", dest[i]);
		i++;
	}
	int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

    // On affiche le contenu de la collection
    for( int i=0; i<ELEMENT_COUNT; i++ ) {
        printf( "%d ", data[i] );
    }
    puts( "" );  // Un retour à la ligne

    // On décale les éléménts dans la collection ...
    void * source = (void *) data;
    void * destination = (void *) ( data + 1 );
    size_t size = (ELEMENT_COUNT - 1) * sizeof( int );
    memmove( destination, source, size );

    // ... pour y insérer une nouvelle valeur en tête
    data[0] = 10;

    // On affiche le contenu de la collection
    for( int i=0; i<ELEMENT_COUNT; i++ ) {
        printf( "%d ", data[i] );
    }
    puts( "" );  // Un retour à la ligne	
	
}*/
