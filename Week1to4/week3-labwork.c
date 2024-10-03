//Joshua Moore
//Yi Hang Lin

#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

void get_matrix(float matrix1[][COL], float matrix2[][COL]);
void multiply_matrix(float matrix1[][COL], float matrix2[][COL], float resultMatrix[][COL]);
void print_matrix(float matrix1[][COL], float matrix2[][COL], float resultMatrix[][COL]);

int main() 
{
   float matrix1[ROW][COL] = {0.0}; // declaring & initializing arrays
   float matrix2[ROW][COL] = {0.0};
   float resultMatrix[ROW][COL] = {0.0};

   get_matrix(matrix1, matrix2); // function calls passing arrays as arguments
   multiply_matrix(matrix1, matrix2, resultMatrix); // arrays passed by address
   print_matrix(matrix1, matrix2, resultMatrix);

}

void get_matrix(float matrix1[][COL], float matrix2[][COL])
{
   unsigned int row, col;

   puts("Enter matrix1:");
   for(row = 0; row < ROW; row++) {
      for(col = 0; col < COL; col++) {
         scanf("%f", &matrix1[row][col]);  // Use %f to pass float
      }
   }

   puts("Enter matrix2:");
   for(row = 0; row < ROW; row++) {
      for(col = 0; col < COL; col++) {
         scanf("%f", &matrix2[row][col]);  // Use %f to pass float
      }
   }
}

void multiply_matrix(float matrix1[][COL], float matrix2[][COL], float resultMatrix[][COL])
{
   unsigned int row, col, k;
   for(row = 0; row < ROW; row++) {
      for(col = 0; col < COL; col++) {
         resultMatrix[row][col] = 0; 
         for(k = 0; k < COL; k++) {
            resultMatrix[row][col] += matrix1[row][k] * matrix2[k][col]; 
         }
      }
   }
}


void print_matrix(float matrix1[][COL], float matrix2[][COL], float resultMatrix[][COL])
{
   unsigned int row, col;

   puts("The multiplication of the matrices is:");
   
   // Printing matrix1
   for(row = 0; row < ROW; row++) {
      for(col = 0; col < COL; col++) {
         printf("%.1f ", matrix1[row][col]);  // Printing with one decimal point
      }
      if (row == 1) {
          printf("   *   ");  // Aligning the multiplication symbol for the second row
      } else {
          printf("       ");  // For the other rows, adding spaces
      }

      // Printing matrix2
      for(col = 0; col < COL; col++) {
         printf("%.1f ", matrix2[row][col]);
      }
      
      if (row == 1) {
          printf("   =   ");  // Aligning the equals symbol for the second row
      } else {
          printf("       ");  // For the other rows, adding spaces
      }

      // Printing resultMatrix
      for(col = 0; col < COL; col++) {
         printf("%.1f ", resultMatrix[row][col]);
      }
      
      puts("");  // Move to next line after each row
   }
}
