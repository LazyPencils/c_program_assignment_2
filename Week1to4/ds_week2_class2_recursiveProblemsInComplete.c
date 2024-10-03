// Use recursion to solve and test the following problems
#include <stdio.h>
unsigned long long int factorial(unsigned long long int number);
int myPower(int base, int exp);
int multiply(int x, int y);
int divide (int numerator, int denominator);
int findSumOfDigits(int n);
int countDigits(int n);
int sumOfNaturals (int n);
int main()
{
    int result = 0;
    /* testing recursive solutions */
    // result = factorial(14);
    // result = myPower(4, 3);
    // result = multiply(10,5);
    // result = divide(9,3);
    // result = findSumOfDigits(7583764);
    result = sumOfNaturals(10);
    // result = countDigits(5837675);
    printf("The Result is %d\n", result);
}

unsigned long long int factorial(unsigned long long int number)
{
    if (number <= 1)
        return 1;
    else
        return number * factorial(number - 1);
}

int myPower(int base, int exp)
{
    if (exp == 0)
        return 1;
    else if (exp == 1)
        return base;
    else
        return base * myPower(base, exp - 1);
}

int multiply(int num1, int num2)
{
    if(num2 == 0)
        return 0;
    else
        return num1 + multiply(num1, num2 - 1);
}

int divide (int numerator, int denominator)
{
    if(denominator > numerator)
        return 0;
    else 
        return 1 + divide((numerator - denominator), denominator);
    
}

int findSumOfDigits(int n)
{
    
    if(n == 0)
        return 0;
    else 
        return n % 10 + findSumOfDigits(n / 10);
}

int countDigits(int n)
{

if(n == 0)
        return 0;
    else 
        return 1 + countDigits(n / 10);
    

}

int sumOfNaturals (int n)
{
    //eg 5 === 5+4+3+2+1 = 15
    if(n == 0)
        return 0;
    else
        return n + sumOfNaturals(n - 1);
}
/*
// this method sums together the first n natural numbers





// sums the digits in the number


// Divide by using a series of subtractions
int divide (int numerator, int denominator)
{

}


// Multiply two positive integers by using a series of additions




// Computes the factotorial of an integer number
int factorial (int number)

{


}

// Raises base to exp




*/
