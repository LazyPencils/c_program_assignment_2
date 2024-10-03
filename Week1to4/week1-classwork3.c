//Program to read 2 numbers and determine if one is larger or if they are equal
#include <stdio.h>
int main (void)
{
   
   int number1, number2;
   
   printf("Enter First Integer: ");
   scanf("%d", &number1);
   
   printf("Enter Second Integer: ");
   scanf("%d", &number2);

   /* determine if first number is greater */
   if( number1 > number2 ){
    printf("Number 1 is greater\n");
   }
   
   /* determine if second number is greater*/
   if( number1 < number2 ){
    printf("Number 2 is greater\n");
   }
   
   /* determine both numbers are equal     */  
   if ( number1 == number2 ){
    printf("The numbers are equal\n");
   }
   
 } // main function ends here


//long double LF LF
//