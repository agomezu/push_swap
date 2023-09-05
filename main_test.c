#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (!validate_input(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = init_stack();
	b = init_stack();
	for (int i = 1; i < argc; i++)
		push(a, ft_atoi(argv[i]));
	sort_selection(a, b);
	t_node	*current = a->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	// Cleaning
	while (a->top)
		pop(a);
	while (b->top)
		pop(b);
	free(a);
	free(b);
}
