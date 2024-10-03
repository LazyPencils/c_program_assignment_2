/* 
 *Program to read two integer numbers from the keyboard
 *compute the sum, difference, quotient, product and remainder
 *and output these results to the console
*/
#include <stdio.h> /* add code for header file */
int main (void)
{
   /* define data containers to store results*/  
   int sum = 0, difference = 0, product = 0, 
   quotient = 0, remainder = 0;

   /* define data containers to store input data*/
   int number1 = 0, number2 = 0;
   
   /* read first number from the keyboard */
    // prompt the user
    printf("Enter First Number: ");
    // read the number
   scanf("%d", &number1);
   /* read second number from the keyboard */
    // prompt the user
    // read the number
   printf("Enter Second Number: ");
    // read the number
   scanf("%d", &number2);
   /* Compute the sum, product, quotient, difference & remainder */
   sum = number1 + number2;
   difference = number1 - number2;
   product = number1 * number2;
   quotient = number1 / number2;
   remainder = number1 % number2;
   
   /* Output the results */
   printf("Sum is: %d\n", sum);
   printf("Difference is: %d\n", difference);
   printf("Product is: %d\n", product);
   printf("Quotient is: %d\n", quotient);
   printf("Remainder is: %d\n", remainder);

}


