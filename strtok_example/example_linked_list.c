//Activity 1: include the link-list header file
#include "link-list1.h"
 
int main () 
{
  //Activity 2: creating list pointer
  ItemPtr startPtr;
  startPtr = NULL;
 
  int id;
  char name[20];
  float price;
  //Activity 3: initialising the start of the list 
  startPtr = NULL;
  
  
  
  menu ();
  
	char input[100];
	int choice;
  
  fgets(input, sizeof(input), stdin);
  
  choice = strtol(input, NULL, 10);
  
  while (choice != 5)
  {
    switch (choice) //Activity 4: Test your link list tasks
    {
       case 1: 	printf ("\nEnter Values for Item for Insertion: ItemID Name Price \n");
            	fgets(input, sizeof(input), stdin);
            	
            	char *token = strtok(input, " "); 
            	id = strtol(token, NULL, 10);
            	
            	token = strtok(NULL, " ");
            	strncpy(name, token, 19);
            	
            	token = strtok(NULL, " ");
            	price = strtof(token, NULL);
            	
	       		startPtr = addItem (startPtr, id, name, price);
	       		printList (startPtr);
	       		printf ("\n");
	       		break;
       case 2: printf ("\nEnter Item ID for deletion : ");
	       fgets(input, sizeof(input), stdin);
		   
		   id = strtol(input, NULL, 10);
		   
	       startPtr = removeItem (startPtr, id);
	       printList (startPtr);
	       printf ("\n");
               break;
       case 3: //printf ("\nEnter Item Number to View : ");
	       //scanf ("%d", &value);
	       //viewItem (startPtr, value);
	       //printf ("\n");
	       break;
       case 4: printList (startPtr);
	       printf ("\n");
	       break;
       default:
	       printf ("Invalid Option... Please Try Again \n");
	       break;
    }
      
    menu ();
    fgets(input, sizeof(input), stdin);
  
  	choice = strtol(input, NULL, 10);
  }
  
}// end of main


