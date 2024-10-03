#include <stdio.h>
// structure definition with student id, name, gender, height 
struct customer{
    char lastName[15];
    char firstName[15];
    int customerNumber

    struct{
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipcode[5];
    } personal;
} customerRecord, *customerPtr;

customerPtr = &customerRecord;

// typedef struct student Student;
// typedef union student2 Student2;

// rename the structure for convenient usage

int main ()
{
   
}



