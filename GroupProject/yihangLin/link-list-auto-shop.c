//Activity 1: include the link-list header file
#include "link-list.h"


 int main() {
    ItemPtr startPtr = NULL;
    int choice;
    char *id, *name;
    float price;
	char input[100];
    
	
	menu();
    
	fgets(input, sizeof(input), stdin);
  
  	choice = strtol(input, NULL, 10);
    while (choice != 5) {
        switch (choice) {
            case 1:
            	printf("Enter a Part ID, Name, and Price \n");
                printf("Enter Part ID: ");
                id = validString();
                
                printf("Enter Name of Part: ");
                name = validString();
                
                printf("Enter Price: ");
                price = validNumericValue();
               
                startPtr = addItem(startPtr, id, name, price);
                printList(startPtr);
                break;
            case 2:
            	
            	if (startPtr == NULL) {
            		printf("The list is empty. Nothing to remove.\n");
				} else {
					printList(startPtr);
					printf("Enter Part ID to remove: ");
	                id = validString();
	                
	                
	                startPtr = removeItem(startPtr, id);
	                printList(startPtr);
				}
            	
                break;
            case 3:
                printf("Enter Part ID to view: ");
                id = validString();
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
        fgets(input, sizeof(input), stdin);
		choice = strtol(input, NULL, 10);
    }
} 