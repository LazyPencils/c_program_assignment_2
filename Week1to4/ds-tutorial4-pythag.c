//Joshua, Yihang

#include <math.h>  // Needed for sqrt function
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int side1, side2;
    double hypotenuse;  // Using double to store the result of sqrt, since it returns a double

    for (side1 = 1; side1 <= 500; side1++) {
        for (side2 = side1; side2 <= 500; side2++) {
            
            hypotenuse = sqrt(pow(side1, 2) + pow(side2, 2));  // Calculate hypotenuse
            if (hypotenuse == (int)hypotenuse && hypotenuse <= 500) {  // Check if hypotenuse is an integer and within bounds
                printf("(%d, %d, %d)\n", side1, side2, (int)hypotenuse);  // Print valid Pythagorean triple
            }
        }
    }

    return 0;
}
