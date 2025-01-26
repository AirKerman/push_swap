/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:02:35 by rkerman           #+#    #+#             */
/*   Updated: 2025/01/26 14:44:14 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct t_list
{
	int				value;
	struct t_list	*next;
}	t_stack;


/*

	Algorithm

*/

void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_sortmin(t_stack **stack, int len);

/*

	Utils

*/

int		ft_arrlen(char **a);
int		ft_strlen(const char *s);
int		ft_lstlen(t_stack *lst);
int		ft_lstissort(t_stack *stack);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
int		format_v(char *v);
int		ft_atoi(char *s);
t_stack	*create_element(int data);
void	ft_lstadd_back(t_stack **lst, t_stack *node);
int		ft_lstchr(t_stack *lst, int data);
void	ft_freelst(t_stack **lst);
void	free_arr(char **arr);
int		format_v(char *v);
int		parser(char **value, t_stack **stack);


/*

	Instructions

*/

void	sa(t_stack **stack, int trigger);
void	sb(t_stack **stack, int trigger);
void	ss(t_stack **stack_a, t_stack **stack_b, int trigger);
void	pa(t_stack **stack_b, t_stack **stack_a, int trigger);
void	pb(t_stack **stack_a, t_stack **stack_b, int trigger);
void	ra(t_stack **stack, int trigger);
void	rb(t_stack **stack, int trigger);
void	rr(t_stack **stack_a, t_stack **stack_b, int trigger);
void	rra(t_stack **stack, int trigger);
void	rrb(t_stack **stack, int trigger);
void	rrr(t_stack **stack_a, t_stack **stack_b, int trigger);

#endif
