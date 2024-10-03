#include <stdio.h>

int main(void)
{
   float mark, totalMark = 0, averageMark;
   unsigned int count = 0;

   printf("Enter Student Mark (-1 to quit): ");
   scanf("%f", &mark);

   while (mark != -1)
   {
       if (mark < 0 || mark > 100)
       {
           // Output "Invalid Mark, Please try again"
           puts("Invalid Mark, Please try again");
       }
       else if (mark >= 80)
       {
           // Output "Student Grade is A"
           puts("Student Grade is A");
           // Accumulate totalMark of all A-marks
           totalMark += mark;
           count++;
       }
       else if (mark >= 70 && mark <= 79)
       {
           // Output "Student Grade is B"
           puts("Student Grade is B");
           // Accumulate totalMark of all B-marks
           totalMark += mark;
           count++;
       }
       else if (mark >= 60 && mark <= 69)
       {
           // Output "Student Grade is C"
           puts("Student Grade is C");
           // Accumulate totalMark of all C-marks
           totalMark += mark;
           count++;
       }
       else if (mark >= 50 && mark <= 59)
       {
           // Output "Student Grade is D"
           puts("Student Grade is D");
           // Accumulate totalMark of all D-marks
           totalMark += mark;
           count++;
       }
       else
       {
           // Output "Student Grade is F"
           puts("Student Grade is F");
           // Accumulate totalMark of all F-marks
           totalMark += mark;
           count++;
       }

       // Prompt for next mark
       printf("Enter Student Mark (-1 to quit): ");
       scanf("%f", &mark); // This is the key part that updates the mark
   }

   // Test if students were processed or not
   if (count == 0)
   {
       // Output "No Student Processed"
       puts("No Student Processed");
   }
   else
   {
       // Compute averageMark
       averageMark = totalMark / count;

       // Determine average grade of class
       if (averageMark >= 80)
       {
           puts("Class Average Grade is A");
       }
       else if (averageMark >= 70 && averageMark < 80)
       {
           puts("Class Average Grade is B");
       }
       else if (averageMark >= 60 && averageMark < 70)
       {
           puts("Class Average Grade is C");
       }
       else if (averageMark >= 50 && averageMark < 60)
       {
           puts("Class Average Grade is D");
       }
       else
       {
           puts("Class Average Grade is F");
       }

       // Output average mark, total mark, and number of students
       printf("Average: %.2f\n", averageMark);
       printf("Total: %.2f\n", totalMark);
       printf("Count: %u\n", count);
   }

   return 0;
}
