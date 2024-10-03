#include <stdio.h>
#define N 3

int main( void )
{
   // declare and initialise matrices
   int matrix1[N][N] = {0};
   int matrix2[N][N] = {0};
   int resultMatrix[N][N] = {0};

   // read values into matrix-1
   unsigned int row, col;

   puts("read values into matrix - 1");
   for(row=0;row<N;row++){
      for(col=0;col<N; col++){
         printf("Row [%u] Col [%u]: ", row, col);
         scanf("%d", &matrix1[row][col]);  // Use & to pass the address
      }
   }       
   
   // read values into matrix-2
   puts("read values into matrix - 2");
   for(row=0;row<N;row++){
      for(col=0;col<N; col++){
         printf("Row [%u] Col [%u]: ", row, col);
         scanf("%d", &matrix2[row][col]);  // Use & to pass the address
      }
   }       
   
   // compute and load values into result matrix
   for(row=0;row<N;row++){
      for(col=0;col<N; col++){
         resultMatrix[row][col] = matrix1[row][col] * matrix2[row][col];
      }
   }    
   
   // output matrix-1
   puts("Matrix-1:");
   for(row=0;row<N;row++){
      for(col=0;col<N; col++){
         printf("%d ", matrix1[row][col]);
      }
      puts("");  // move to next line after each row
   }    

   // output matrix-2
   puts("Matrix-2:");
   for(row=0;row<N;row++){
      for(col=0;col<N; col++){
         printf("%d ", matrix2[row][col]);
      }
      puts("");  // move to next line after each row
   }    
   
   // output result matrix
   puts("Result Matrix:");
   for(row=0;row<N;row++){
      for(col=0;col<N; col++){
         printf("%d ", resultMatrix[row][col]);
      }
      puts("");  // move to next line after each row
   }    

   return 0;
}
