/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:13:15 by agomez-u          #+#    #+#             */
/*   Updated: 2023/09/04 21:49:07 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
#define	PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include "libft/libft.h"

/* Estructura para un nodo de la pila */
typedef struct		s_node
{
	int		value;
	struct s_node	*next;
}			t_node;

/* Estructura para la pila */
typedef struct		s_stack
{
	t_node		*top;
}			t_stack;

/* Prototipos de funciones para stack_utils.c */
t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
int	pop(t_stack *stack);
int	peek(t_stack *stack);

/* Protipos de funciones para operations.c */
// Se agregan más tarde al implementar las operaciones

/* Prototipos de funciones para validation.c */
// Se agregan más tarde al implementar la validación

/* Otros que pueden necesitarse más tarde */
// ...

#endif /* PUSH_SWAP_H */
