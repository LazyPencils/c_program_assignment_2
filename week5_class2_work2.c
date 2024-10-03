#include <stdio.h>

// Structure definition for type friend with id, name
// Structure renaming / alias

typedef struct friend{
  int id;
  char name[20];
} Friend;

int main()
{
  // declare array of structures for 3 friends
  size_t i;  // Change i to size_t
  Friend myFriends[3];

  // read values into array-of-structures
  for (i = 0; i < 3; i++)
  {
    printf("Enter ID of friend %zu: ", i+1);  // Use %zu for size_t
    scanf("%d", &myFriends[i].id);
    printf("Enter name of friend %zu: ", i+1);  // Use %zu for size_t
    scanf("%19s", myFriends[i].name);
  }

  // print values from array-of-structures
  printf("Id\tName\n");
  for (i = 0; i < 3; i++)
  {
    printf("%d\t%s\n", myFriends[i].id, myFriends[i].name);
  }
  
  return 0;
}
