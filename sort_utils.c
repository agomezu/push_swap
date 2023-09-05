/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:21:18 by agomez-u          #+#    #+#             */
/*   Updated: 2023/09/05 19:36:58 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char stack_name)
{
	t_node	*current = stack->top;
	printf("Stack %c: ", stack_name);
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

int	find_min(t_stack *a, int *index)
{
	t_node	*current;
	int	min;
	int	i;

	min = 0;
	if (!a || !a->top)
		return (INT_MAX);
	current = a->top;
	min = current->value;
	*index = 0;
	i = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			*index = i;
		}
		i++;
		current = current->next;
	}
	return (min);
}

void	sort_selection(t_stack *a, t_stack *b)
{
	int	index;
	int	rotations;
	int	len;

	len = stack_length(a);
	while (len > 0)
	{
		print_stack(a, 'A');
		print_stack(b, 'B');

		find_min(a, &index);
		rotations = index;

		printf("Moving smallest item at index %d to stack B\n", index);

		while (index-- > 0)
		{
			ra(a);
			print_stack(a, 'A');
		}
		pb(a, b);
		print_stack(b, 'B');
		while (rotations++ < len - 1)
		{
			rra(a);
			print_stack(a, 'A');
		}
		printf("\nMoving all items back to stack A\n");
		len--;
	}
	while (b->top)
	{
		pa(a, b);
		print_stack(a, 'A');
	}
}
