#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

//Function prototypes
void get_matrix(int matrix1[][COL], int matrix2[][COL]);
void sum_matrix(int matrix1[][COL], int matrix2[][COL], int resultMatrix[][COL]);
void print_matrix(int matrix1[][COL], int matrix2[][COL], int resultMatrix[][COL]);

int main() 
{
   int matrix1[ROW][COL] = {{0}, {0}, {0}}; // declaring & initialising arrays
   int matrix2[ROW][COL] = {{0}, {0}, {0}};
   int resultMatrix[ROW][COL] = {{0}, {0}, {0}};

   get_matrix(matrix1, matrix2); // function calls passing arrays as arguments
   sum_matrix(matrix1, matrix2, resultMatrix); // arrays passed by address
   print_matrix(matrix1, matrix2, resultMatrix);

   return 0; // good practice to return 0 in main
}

/**********Function Definitions*************/

void get_matrix(int matrix1[][COL], int matrix2[][COL])
{
   unsigned int row, col;

   puts("read values into matrix - 1");
   for(row = 0; row < ROW; row++) {
      for(col = 0; col < COL; col++) {
         printf("Row [%u] Col [%u]: ", row, col);
         scanf("%d", &matrix1[row][col]);  // Use & to pass the address
      }
   }

   // read values into matrix-2
   puts("read values into matrix - 2");
   for(row = 0; row < ROW; row++) {
      for(col = 0; col < COL; col++) {
         printf("Row [%u] Col [%u]: ", row, col);
         scanf("%d", &matrix2[row][col]);  // Use & to pass the address
      }
   }
}

void sum_matrix(int matrix1[][COL], int matrix2[][COL], int resultMatrix[][COL])
{
   unsigned int row, col;
   for(row = 0; row < ROW; row++) {
      for(col = 0; col < COL; col++) {
         resultMatrix[row][col] = matrix1[row][col] + matrix2[row][col];
      }
   }
}

void print_matrix(int matrix1[][COL], int matrix2[][COL], int resultMatrix[][COL])
{
   unsigned int row, col; // Declare row and col here

   puts("Matrix-1:");
   for(row = 0; row < ROW; row++) {
      for(col = 0; col < COL; col++) {
         printf("%d ", matrix1[row][col]);
      }
      puts("");  // move to next line after each row
   }

   // output matrix-2
   puts("Matrix-2:");
   for(row = 0; row < ROW; row++) {
      for(col = 0; col < COL; col++) {
         printf("%d ", matrix2[row][col]);
      }
      puts("");  // move to next line after each row
   }

   // output resultMatrix
   puts("Result Matrix:");
   for(row = 0; row < ROW; row++) {
      for(col = 0; col < COL; col++) {
         printf("%d ", resultMatrix[row][col]);
      }
      puts("");  // move to next line after each row
   }
}
