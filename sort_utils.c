/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:21:18 by agomez-u          #+#    #+#             */
/*   Updated: 2023/09/06 19:18:09 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sort_utils.c: algoritmos de ordenación avanzados

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

// Verifica si la pila está ordenada
int	stack_is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

// Una función simple de BubbleSort para ordenar un array
void	sort_array(int *array, int size)
{
	int	temp;
	int	swapped;
	int	i;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

// Obtiene la mediana de una pila
int	get_median(t_stack *stack, int size)
{
	int	*values;
	int	i;
	int	median;
	t_node	*current;

	i = 0;
	current = stack->top;
	values = (int *)malloc(sizeof(int) * size);
	while (i < size && current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	sort_array(values, size);
	median = values[size / 2];
	free(values);
	return (median);
}

void	sort_half(t_stack *a, t_stack *b, int size, int dir)
{
	int	count;
	int	median;
	int	i;

	count = 0;
	median = get_median(a, size);
	i = 0;
	while (i < size)
	{
		if ((dir == 1 && a->top->value < median) || (dir == -1 && a->top->value > median))
		{
			execute_and_print_op("pb", a, b);
			count++;
		}
		else
			execute_and_print_op("ra", a, b);
		i++;
	}
	if (dir == 1)
	{
		quicksort_stack(b, a, count);
		while (count-- > 0)
			execute_and_print_op("pa", a, b);
	}
	else
		quicksort_stack(a, b, size - count);
}

// Algoritmos de ordenación avanzados
void	quicksort_stack(t_stack *a, t_stack *b, int size)
{
	if (size <= 1 || stack_is_sorted(a))
		return ;
	sort_half(a, b, size, 1);	// Mueve la mitad inferior a la pila b y ordena
	sort_half(a, b, size / 2, -1);	// Ordena la mitad superior en la pila a
}

void	sort_advanced(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a))
		return ;
	quicksort_stack(a, b, stack_length(a));
}

// Simplier one. This is the one we're using!!!

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

void	sort_insertion(t_stack *a, t_stack *b)
{
	int	index;
	int	len;
	int	rotations;

	while (!stack_is_sorted(a))
	{
		find_min(a, &index);
		rotations = index;
		len = stack_length(a);
		
		if (index <= len / 2)
		{
			while (rotations--)
				execute_and_print_op("ra", a, NULL);
		}
		else
		{
			rotations = len - index;
			while (rotations--)
				execute_and_print_op("rra", a, NULL);
		}
		execute_and_print_op("pb", a, b);
	}

	while (b->top)
		execute_and_print_op("pa", a, b);
}

/*
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
*/