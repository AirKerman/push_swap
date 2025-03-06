/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkerman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:08 by rkerman           #+#    #+#             */
/*   Updated: 2025/03/06 14:50:33 by rkerman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_new_min(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_a->value > stack_b->value)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int	is_new_max(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_a->value < stack_b->value)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int	pos_max(t_stack *stack)
{
	int	max_pos;
	int	i;
	int	max;

	i = 0;
	max = stack->value;
	max_pos = i;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (max_pos);
}

int	who_is_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_pos(t_stack *stack, int data)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == data)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}

/*

	si les deux son proche du centre suivre 1 direction peux raccourcir le chemin et faire econimisez des coups par la suite

	par exemple 
	
	stack_a :
	1 2 3 4 5 6 7 8 9

	stack_b :
	10 11 12 13 14 15 16 17 18

	en voulant par exemple deplacer le 13 et le 6 il serais + judicieux de faire un coup combiner pour deplacer le 6 en 1 ere place
	avec le 13 il restera - de coup a faire et cela divisera le nombre de coup effectuer donc apres le deplacement de 6 mmh enfin de
	compte deplacer le 13 combiner du 6 avec un rr serais plus rentable (economie de 1 constant)

	il serais + judicieux de commencer par le combiner en rr et pas en rrr le rrr est seulement si le rr n est pas rentable car le rr
	est toujours plus avantageux

	plus qu a trouver comment savoir si cest rentable de rr a la place de rrr pour ca il faudra stocker le nombre de coup en rrr et en rr
	des deux valeur afin dy concocter une formule qui aura la solution il faudrais donc regarder si le fais de deplacer les 2 en meme temps
	reduirais drastiquement ca position de la premiere place donc occupons nous de la fonction des rr

	rrshot = (len - pos) = coup en reverse rotate

	desormais il faut voir ou ce situation le chiffre concerner par un reverse rotate apres lexecution du rotate classic donc 
	shotrotate classic - positionceluienreverserotate
*/

int	bellow_med(int len_a, int len_b, int pos_target, int pos_bullet)
{
	int	shot;

	shot = 0;
	if ((pos_bullet < len_a / 2 && pos_target < len_b / 2)
		|| (pos_bullet == len_a / 2 && len_a % 2 > 0
		&& pos_target == len_b / 2 && len_b % 2 > 0)
		|| (pos_bullet <= len_a / 2 && pos_target >= len_b / 2
		&& (pos_target - pos_bullet ) <= (len_b - pos_target))
		|| (pos_target <= len_b / 2 && pos_bullet >= len_a / 2
		&& ((pos_bullet - pos_target) <= (len_a - pos_bullet))))
	{
		if (pos_bullet > pos_target)
			shot = pos_bullet + 1;
		else
			shot = pos_target + 1;
	}
	return (shot);
}

int	top_med(int len_a, int len_b, int pos_target, int pos_bullet)
{
	int	shot;

	shot = 0;
	if ((pos_bullet > len_a / 2 && pos_target > len_b / 2)
		|| (pos_bullet == len_a / 2 && len_a % 2 == 0
		&& pos_target == len_b / 2 && len_b % 2 == 0)
		|| (pos_bullet > len_a / 2 && pos_target <= len_b / 2
		&& (len_b - (pos_target + (len_a - pos_bullet))) < pos_target)
		|| (pos_target > len_b / 2 && pos_bullet <= len_a / 2
		&& (len_a - (pos_bullet + (len_a - pos_target))) <= pos_bullet)
		)
	{
		if ((len_a - pos_bullet) > (len_b - pos_target))
			shot = len_a - pos_bullet + 1;
		else
			shot = len_b - pos_target + 1;
	}
	return (shot);
}

int	shot_calcul(int len_a, int len_b, int pos_target, int i)
{
	int	shot;

	shot = bellow_med(len_a, len_b, pos_target, i);
	if (!shot)
	{
		top_med(len_a, len_b, pos_target, i);
		if (!shot && ((pos_target < len_b / 2 && i > len_a / 2) || (i == len_a / 2 && len_a % 2 == 0)))
			shot = pos_target + (len_a - i) + 1;
		else
			shot = i + (len_b - pos_target) + 1;
	}

	/*
	if (pos_target >= len_b / 2 && i >= len_a / 2)
	{
		if ((len_a - i) > (len_b - pos_target))
			shot = len_a - i + 1;
		else
			shot = len_b - pos_target + 1;
	}
	else if ((pos_target < len_b / 2 && i < len_a / 2)
		|| (i < len_a / 2 && len_b < 4 && pos_target < 2)
		|| (pos_target < len_b / 2 && len_a < 4 && i < 2))
		
	{
		if (i > pos_target)
			shot = i + 1;
		else
			shot = pos_target + 1;
	}
	else if ((pos_target < len_b / 2 && i > len_a / 2) || (i == len_a / 2 && len_a % 2 == 0))
		shot = pos_target + (len_a - i) + 1;
	else
		shot = i + (len_b - pos_target) + 1;*/
	return (shot);
}

void	is_min_or_max_calcul(t_stack *stack_a, t_stack *stack_b, t_stat *p, int i)
{
	int	shot;

	if (!i && !pos_max(stack_b) && (!p->shotcount || p->shotcount > 1))
		shot = 1;
	else
		shot = shot_calcul(ft_lstlen(stack_a) + i, ft_lstlen(stack_b), pos_max(stack_b), i);
	if (shot < p->shotcount || !p->shotcount)
	{
		p->shotcount = shot;
		p->bullet = stack_a->value;
		p->target = stack_b->value;
	}
}

int	target_finder(t_stack *stack_a, t_stack *stack_b)
{
	int	target;

	while (stack_b)
	{
		if (stack_b->value < stack_a->value)
			break;
		stack_b = stack_b->next;
	}
	target = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value < stack_a->value && target < stack_b->value )
			target = stack_b->value;
		stack_b = stack_b->next;
	}
	return (target);
}

void	is_random_num_calcul(t_stack *stack_a, t_stack *stack_b, t_stat *p, int i)
{
	int	shot;

	shot = shot_calcul(ft_lstlen(stack_a) + i, ft_lstlen(stack_b), get_pos(stack_b, target_finder(stack_a, stack_b)), i);
	if (shot < p->shotcount || !p->shotcount)
	{
		p->shotcount = shot;
		p->bullet = stack_a->value;
		p->target = target_finder(stack_a, stack_b);
	}
}

void	panel_init(t_stat *panel)
{
	panel->shotcount = 0;
	panel->target = 0;
	panel->bullet = 0;
}

void	ft_calcul_lowcost(t_stack *stack_a, t_stack *stack_b, t_stat *panel)
{
	int		ia;
	
	ia = 0;
	while (stack_a)
	{
		if (is_new_min(stack_a, stack_b) || is_new_max(stack_a, stack_b))
			is_min_or_max_calcul(stack_a, stack_b, panel, ia);
		else
			is_random_num_calcul(stack_a, stack_b, panel, ia);
		ia++;
		stack_a = stack_a->next;
	}
}

void	ft_calcul_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	t_stat panel;

	panel_init(&panel);
	ft_calcul_lowcost(*stack_a, *stack_b, &panel);
	//ft_execute();
}
