// Exercise 8.7 Solution
#include <stdio.h>
#include <stdlib.h>

int main(void) { 
    char stringValue[80]; // integer string input by user
    int sum = 0; // result of four integers
    int i; // loop counter
    
    // Loop 4 times, read string, and use strtol() to process input 
    for (i = 1; i <= 4; ++i) { 
        printf("Enter an integer string: ");
        
        // Read the string from the user
        fgets(stringValue, 80, stdin){
            // Convert stringValue to an integer and accumulate sum
            sum += (int)strtol(stringValue, NULL, 0);
        } 
    }
    
    // Output the total sum
    printf("\nThe total of the values is %d\n", sum);
 
}

 