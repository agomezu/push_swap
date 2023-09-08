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

void	print_final_result(t_stack *a)
{
	t_node	*current;

	current = a->top;
	printf("Final sorted Stack A: ");
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void	execute_and_print_op(char *op, t_stack *a, t_stack *b)
{
	if (ft_strncmp(op, "sa", 3) == 0)
		sa(a);
	else if (ft_strncmp(op, "sb", 3) == 0)
		sb(b);
	else if (ft_strncmp(op, "ss", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(op, "pa", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(op, "pb", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(op, "ra", 3) == 0)
		ra(a);
	else if (ft_strncmp(op, "rb", 3) == 0)
		rb(a);
	else if (ft_strncmp(op, "rr", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rra", 4) == 0)
		rra(a);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		rrb(b);
	else if (ft_strncmp(op, "rrr", 4) == 0)
		rrr(a, b);	
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc == 1)
		return (0);
	if (!validate_input(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = init_stack();
	b = init_stack();
	i = 1;
	while (i < argc)
	{
		push(a, ft_atoi(argv[i]));
		i++;
	}
	sort_using_all_operations(a, b);
	// Imprime el resultado final
	print_final_result(a);
	// Limpieza
	while (a->top)
		pop(a);
	while (b->top)
		pop(b);
	free(a);
	free(b);
	return (0);
}
