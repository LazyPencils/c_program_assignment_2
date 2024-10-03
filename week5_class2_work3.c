/*
Part A:
Write a program that creates a structure called "Friend". You should house at least 3 
different pieces / types of data in your structures. Furthermore, create an array of N friends, 
where N is a predefined constant, load the array and output the details of your friends. 
Include in your data items, a piece of data called "price", which is the price of a bus ticket
that each friend would need to travel to your house. Your program should calculate the total cost 
for all friends travelling to your house.

Part B: 
Please use a separate function to print out the details for each friend. 
Pass a single structure to the function.

Part C: 

Please use a separate function to print out the details for each friend. Pass an array of structures to the function.

Part D:
Create a new structure called address with at least 4 appropriate members and ensure that each friend now has a home address (this should be a separate structure).
*/ 

#include <stdio.h>
#define N 3

// structure definition
  //age
  //name
  //price
  // structure renaming
  typedef struct friend{
    unsigned int age;
    char name[20];
    float price;
  } Friend;



int main ()
{
  // declare array of structures for 3 friends
    
  // read values into array-of-structures


 // declare array of structures for 3 friends
  size_t i;  
  Friend myFriends[N];
  float totalCost = 0.0;

  // read values into array-of-structures
  for (i = 0; i < N; i++)
  {
    printf("Enter age          of friend %zu: ", i+1);  // Use %zu for size_t
    scanf("%u", &myFriends[i].age);
    printf("Enter name         of friend %zu: ", i+1);  // Use %zu for size_t
    scanf("%19s", myFriends[i].name);
    printf("Enter ticket price of friend %zu: ", i+1);  // Use %zu for size_t
    scanf("%f", &myFriends[i].price);
    totalCost += myFriends[i].price;
  }

  // print values from array-of-structures
  printf("Age\tName\n");
  for (i = 0; i < N; i++)
  {
    printf("%u\t%s\t%.2f\n", myFriends[i].age, myFriends[i].name, myFriends[i].price);
  }
  printf("Total cost for all friends is %.2f\n", totalCost);
  // print values from array-of-structures
  
}
