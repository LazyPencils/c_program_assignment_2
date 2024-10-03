#include <stdio.h>
int main (void)
{
   int digit1=0, digit2=0, digit3=0, digit4=0, number=0, encodedNum=0, originalNumber=0;
   
   // Prompt the user to enter a 4-digit number
   printf("Enter a 4-digit Number: ");
   scanf("%d",&number);

   // Store the original number before modification for later display
   originalNumber = number;

   // Split the number into individual digits (from right to left)
   digit4 = number % 10;   // Get the last digit
   number = number / 10;   // Remove the last digit from the number

   digit3 = number % 10;   // Get the third digit
   number = number / 10;   // Remove the third digit from the number

   digit2 = number % 10;   // Get the second digit
   number = number / 10;   // Remove the second digit from the number

   digit1 = number % 10;   // Get the first digit (most significant digit)
   number = number / 10;   // Remove the first digit from the number

   // Modify each digit by adding 7 and taking modulo 10 (digit encryption logic)
   digit4 = (digit4 + 7) % 10;
   digit3 = (digit3 + 7) % 10;
   digit2 = (digit2 + 7) % 10;
   digit1 = (digit1 + 7) % 10;
   
   // Rearrange the modified digits to reverse the order
   // Multiply by appropriate powers of 10 to move the digits to their new places
   digit4 = digit4 * 100;  // Move the last digit to the hundred's place
   digit3 = digit3 * 1000; // Move the third digit to the thousand's place
   digit2 = digit2 * 1;    // Keep the second digit in the unit's place
   digit1 = digit1 * 10;   // Move the first digit to the ten's place

   // Calculate the reversed and modified number
   encodedNum = digit3 + digit4 + digit1 + digit2;

   // Output both the original and the encoded number
   printf("The original number was: %d\n", originalNumber);
   printf("The encoded number: %d\n", encodedNum);
}
