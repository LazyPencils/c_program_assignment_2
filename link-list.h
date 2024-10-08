#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definition for Parts in an Auto Shop
struct part {
    int partId;              // Numeric ID
    char partName[20];       // String name
    char partCategory;       // Character field for category (e.g., A, B, C)
    float partPrice;         // Numeric price
    struct part *nextPtr;    // Pointer to next part
};

// Structure renaming
typedef struct part Part;
typedef struct part *PartPtr;

/* Function Prototypes */
PartPtr makePart(int id, char name[20], char category, float price);
PartPtr addPart(PartPtr sPtr, int id, char name[20], char category, float price);
PartPtr removePart(PartPtr sPtr, int id);
void viewPart(PartPtr sPtr, int id);
void printList(PartPtr sPtr);
void menu();
int validateInput(char *input, int *id, char *category, char *name, float *price);

/******* Function Definitions ******/

// Create a part and return pointer to it
PartPtr makePart(int id, char name[20], char category, float price) {
    PartPtr newPtr = (PartPtr)malloc(sizeof(Part));
    if (newPtr == NULL) {
        puts("Memory allocation failed... Part not created.");
    } else {
        newPtr->partId = id;
        strcpy(newPtr->partName, name);
        newPtr->partCategory = category;
        newPtr->partPrice = price;
        newPtr->nextPtr = NULL;
    }
    return newPtr;
}

// Add part to list and figure out its new position within the list
PartPtr addPart(PartPtr sPtr, int id, char name[20], char category, float price) {
    PartPtr newPtr, previousPtr, currentPtr;
    previousPtr = NULL;
    currentPtr = sPtr;
    newPtr = makePart(id, name, category, price);

    while (currentPtr != NULL && id > currentPtr->partId) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    if (previousPtr == NULL) { // Inserting at the start of the list
        newPtr->nextPtr = sPtr;
        sPtr = newPtr;
    } else { // Inserting elsewhere in the list
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }

    return sPtr;
}

// Remove a part from the list
PartPtr removePart(PartPtr sPtr, int id) {
    PartPtr previousPtr, currentPtr;

    // If the list is empty
    if (sPtr == NULL) {
        printf("List is empty, nothing to delete.\n");
        return sPtr;
    }

    // If the part to be deleted is the first part
    if (id == sPtr->partId) {
        sPtr = sPtr->nextPtr;
        printf("Part with ID %d deleted.\n", id);
        return sPtr;
    }

    previousPtr = sPtr;
    currentPtr = sPtr->nextPtr;

    // Traverse the list to find the part
    while (currentPtr != NULL && currentPtr->partId != id) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    // If the part is found
    if (currentPtr != NULL) {
        previousPtr->nextPtr = currentPtr->nextPtr;
        printf("Part with ID %d deleted successfully.\n", id);
    } else {
        printf("Part with ID %d not found.\n", id);
    }

    return sPtr;
}

// View a specific part from the list
void viewPart(PartPtr sPtr, int id) {
    while (sPtr != NULL && sPtr->partId != id) {
        sPtr = sPtr->nextPtr;
    }

    if (sPtr == NULL) {
        printf("Part with ID %d not found.\n", id);
    } else {
        printf("Part found: ID: %d, Name: %s, Category: %c, Price: %.2f\n", sPtr->partId, sPtr->partName, sPtr->partCategory, sPtr->partPrice);
    }
}

// Print the entire list of parts
void printList(PartPtr sPtr) {
    PartPtr tempPtr = sPtr; // Use temp pointer to avoid modifying sPtr

    if (tempPtr == NULL) { // If list is empty
        puts("List is empty! Nothing to print.");
    } else {
        puts("The parts in the list are:");
        while (tempPtr != NULL) {
            printf("ID: %d, Name: %s, Category: %c, Price: %.2f\n", tempPtr->partId, tempPtr->partName, tempPtr->partCategory, tempPtr->partPrice);
            tempPtr = tempPtr->nextPtr;
        }
        puts("");
    }
}

// Menu function
void menu() {
    printf("\t1: Insert Part into Ordered List\n");
    printf("\t2: Remove Part from List\n");
    printf("\t3: View Part from List\n");
    printf("\t4: Print the List\n");
    printf("\t5: Exit\n");
    printf("\tEnter Choice: ");
}

// Validate input for insertion
int validateInput(char *input, int *id, char *category, char *name, float *price) {
    char priceStr[20];

    printf("Enter Part ID (numeric): ");
    fgets(input, 20, stdin);
    *id = (int)strtol(input, NULL, 10);

    printf("Enter Category (single character): ");
    fgets(input, 5, stdin);
    *category = input[0];

    printf("Enter Part Name (up to 20 chars): ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove trailing newline

    printf("Enter Part Price: ");
    fgets(priceStr, 20, stdin);
    *price = strtof(priceStr, NULL);

    return 1;
}

int main() {
    PartPtr startPtr = NULL; // Initializing the start of the list
    char input[20], name[20];
    int choice, id;
    char category;
    float price;

    menu();
    fgets(input, 5, stdin);
    choice = (int)strtol(input, NULL, 10);  // Safe input conversion

    while (choice != 5) {
        switch (choice) {
            case 1: // Insert Part
                if (validateInput(input, &id, &category, name, &price)) {
                    startPtr = addPart(startPtr, id, name, category, price);
                    printList(startPtr);
                }
                break;

            case 2: // Remove Part
                printf("\nEnter Part ID for deletion: ");
                fgets(input, 20, stdin);
                id = (int)strtol(input, NULL, 10);
                startPtr = removePart(startPtr, id);
                printList(startPtr);
                break;

            case 3: // View Part
                printf("\nEnter Part ID to View: ");
                fgets(input, 20, stdin);
                id = (int)strtol(input, NULL, 10);
                viewPart(startPtr, id);
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

}
