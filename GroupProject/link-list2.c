//Activity 1: include the link-list header file
#include "link-list2.h"
 int main() {
    ItemPtr startPtr = NULL;
    int choice;
    char id[10], name[20];
    float price;

    menu();
    scanf("%d", &choice);
    clearInputBuffer();

    while (choice != 5) {
        switch (choice) {
            case 1:
                printf("Enter Part ID, Name, and Price: ");
                fgets(id, 10, stdin);  // Read ID
                id[strcspn(id, "\n")] = '\0';  // Remove newline
                fgets(name, 20, stdin);  // Read Name
                name[strcspn(name, "\n")] = '\0';  // Remove newline
                scanf("%f", &price);  // Read Price
                clearInputBuffer();  // Clear the buffer
                startPtr = addItem(startPtr, id, name, price);
                printList(startPtr);
                break;
            case 2:
                printf("Enter Part ID to remove: ");
                fgets(id, 10, stdin);
                id[strcspn(id, "\n")] = '\0';
                startPtr = removeItem(startPtr, id);
                printList(startPtr);
                break;
            case 3:
                printf("Enter Part ID to view: ");
                fgets(id, 10, stdin);
                id[strcspn(id, "\n")] = '\0';
                viewItem(startPtr, id);
                break;
            case 4:
                printList(startPtr);
                break;
            default:
                printf("Invalid Option... Please Try Again\n");
                break;
        }
        menu();
        scanf("%d", &choice);
        clearInputBuffer();
    }
}