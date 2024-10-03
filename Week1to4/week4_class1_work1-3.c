// Write a program that will use a function to increase a user supplied input 
// by 10%
#include <stdio.h>

// function prototype for a pass-by-reference/address/pointer
void increaseUsingPassByReference(int *valuePtr);
int main(void)
{
   int value;
   printf("Enter Value to be Increased: ");
   scanf("%d", &value);
   printf("The old value %d: \n", value);
   increaseUsingPassByReference(&value);
   printf("The answer is %d: \n", value);
}

// Implement function definition here
void increaseUsingPassByReference(int *valuePtr){
   *valuePtr = *valuePtr * 1.1;   
}
