/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:11:04 by agomez-u          #+#    #+#             */
/*   Updated: 2023/09/05 18:38:00 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Inicializar una nueva pila
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

// Push (agregar un valor a la pila)
void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

// Pop (eliminar y devolver el valor superior de la pila)
int	pop(t_stack *stack)
{
	t_node	*temp;
	int	value;

	if (!stack || !stack->top)
		return (INT_MIN);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	return (value);
}

// Peek (ver el valor superior de la pila sin eliminarlo)
int	peek(t_stack *stack)
{
	if (!stack || !stack->top)
		return (INT_MIN);
	return (stack->top->value);
}

// Stack length (para contar el tamaño de una lista)
int	stack_length(t_stack *stack)
{
	t_node	*current;
	int	count;

	count = 0;
	current = stack->top;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}
