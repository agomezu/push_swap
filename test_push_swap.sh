#!/bin/bash

# Test script for push_swap

# Número de tests a realizar
NUM_TESTS=100

# Rango de números a generar
RANGE=100

# Número de números en cada test
NUM_VALUES=50

# Función para comprobar si la lista está ordenada
check_sorted() {
    echo "$1" | awk 'BEGIN{prev=-inf; flag=0} {if ($1<prev) {flag=1; exit}} {prev=$1} END{print !flag}'
}

# Iniciar el test
for ((i=1; i<=$NUM_TESTS; i++)); do
    # Generar una lista aleatoria de números usando seq y sort -R
    VALUES=$(seq 1 $RANGE | sort -R | head -n $NUM_VALUES | tr '\n' ' ')
    
    # Pasar los valores a push_swap
    RESULT=$("./push_swap" $VALUES)
    
    # Comprobar si el resultado está ordenado
    IS_SORTED=$(check_sorted "$RESULT")

    # Mostrar el resultado
    if [[ "$IS_SORTED" -eq "1" ]]; then
        echo "Test $i: PASS"
    else
        echo "Test $i: FAIL"
        echo "Input: $VALUES"
        echo "Output: $RESULT"
    fi
done
