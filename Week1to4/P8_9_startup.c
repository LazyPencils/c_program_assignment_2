// Exercise 8.9 Solution
#include <stdio.h>
#include <string.h>


//defining the structure / record
typedef struct student{
   int id;
   char name[20];
   char gender;
   float height;
} Student;

//Renaming the structure for convenience
// typedef struct student Student;


printf("%ld", sizeof(Student));
printf("%ld", sizeof(struct student));
malloc(sizeof(Student));

//Created varaibles of type student
struct student x;
Student y;

struct student t;

x = {991700947,"Joshua",'m', 5.10}
Student *xPtr = &x;

(*).    ===     ->

//Accessing members of the structure using
// 1) structure member operator  .  //also called the dot operator
// 2) Structure pointer operator -> //also called the arrow operator

//Directly
printf("%d", x.id);
printf("%s", x.name);
printf("%c", x.gender);
printf("%f", x.height);

//Indirectly using old standard
printf("%d", (*xPtr).id);
printf("%c", (*xPtr).gender);
printf("%s", (*xPtr).name);
printf("%f", (*xPtr).height);

//Indirectly using new standard
printf("%d", xPtr->id);
printf("%c", xPtr->gender);
printf("%s", xPtr->name);
printf("%f", xPtr->height);

//Using the dot operator

t.id = 991700948;
scanf("%d", &t.id);

t.name = "John";
strcpy(t.name, "john");
scanf("%19s", t.name);
t.gender = 'f';
tgender = getchar();
t.height = 5.7;
scanf("%f", &t.height);

int main( void )
{ 
   char string1[ 20 ]; // first string input by user
   char string2[ 20 ]; // second string input by user
   char *string1Ptr = "NULL";
   char *string2Ptr = "NULL";
   int result; // result of comparing two strings

   printf( "%s", "Enter First string: " );
   fgets( string1, 20, stdin );

   printf( "%s", "Enter Second string: " );
   fgets( string2, 20, stdin );
   
   result = strcmp(string1, string2); // use strcmp() to decide the if the strings are equal 
  
   string1Ptr = strtok(string1, "\n");
   string2Ptr = strtok(string2, "\n");

   // display appropriate message for result
   printf("String-1 %ld\nString-2 %ld\n", strlen(string1Ptr), strlen(string2Ptr));
   if ( result > 0 ) {
      printf( "\"%s\" is greater than \"%s\"\n", string1Ptr, string2Ptr );
   } // end if
   else if ( 0 == result ) {
      printf( "\"%s\" is equal to \"%s\"\n", string1Ptr, string2Ptr );
   } // end else if
   else {
      printf( "\"%s\" is less than \"%s\"\n", string1Ptr, string2Ptr );
   } // end else
} // end main




 
