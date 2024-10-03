#include "link-list.h"
int main () 
{
  ItemPtr startPtr; //Activity 2: creating list pointer
  startPtr = NULL; //Activity 3: initialising the start of the list   
  int choice;
  int id;
  char name[20];
  float price;
  
  menu();
  scanf("%d", &choice);
  
  while (choice != 5)
  {
    switch (choice) //Activity 4: Test your link list tasks
    {
      case 1: 
        printf("\nEnter Value for Item for Insertion (id name price): ");
        scanf("%d %19s %f", &id, name, &price);
        startPtr = addItem(startPtr, id, name, price);
        printList(startPtr);
        printf("\n");
        break;

      case 2: 
        printf("\nEnter Item ID for deletion: ");
        // scanf("%d", &value); // You'll need to implement removeItem logic here
        // startPtr = removeItem(startPtr, value);
        // printList(startPtr);
        printf("\n");
        break;

      case 3: 
        printf("\nEnter Item ID to View: ");
        // scanf("%d", &value); // You'll need to implement viewItem logic here
        // viewItem(startPtr, value);
        printf("\n");
        break;

      case 4: 
        printList(startPtr);
        printf("\n");
        break;

      default:
        printf("Invalid Option... Please Try Again\n");
        break;
    }

    menu();
    scanf("%d", &choice);
  }
  
  return 0;
}
