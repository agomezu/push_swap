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
        return INT_MAX; // Representa un valor vacío o un error.
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

int shortest_rotation_direction(t_stack *a, int min_val) {
    t_node *current = a->top;
    int position = 0;
    int total_len = stack_length(a);

    while (current && current->value != min_val) {
        position++;
        current = current->next;
    }

    // Si la posición es menor o igual a la mitad del tamaño, la rotación hacia arriba es más corta.
    if (position <= total_len / 2) {
        return 1;
    } else { // En caso contrario, la rotación hacia abajo es más corta.
        return -1;
    }
}

// Encuentra el valor mínimo y la dirección de rotación
void find_min_val_and_dir(t_stack *a, int *min_val, int *direction) {
    int min_index;
    *min_val = find_min(a, &min_index);
    *direction = shortest_rotation_direction(a, *min_val);
}

// Rota A hasta que el valor mínimo esté en la parte superior
void rotate_till_min_at_top(t_stack *a, t_stack *b, int min_val, int direction) {
    while (a->top->value != min_val) {
        if (direction == 1) {
            if (b->top && b->top->next && b->top->value < b->top->next->value) {
                rr(a, b);
            } else {
                ra(a);
            }
        } else {
            if (b->top && b->top->next && b->top->value < b->top->next->value) {
                rrr(a, b);
            } else {
                rra(a);
            }
        }
    }
}

// Mueve todos los mínimos de A a B
void move_mins_to_b(t_stack *a, t_stack *b) {
    int min_val, direction;

    while (a->top) {
        find_min_val_and_dir(a, &min_val, &direction);
        rotate_till_min_at_top(a, b, min_val, direction);
        pb(a, b);
    }
}

// Mueve todos los valores de B de vuelta a A
void move_all_to_a(t_stack *a, t_stack *b) {
    while (b->top) {
        pa(a, b);
    }
}

// Función principal de ordenación
void sort_using_all_operations(t_stack *a, t_stack *b) {
    move_mins_to_b(a, b);
    move_all_to_a(a, b);
}
