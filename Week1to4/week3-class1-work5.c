// Introduction to working with strings
#include<stdio.h>
#include<stdlib.h>
int main() 
{
  char word0[6]={'h','e','l','l','o','\0'};
  char word1[6] = "Hello";
  char word2[]="This is a test";   // declaring and initialising strings
  char word3[20];

  printf("%c %c \n", word0[2], word2[5]); 

  // printing character in a string
  printf("%s \t%s \n",word0, word2);     
  
  // printing entire string
  puts(word1);
  
  int x = 7;
  printf("The address of x is %p \n", &x);
  printf("The value of x is %d \n", x);   
  
  puts("Enter a string of length 19 characters");
  scanf("%19s", word3);      // reading string and preventing array overflow

  printf("The value of the string is %s \n", word3);

  printf("The address of the string is %p \n", word3);
  printf("The address of the string is %p \n", &word3[0]);
  printf("The address of the string is %p \n", &word3);

}
