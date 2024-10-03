/*
   Write a program that accepts a series of numbers from the user, 
   totals and averages the numbers and then outputs the 
   total and average.
*/
#include <stdio.h>
int main(void)
{
  int number = 0, total = 0; 
  float average = 0.0;
  unsigned int counter = 0;
  scanf("%d", &number);
  while(number != -1)  
  {
     //accumulate total for numbers entered;
     total += number;
     //count each number 
     counter++;
     //continue to get user input 
     printf("Enter Number... -1 to quit: ");
      scanf("%d", &number);
  }

  if(counter == 0){
   //printf("No numbers were entered\n");
   puts("No numbers were entered");
  }
  else{
      average = (float)total / counter;
  }

  
      printf("Total is %d\n", total);
      printf("Average is %f\n", average);
      printf("Count is %u\n", counter);
  // compute average
  // Output total, average, counter
  
}



