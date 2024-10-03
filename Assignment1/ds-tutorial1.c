#include <stdio.h>

int main()
{
    int number; // Variable to store the user's input

    // Prompt the user to enter an integer
    printf("Enter The Integer: ");
    
    // Read the integer input from the user
    scanf("%d", &number);

    // Check if the integer is even or odd
    if((number % 2) == 0) {
        // If the remainder when divided by 2 is 0, it's an even number
        printf("This integer is even\n");
    } else {
        // Otherwise, it's an odd number
        printf("This integer is odd\n");
    }
}
