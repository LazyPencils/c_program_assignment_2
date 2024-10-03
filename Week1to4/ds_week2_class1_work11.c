/*
   Write a program that uses your computer to simulate the basic
   operations of a calculator. Present the user with the following
   menu:
   1: Add
   2: Subtract
   3: Multiply
   4: Divide
   5: Exit
   Your program should allow the user to enter a choice along with 2
   integers and then perform the appropriate computation and output
   the result to the user. The program should only exit when the user
   selects option 5.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
   int answer = 0, number1, number2, userChoice;

   while (true)
   {

      puts("1: Add");
      puts("2: Subtract");
      puts("3: Multiply");
      puts("4: Divide");
      puts("5: Exit    ");
      printf("Enter Choice: ");
      scanf("%d", &userChoice);

      switch (userChoice)
      {
      case 1:
         printf("Enter First Number: ");
         scanf("%d", &number1);
         printf("Enter Second Number: ");
         scanf("%d", &number2);
         answer = number1 + number2;
         printf("The Sum is %d\n", answer);
         break;
      case 2:
         printf("Enter First Number: ");
         scanf("%d", &number1);
         printf("Enter Second Number: ");
         scanf("%d", &number2);
         answer = number1 - number2;
         printf("The Answer is %d\n", answer);
         break;
      case 3:
         printf("Enter First Number: ");
         scanf("%d", &number1);
         printf("Enter Second Number: ");
         scanf("%d", &number2);
         answer = number1 * number2;
         printf("The Product is %d\n", answer);
         break;
      case 4:
         printf("Enter First Number: ");
         scanf("%d", &number1);
         printf("Enter Second Number: ");
         scanf("%d", &number2);
         answer = number1 / number2;
         printf("The answer is %d\n", answer);
         break;
      case 5:
      puts("Program Exiting... goodbye");
      exit(0);
         break;
      default:
         break;
      }
   }
}
