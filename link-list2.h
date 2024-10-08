// Header file containing link-list definitions & implementation methods
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definition should have at least 3 different types/pieces
struct item {
  int itemId;
  char itemName[20];
  float itemPrice;
  struct item *nextPtr;
};

// Structure renaming
typedef struct item Item;
typedef struct item *ItemPtr;

/*Function Prototypes*/

ItemPtr makeItem(int id,char name[20],float price);
ItemPtr addItem(ItemPtr sPtr, int id,char name[20],float price);
void printList(ItemPtr sPtr);
ItemPtr removeItem (ItemPtr sPtr, int id);
void viewItem (ItemPtr sPtr, int id);
void menu ();
 
/*******Function Definitions******/
ItemPtr makeItem(int id,char name[20],float price)
{
    ItemPtr newPtr = (ItemPtr)malloc(sizeof(Item));
    if(newPtr == NULL)
    {
      puts("Memory Issues... Item not created");
    }else{
      newPtr->itemId = id;
      strcpy(newPtr->itemName, name);
      newPtr->itemPrice = price;
      newPtr->nextPtr = NULL;
    }
    return newPtr;
}

ItemPtr addItem(ItemPtr sPtr, int id,char name[20],float price)
{
  ItemPtr newPtr, previousPtr, currentPtr;
  previousPtr = NULL;
  currentPtr = sPtr;
  newPtr = makeItem(id,name,price);
  while(currentPtr != NULL && id > currentPtr->itemId){
    previousPtr = currentPtr;
    currentPtr = currentPtr->nextPtr;
  }  
  if(previousPtr == NULL){// inserting at the start-of-list
    newPtr->nextPtr = sPtr;
    sPtr = newPtr;  
  }
  else{  // inserting elsewhere in the list
    previousPtr->nextPtr = newPtr;
    newPtr->nextPtr = currentPtr;
  }
  return sPtr;
}

void printList(ItemPtr sPtr)
{
  ItemPtr tempPtr = sPtr;
  if(tempPtr == NULL){
    puts("List is empty... Nothing to print");
  }else{
    puts("The Items in the list are: ");
    
    while(tempPtr != NULL){
      printf("%d %s %f\n", tempPtr->itemId, tempPtr->itemName, tempPtr->itemPrice);
      tempPtr = tempPtr->nextPtr;
    }
    puts("");
  }
}

ItemPtr removeItem (ItemPtr sPtr, int id)
{
   ItemPtr previousPtr = NULL, currentPtr = sPtr, tempPtr = NULL;
   if(sPtr == NULL){
      puts("List is empty... nothing to delete");
      return NULL;
   }
   while(currentPtr != NULL && id != currentPtr->itemId){
     previousPtr = currentPtr;
     currentPtr = currentPtr->nextPtr;
   }
   if(currentPtr == NULL){ 	// value was not found
     printf("ID %d was not found in the list\n", id);
   }else if(previousPtr == NULL){ // value to be deleted is at the front of the list
     tempPtr = sPtr;
     printf("%d %s %f deleted...\n", tempPtr->itemId, tempPtr->itemName, tempPtr->itemPrice);
     sPtr = sPtr->nextPtr;
     free(tempPtr);
   }else{	// value to be deleted is elsewhere in the list
     tempPtr = currentPtr;
     printf("%d %s %f deleted...\n", tempPtr->itemId, tempPtr->itemName, tempPtr->itemPrice);
     previousPtr->nextPtr = currentPtr->nextPtr;
     free(tempPtr);
   }
   return sPtr;
}


void viewItem (ItemPtr sPtr, int id){
   ItemPtr currentPtr = sPtr;
   int position = 0;
   if(sPtr == NULL){
      puts("List is empty... nothing to view");
      return;
   }
   while(currentPtr != NULL && id != currentPtr->itemId){
     currentPtr = currentPtr->nextPtr;
     position++;
   }
   if(currentPtr == NULL){ 	// value was not found
     printf("ID %d was not found in the list\n", id);
   }else{ // value was found
     printf("%d %s %f found at location %d\n", currentPtr->itemId, currentPtr->itemName, currentPtr->itemPrice, position+1);
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
 

