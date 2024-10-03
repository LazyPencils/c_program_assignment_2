/*
   numbers and outputs the sum.
*/
#include <stdio.h>
int main(void)
{
  // declare number, sum
  // declare counter, ensure it is not signed
  int number = 0, sum = 0;
  unsigned int count = 0;
  while(count < 10)       
  {
    // read number
    printf("Enter Number %u: ", count+1);
    // read the number
    scanf("%d", &number);                   
    // accummulate sum of numbers
    sum += number;
    count++;
    // update counter
  }
  printf("The sum is %d\n", sum);
  // output the sum
}
