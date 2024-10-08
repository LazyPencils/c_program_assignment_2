// Header file containing link-list definitions & implementation methods
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definition should have at least 3 different types/pieces
struct item{
   int itemId; // In real world, itemIds are alphanumeric, for simplicity the assignment tests you for int
   char itemName[20];
   float itemPrice;
   struct item *nextPtr;
};

// Structure renaming
typedef struct item Item;
typedef struct item *ItemPtr;

/*Function Prototypes*/
ItemPtr makeItem(int id, char name[20], float price);
ItemPtr addItem(ItemPtr sPtr, int id, char name[20], float price);
void printList(ItemPtr sPtr);
//ItemPtr removeItem(ItemPtr sPtr, int id, char name[20], float price);
//void viewItem(ItemPtr sPtr, int id, char name[20], float price);
void menu ();
 
ItemPtr makeItem(int id, char name[20], float price)
{
  ItemPtr newPtr = malloc(sizeof(Item));
  if(newPtr == NULL)
  {
     puts("Memory Issues... Item Not Created");
  }
  else{
     newPtr->itemId = id;
     strcpy(newPtr->itemName, name);
     newPtr->itemPrice = price;
     newPtr->nextPtr = NULL;
  }
  return newPtr;
}


// Add handling, if item id fully matches any in linked list, print "Duplicate itemID" and return sptr
ItemPtr addItem(ItemPtr sPtr, int id, char name[20], float price)
{
  ItemPtr previousPtr, currentPtr, newPtr;
  previousPtr = NULL;
  currentPtr = sPtr;
  newPtr = makeItem(id, name, price);
  
  while (currentPtr != NULL && id > currentPtr->itemId)
  {
     previousPtr = currentPtr;
     currentPtr = currentPtr->nextPtr;
  }
  
  // exit traversal
  if(previousPtr == NULL)
  {
    newPtr->nextPtr = sPtr;
    sPtr = newPtr;
  }
  else{
    previousPtr->nextPtr = newPtr;
    newPtr->nextPtr = currentPtr;
  }
  return sPtr;
}

void printList(ItemPtr sPtr)
{
  ItemPtr tempPtr = sPtr;
  if(tempPtr == NULL)
  {
     puts("List is Empty... Nothing to Print");
     return;
  }
  else{
     puts("The Items in the List are");
     while(tempPtr != NULL)
     {
       printf("%d %s %f\n->", tempPtr->itemId, tempPtr->itemName, tempPtr->itemPrice);
       tempPtr = tempPtr->nextPtr;
     }
  
  }
}

void menu () 
{
  printf ("\t1: Insert Item into Ordered List\n");
  printf ("\t2: Remove Item from List\n");
  printf ("\t3: View Item from List\n");
  printf ("\t4: Printing the List\n");
  printf ("\t5: Exit\n");
  printf ("\tEnter Choice: ");
}


// Add Print list method so user can see items to remove
ItemPtr removeItem(ItemPtr sPtr, int id)
{
  ItemPtr previousPtr, currentPtr, tempPtr;
  previousPtr = NULL;
  currentPtr = sPtr;
  // revisit here
  if (sPtr == NULL) { 
     puts("List is Empty... Nothing to Delete");
     return sPtr;
  }
  while (currentPtr != NULL && id != currentPtr->itemId){
     previousPtr = currentPtr;
     currentPtr = currentPtr->nextPtr;
  } // exit traversal
  if(currentPtr == NULL){ // check if node is not in the list
     printf("%d is [not] found in the list\n", id);
  }
  else if(previousPtr == NULL){ // node found at the front list
    tempPtr = sPtr;
    printf("Node %d is being deleted...\n", tempPtr->itemId); // inform user
    sPtr = sPtr->nextPtr;
    free(tempPtr);
  }
  else{ // node found elsewhere in the list
    tempPtr = currentPtr;
    printf("Node %d is being deleted...\n", tempPtr->itemId); // inform user
    previousPtr->nextPtr = currentPtr->nextPtr;
    free(tempPtr);
  }
  return sPtr;
} 

/*

void viewItem(ItemPtr sPtr, int id, char name[20], float price)
{
  ItemPtr currentPtr = sPtr;
  int position = 0;
  if (sPtr == NULL) { 
     puts("List is Empty... Nothing to View");
     return;
  }
  while (currentPtr != NULL && value != currentPtr->data){
     currentPtr = currentPtr->nextPtr;
     position++;
  } // exit traversal
  if(currentPtr == NULL){ // check if node is not in the list
     printf("%d is [not] found in the list\n", value);
  }
  else { 
     printf("Node %d was found at position %d...\n", currentPtr->data, position+1);
  }
}
*/
 

