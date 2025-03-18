/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:55:26 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/18 14:28:52 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdint.h>

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*mem;

	mem = (unsigned char *)ptr;
	while (n--)
		*mem++ = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	ft_strcmp(char *s, char *d)
{
	int	i;

	i = 0;
	while (s[i] == d[i])
		i++;
	return (s[i] - d[i]);
}

int	ft_isins(char *ins)
{
	if (!ft_strcmp(ins, "ra\n"))
		return (1);
	return (0);
}

void    checking(t_stack **stack_a, t_stack **stack_b)
{
    char *instruction;

	while (1)
	{
		instruction = ft_calloc(4, sizeof(char));
		while (read(1, instruction, 4))
		{
			printf("%s", instruction);
			//exit(1);
		}
		if (ft_isins(instruction))
    		printf("%s",instruction);//ft_execins(instruction);
		else
			printf("KO");
		free (instruction);
	}
}


int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
	//if (argc - 1)
	//{
	//	if (parser(&argv[1], &stack_a))
			checking(&stack_a, &stack_b);
	//	else
	//		write(2, "Error\n", 6);
	//}
}
