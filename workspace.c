//Implementing a link list data stucture
typedef struct item {
    int data;
    struct item* nextPtr;
} Item;

typedef Item* ItemPtr;

ItemPtr makeItem(int value);
ItemPtr addItem(ItemPtr sPtr, int value);
void printList(ItemPtr sPtr);

/*****Function Definitions */

ItemPtr makeItem(int value) {
    ItemPtr newPtr = malloc(sizeof(Item));
    if (newPtr == NULL) {
        puts("Memory Issues... Item not created");
    }
    else {
        newPtr->data = value;
        newPtr->nextPtr = NULL;
    }
    return newPtr;
}

ItemPtr addItem(ItemPtr sPtr, int value) {
    ItemPtr newPtr, previousPtr, currentPtr;
    previousPtr = NULL;
    currentPtr = sPtr;
    newPtr = makeItem(value);

    while (currentPtr != NULL && value > currentPtr->data) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    if (previousPtr == NULL) {//inserting at the start-of-list
        newPtr->nextPtr = sPtr;
        sPtr = newPtr;
    }
    else {//inserting elsewhere in the list 
        previous->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }

    return sPtr;
}

void printList(ItemPtr sPtr){
    ItemPtr tempPtr = sPtr;
    if(tempPtr == NULL){
        puts("List is empty... Nothing to print");
    }else{
        puts("The Items in the list are");
        while(tempPtr != NULL){
            printf("%d->",tempPtr->data);
            tempPtr = tempPtr->nextPtr;
        }
        puts("");
    }


}


