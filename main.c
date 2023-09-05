/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:13:10 by agomez-u          #+#    #+#             */
/*   Updated: 2023/09/05 20:17:09 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_and_print_op(char *op, t_stack *a, t_stack *b)
{
	// ...
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	i = 0;
	if (argc == 1)
		return (0);
	if (!validate_input(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = init_stack();
	b = init_stack();
	while (i++ < argc)
		push(a, ft_atoi(argv[i]));

	// Aquí va el algoritmo de ordenación.
	// Usamos execute_and_print_op en lugar de las funciones directamente.
	// Por ejemplo: execute_and_print_op("ra", a, b);
	
	// Limpieza
	while (a->top)
		pop(a);
	while (b->top)
		pop(b);
	free(a);
	free(b);

	return (0);
}
