#include <stdio.h>
int main()
{
   int inum = 8;
   float fnum = 67.7;
   void *ptr;
   ptr = &inum;
   printf("\nThe value of inum = %d", *((int *)ptr)); 
   ptr = &fnum;
   printf("\nThe value of fnum = %f", *((float *)ptr));
   puts(""); 
}
