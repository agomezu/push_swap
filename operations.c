/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:39:43 by agomez-u          #+#    #+#             */
/*   Updated: 2023/09/04 20:41:21 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 'sa' y 'sb' - Swap
void	sa(t_stack *a)
{
	int	temp;

	if (a && a->top && a->top->next)
	{
		temp = a->top->value;
		a->top->value = a->top->next->value;
		a->top->value = temp;
	}
}

void	sb(t_stack *b)
{
	sa(b);
}

// 'ss' - Swap a y Swap b a la vez
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

// 'pa' y 'pb' - Push
void	pa(t_stack *a, t_stack *b)
{
	int	value;

	if (b && b->top)
	{
		value = pop(b);
		push(a, value);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	value;

	if (a && a->top)
	{
		value = pop(a);
		push(b, value);
	}
}

// 'ra' y 'rb' - Rotate
void	ra(t_stack *a)
{
	t_node	*last;
	t_node	*temp;

	if (a && a->top && a->top->next)
	{
		temp = a->top;
		a->top = a->top->next;
		temp->next = NULL;
		last = a->top;
		while (last->next)
			last = last->next;
		last->next = temp;
	}
}

void	rb(t_stack *b)
{
	ra(b);
}

// 'rr' - Rotate a y Rotate b a la vez
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

// 'rra', 'rrb', y 'rrr' - Reverse rotate
void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*second_to_last;
	
	if (a && a->top && a->top->next)
	{
		last = a->top;
		while (last->next)
		{
			second_to_last = last;
			last = last->next;
		}
		second_to_last->next = NULL;
		last->next = a->top;
		a->top = last;
	}
}

void	rrb(t_stack *b)
{
	rra(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
