#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definition
struct item {
    int itemId;              // Numeric ID
    char itemName[20];       // String name
    char itemCategory;       // Character field for category (e.g., A, B, C)
    float itemPrice;         // Numeric price
    struct item *nextPtr;    // Pointer to next item
};

// Structure renaming
typedef struct item Item;
typedef struct item *ItemPtr;

/* Function Prototypes */
ItemPtr makeItem(int id, char name[20], char category, float price);
ItemPtr addItem(ItemPtr sPtr, int id, char name[20], char category, float price);
ItemPtr removeItem(ItemPtr sPtr, int id);
void viewItem(ItemPtr sPtr, int id);
void printList(ItemPtr sPtr);
void menu();

/******* Function Definitions ******/

// Create an item and return pointer to it
ItemPtr makeItem(int id, char name[20], char category, float price) {
    ItemPtr newPtr = (ItemPtr)malloc(sizeof(Item));
    if (newPtr == NULL) {
        puts("Memory Issues... Item not created");
    } else {
        newPtr->itemId = id;
        strcpy(newPtr->itemName, name);
        newPtr->itemCategory = category;
        newPtr->itemPrice = price;
        newPtr->nextPtr = NULL;
    }
    return newPtr;
}

// Add item to list and figure out its new position within the list
ItemPtr addItem(ItemPtr sPtr, int id, char name[20], char category, float price) {
    ItemPtr newPtr, previousPtr, currentPtr;
    previousPtr = NULL;
    currentPtr = sPtr;
    newPtr = makeItem(id, name, category, price);

    while (currentPtr != NULL && id > currentPtr->itemId) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    if (previousPtr == NULL) { // Inserting at the start-of-list
        newPtr->nextPtr = sPtr;
        sPtr = newPtr;
    } else { // Inserting elsewhere in the list
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }

    return sPtr;
}

// Remove an item from the list
ItemPtr removeItem(ItemPtr sPtr, int id) {
    ItemPtr previousPtr, currentPtr;

    // If the list is empty
    if (sPtr == NULL) {
        printf("List is empty, nothing to delete.\n");
        return sPtr;
    }

    // If the item to be deleted is the first item
    if (id == sPtr->itemId) {
        sPtr = sPtr->nextPtr;
        return sPtr;
    }

    previousPtr = sPtr;
    currentPtr = sPtr->nextPtr;

    // Traverse the list to find the item
    while (currentPtr != NULL && currentPtr->itemId != id) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    // If the item is found
    if (currentPtr != NULL) {
        previousPtr->nextPtr = currentPtr->nextPtr;
        printf("Item deleted successfully.\n");
    } else {
        printf("Item with ID %d not found.\n", id);
    }

    return sPtr;
}


// View a specific item from the list
void viewItem(ItemPtr sPtr, int id) {
    while (sPtr != NULL && sPtr->itemId != id) {
        sPtr = sPtr->nextPtr;
    }

    if (sPtr == NULL) {
        printf("Item with ID %d not found.\n", id);
    } else {
        printf("Item found: %d %s %c %.2f\n", sPtr->itemId, sPtr->itemName, sPtr->itemCategory, sPtr->itemPrice);
    }
}

// Print the entire list
void printList(ItemPtr sPtr) {
    ItemPtr tempPtr = sPtr; // Use temp pointer to avoid modifying sPtr

    if (tempPtr == NULL) { // If list is empty
        puts("List is empty! Nothing to print.");
    } else {
        puts("The items in the list are:");
        while (tempPtr != NULL) {
            printf("%d %s %c %.2f\n", tempPtr->itemId, tempPtr->itemName, tempPtr->itemCategory, tempPtr->itemPrice);
            tempPtr = tempPtr->nextPtr;
        }
        puts("");
    }
}

// Menu function
void menu() {
    printf("\t1: Insert Item into Ordered List\n");
    printf("\t2: Remove Item from List\n");
    printf("\t3: View Item from List\n");
    printf("\t4: Print the List\n");
    printf("\t5: Exit\n");
    printf("\tEnter Choice: ");
}

int main() {
    ItemPtr startPtr = NULL; // Initializing the start of the list
    char input[20], name[20];
    int choice, id;
    char category;
    float price;

    menu();
    fgets(input, 5, stdin);
    choice = (int)strtol(input, NULL, 10);  // Safe input conversion

    while (choice != 5) {
        switch (choice) {
            case 1: // Insert Item
                printf("\nEnter Value for Item for Insertion (id category name price): ");
                fgets(input, 20, stdin);  // Get id
                id = (int)strtol(input, NULL, 10);

                fgets(input, 5, stdin);  // Get category (single character)
                category = input[0];

                fgets(name, 20, stdin);  // Get name

                fgets(input, 20, stdin);  // Get price
                price = strtof(input, NULL);

                startPtr = addItem(startPtr, id, name, category, price);
                printList(startPtr);
                break;

            case 2: // Remove Item
                printf("\nEnter Item ID for deletion: ");
                fgets(input, 20, stdin);
                id = (int)strtol(input, NULL, 10);
                startPtr = removeItem(startPtr, id);
                printList(startPtr);
                break;

            case 3: // View Item
                printf("\nEnter Item ID to View: ");
                fgets(input, 20, stdin);
                id = (int)strtol(input, NULL, 10);
                viewItem(startPtr, id);
                break;

            case 4: // Print the List
                printList(startPtr);
                break;

            default:
                printf("Invalid Option... Please Try Again\n");
                break;
        }

        menu();
        fgets(input, 5, stdin);
        choice = (int)strtol(input, NULL, 10);  // Safe input conversion
    }

    return 0;
}
