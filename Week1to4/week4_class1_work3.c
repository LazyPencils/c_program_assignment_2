// Write a program that will use a function to increase a user supplied input 
// by 10%
#include <stdio.h>

// function prototype for a pass-by-value
int increaseUsingPassByValue(int valueCopy);
int main(void)
{
   int value, answer=0;
   printf("Enter Value to be Increased: ");
   scanf("%d", &value);
   printf("The old value %d: \n", answer);
   // add code for function call here 
   
   answer = increaseUsingPassByValue(value);

   printf("The answer is %d: \n", answer);
}

// Implement function definition here
int increaseUsingPassByValue(int valueCopy){
   valueCopy = valueCopy * 1.1;
   return valueCopy;
}
