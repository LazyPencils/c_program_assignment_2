#include <stdio.h>
// structure definition with student id, name, gender, height 
struct student{
   int id;
   char name[8];
   char gender;
   float height;
};

union student2 {
   int id;
   char name[8];
   char gender;
   float height;
};

typedef struct student Student;
typedef union student2 Student2;

// rename the structure for convenient usage

int main ()
{
   /* Structure declaration & Initialisation */

   Student x = {123, "Jim", 'm', 5.7}; 
   Student2 w = {444}
   // Student y;
   // Student *xPtr = &x;
   // int i;

   
   /* Determining the size of the structure type "Student"*/
   printf("The Size of the Student Type is %ld\n", sizeof(Student));
   printf("The Size of the Student2 Type is %ld\n", sizeof(Student2));

   /* Structure usage with the dot-operator*/
   //printf("The Id is : %d \n", x.id); 
   //printf("The Name is : %s \n", x.name);
   //printf("The Gender is : %c \n",x.gender);
   //printf("The Height is : %f \n",x.height);
   
   /* Structure usage with the pointer operator old standard*/
   // puts("Old pointer standard");
   // printf("The Id is : %d \n", (*xPtr).id); 
   // printf("The Name is : %s \n", (*xPtr).name);
   // printf("The Gender is : %c \n",(*xPtr).gender);
   // printf("The Height is : %f \n",(*xPtr).height);

   /* Structure usage with the pointer arrow-operator new standard*/
   // puts("New pointer standard... always use this");
   // printf("The Id is : %d \n", xPtr->id); 
   // printf("The Name is : %s \n", xPtr->name);
   // printf("The Gender is : %c \n",xPtr->gender);
   // printf("The Height is : %f \n",xPtr->height);

   
   /* Read new info into Student Y and Print the information*/  
   // printf("Enter ID ");
   // scanf("%d", &y.id);

   // printf("Enter Name ");
   // scanf("%s", y.name);

   // printf("Enter Gender ");
   // scanf(" %c", &y.gender); // note the space before %c; try using getchar()

   // printf("Enter Height ");
   // scanf("%f", &y.height);

   // printf("ID for Student Y is %d \n", y.id);
   // printf("Name for Student Y is %s \n ", y.name);
   // printf("Gender for Student Y is %c \n", y.gender);
   // printf("Height for Student Y is %f \n", y.height);
}



