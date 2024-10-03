#include <stdio.h>
#define N 3

typedef struct address {
    unsigned int streetNumber;
    char streetName[20];
    char city[20];
    char postalCode[20];
} Address;

typedef struct friend {
    unsigned int age;
    char name[20];
    float price;
    Address friendAddress;  
} Friend;


void printDetails(Friend allFriends[N]);

int main() {
    size_t i;  
    Friend myFriends[N];
    float totalCost = 0.0;

    for (i = 0; i < N; i++) {
        printf("Enter age          of friend %zu: ", i+1);
        scanf("%u", &myFriends[i].age);
        printf("Enter name         of friend %zu: ", i+1);
        scanf("%19s", myFriends[i].name);
        printf("Enter ticket price of friend %zu: ", i+1);
        scanf("%f", &myFriends[i].price);

        printf("Enter street number of friend %zu: ", i+1);
        scanf("%u", &myFriends[i].friendAddress.streetNumber);
        printf("Enter street name of friend %zu: ", i+1);
        scanf("%19s", myFriends[i].friendAddress.streetName);
        printf("Enter city of friend %zu: ", i+1);
        scanf("%19s", myFriends[i].friendAddress.city);
        printf("Enter postal code of friend %zu: ", i+1);
        scanf("%19s", myFriends[i].friendAddress.postalCode);
    }

    // Print the details of all friends, including total cost
    printDetails(myFriends);

    return 0;
}

void printDetails(Friend allFriends[N]) {
    size_t i;  
    float totalCost = 0.0;

    printf("Age\tName\t\tPrice\tStreet Number\tStreet Name\tCity\t\tPostal Code\n");
    
    for (i = 0; i < N; i++) {
        printf("%u\t%-10s\t%.2f\t%u\t\t%-15s\t%-10s\t%-10s\n", 
                allFriends[i].age, 
                allFriends[i].name, 
                allFriends[i].price, 
                allFriends[i].friendAddress.streetNumber, 
                allFriends[i].friendAddress.streetName, 
                allFriends[i].friendAddress.city, 
                allFriends[i].friendAddress.postalCode);
        totalCost += allFriends[i].price;
    }

    printf("\nTotal cost for all friends is: %.2f\n", totalCost);
}
