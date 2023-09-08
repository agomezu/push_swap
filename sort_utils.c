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

int find_min(t_stack *a, int *min_index) {
    t_node *current = a->top;
    int min_val, idx, position;

    if (!current) {
        *min_index = -1;
        return INT_MAX; // Represents an empty or error value.
    }

    min_val = current->value;
    position = 0;
    idx = 0;

    while (current) {
        if (current->value < min_val) {
            min_val = current->value;
            position = idx;
        }
        idx++;
        current = current->next;
    }

    *min_index = position;
    return min_val;
}

int shortest_rotation_direction(t_stack *a, int target_val) {
    t_node *current = a->top;
    int position = 0;
    int total_len = stack_length(a);

    while (current && current->value != target_val) {
        position++;
        current = current->next;
    }

    // If the position is less than or equal to half the size, upward rotation is shorter.
    if (position <= total_len / 2) {
        return 1;
    } else { 
        // Otherwise, downward rotation is shorter.
        return -1;
    }
}

void rotate_till_min_at_top(t_stack *a, t_stack *b, int min_val, int direction) {
    while (a->top->value != min_val) {
        if (direction == 1) {
            if (b->top && b->top->next && b->top->value < b->top->next->value) {
				execute_and_print_op("rr", a, b);
            } else {
				execute_and_print_op("ra", a, NULL);
            }
        } else {
            if (b->top && b->top->next && b->top->value < b->top->next->value) {
				execute_and_print_op("rrr", a, b);
            } else {
				execute_and_print_op("rra", a, NULL);
            }
        }
    }
}

void move_mins_to_b(t_stack *a, t_stack *b) {
    int min_val, direction;

    while (a->top) {
        min_val = find_min(a, &direction);
        direction = shortest_rotation_direction(a, min_val);
        rotate_till_min_at_top(a, b, min_val, direction);
		execute_and_print_op("pb", a, b);
    }
}

void move_all_to_a(t_stack *a, t_stack *b) {
    while (b->top) {
		execute_and_print_op("pa", a, b);
    }
}

void sort_using_all_operations(t_stack *a, t_stack *b) {
	move_mins_to_b(a, b);
    move_all_to_a(a, b);
}

