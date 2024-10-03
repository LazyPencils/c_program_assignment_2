// program to demonstrate array addressing
#include <stdio.h>
#define SIZE 10

int main()
{
  int numbers[SIZE]={0};
  
  // accessing the address of the array, option-1
  printf("Address of array is =\tnumbers %p\n", numbers);
  // accessing the address of the array, option-2
    printf("Address of array is =\t&numbers[0] %p\n", &numbers[0]);
  // accessing the address of the array, option-3
  printf("Address of array is =\t&numbers[0] %p\n", &numbers);
  
}
