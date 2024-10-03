/*
    Problem Definition
        Write a program that reads an integer number and determines if the
    number is perfect. A perfect number is a number whose factors
    (including 1, but not the number itself) sums to the number.

    For example:
      6 is a perfect number, because its factors (1, 2 ,3 ) sums
      to 6.
          but 16 is not perfect, since its factors (1,2,4,8) does not
      sum does not sum to 16.

        Part 2 (Homework):
    Update your program to output all the perfect numbers less
    than 1000.
*/

#include <stdio.h>

int main()
{
    int number, sumOfFactors = 0;
    unsigned int count;

    // compute factors

    

    puts("The Factors of the Number are: ");
    for (number = 1; number < 1000; number++)
    {
        sumOfFactors = 0;
        for (count = 1; count <= number / 2; count++)
        {
            if (number % count == 0)
            {
                sumOfFactors += count;
                // printf("%d ", count);
            }
        }
        // determine if number is perfect (or not)
        if (sumOfFactors == number)
        {
            printf("The Number %d is perfect \n", number);
        }
    }
}
