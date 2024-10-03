#include <stdio.h>

#define SIZE 10  // Define the symbolic constant for array size

int main() {
    // Part a: Define an array of floats with 10 elements initialized with 0.0, 1.1, 2.2, ..., 9.9
    float numbers[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};

    // Part b: Define a pointer nPtr that points to a float object
    float *nPtr;

    // Part c: Print the elements of array numbers using array subscript notation
    // Print each number with 1 decimal precision
    printf("Part c: Array subscript notation\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.1f\n", numbers[i]);
    }

    // Part d: Two separate statements that assign the starting address of array numbers to nPtr
    nPtr = numbers;         // First way
    nPtr = &numbers[0];     // Second way

    // Part e: Print the elements of array numbers using pointer/offset notation with nPtr
    printf("\nPart e: Pointer/offset notation with nPtr\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.1f\n", *(nPtr + i));
    }

    // Part f: Print the elements of array numbers using pointer/offset notation with array name
    printf("\nPart f: Pointer/offset notation with array name\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.1f\n", *(numbers + i));
    }

    // Part g: Print the elements of array numbers by subscripting pointer nPtr
    printf("\nPart g: Subscript pointer nPtr\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.1f\n", nPtr[i]);
    }

    // Part h: Refer to 4 elements of array numbers using 3 different notations
    printf("\nPart h: Referencing first 4 elements with different notations\n");
    for (int i = 0; i < 4; i++) {
        // Array subscript notation
        printf("Array subscript notation: %.1f\n", numbers[i]);
        // Pointer subscript notation with nPtr
        printf("Pointer subscript notation with nPtr: %.1f\n", nPtr[i]);
        // Pointer/offset notation with nPtr
        printf("Pointer/offset notation with nPtr: %.1f\n", *(nPtr + i));
    }

    // Part i: Calculate nPtr + 8 and print the address and value
    nPtr = numbers;  // Point nPtr to the beginning of the array
    printf("\nPart i: Address and value at nPtr + 8\n");
    printf("Address of nPtr + 8: %p, Value: %.1f\n", (nPtr + 8), *(nPtr + 8));

    // Part j: Point nPtr to numbers[5], subtract 4, and print the new address and value
    nPtr = &numbers[5];  // Point nPtr to numbers[5]
    nPtr -= 4;           // Subtract 4 from the pointer
    printf("\nPart j: Address and value after nPtr -= 4\n");
    printf("Address of nPtr -= 4: %p, Value: %.1f\n", nPtr, *nPtr);

    return 0;
}
