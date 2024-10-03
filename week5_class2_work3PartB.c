#include <stdio.h>
#define N 3

// Structure definition for Friend
typedef struct friend {
    unsigned int age;
    char name[20];
    float price;
} Friend;

// Function declaration
void printDetails(Friend any);

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
        totalCost += myFriends[i].price;
    }

    // Part B: Print details for each friend
    puts("Part B");
    printf("Age\tName\tPrice\n");
    for (i = 0; i < N; i++) {
        printDetails(myFriends[i]);  // Call the function to print each friend's details
    }

    // Print the total cost
    printf("Total cost for all friends is %.2f\n", totalCost);

    return 0;
}

// Part B: Function to print details of a single friend
void printDetails(Friend any) {
    printf("%u\t%s\t%.2f\n", any.age, any.name, any.price);
}
