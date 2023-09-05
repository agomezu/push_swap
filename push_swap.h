/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:13:15 by agomez-u          #+#    #+#             */
/*   Updated: 2023/09/05 18:58:53 by agomez-u         ###   ########.fr       */
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
int	stack_length(t_stack *stack);

/* Protipos de funciones para operations.c */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Prototipos de funciones para validation.c */
int	validate_input(int argc, char **argv);

/* Otros que pueden necesitarse más tarde */
// ...
int	find_min(t_stack *a, int *index);
void	sort_selection(t_stack *a, t_stack *b);

#endif /* PUSH_SWAP_H */
