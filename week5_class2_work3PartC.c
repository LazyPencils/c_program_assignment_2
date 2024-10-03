#include <stdio.h>
#define N 3

// Structure definition for Friend
typedef struct friend {
    unsigned int age;
    char name[20];
    float price;
} Friend;

// Function declaration
void printDetails(Friend allFriends[N]);

int main() {
    size_t i;  
    Friend myFriends[N];
    float totalCost = 0.0;

    // Read values into array-of-structures
    for (i = 0; i < N; i++) {
        printf("Enter age          of friend %zu: ", i+1);
        scanf("%u", &myFriends[i].age);
        printf("Enter name         of friend %zu: ", i+1);
        scanf("%19s", myFriends[i].name);
        printf("Enter ticket price of friend %zu: ", i+1);
        scanf("%f", &myFriends[i].price);
    }



    // Print the total cost
   
    printDetails(myFriends);
}

// Part B: Function to print details of a single friend 
void printDetails(Friend allFriends[N]) {
    size_t i;  
    float totalCost = 0.0;
    printf("Age\tName\tPrice\n");
    for (i = 0; i < N; i++) {
        printf("%u\t%s\t%.2f\n", allFriends[i].age, allFriends[i].name, allFriends[i].price);
        totalCost += allFriends[i].price;
    }
     printf("Total cost for all friends is %.2f\n", totalCost);
}