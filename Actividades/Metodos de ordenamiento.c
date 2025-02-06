#include <stdio.h>

// PRE: 'size' debe estar inicializado correctamente.
// POST: 'array' queda ordenado en orden ascendente.
void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// PRE: 'size' debe estar inicializado correctamente.
// POST: 'array' queda ordenado en orden ascendente.
void selection_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

// PRE: 'size' debe estar inicializado correctamente.
// POST: 'array' queda ordenado en orden ascendente.
void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int current_element = array[i];
        int previous_index = i - 1;
        while (previous_index >= 0 && array[previous_index] > current_element) {
            array[previous_index + 1] = array[previous_index];
            previous_index--;
        }
        array[previous_index + 1] = current_element;
    }
}