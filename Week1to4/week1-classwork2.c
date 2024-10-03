//Program to compute the diameter, area, circumference of a circle

#include <stdio.h>
// #define PI 3.14159

int main (void)
{
   /* define data container to store floating point value radius*/
   float radius = 0.0;

   /* define read-only data container (constant) value PI with 3.14159 */
    const float PI = 3.14159;

   /* read radius from the keyboard */
     // prompt user 
     printf("Enter Radius: ");
     // get keyboard input
     scanf("%f", &radius);

     printf("Radius Right Value %f\n", radius);
     printf("Radius Left Value %p\n", &radius);
     

   /* compute and output diameter, circumference and area */
   printf("Diameter is: %.2f\n", 2 * radius);
   printf("Circumference is: %.2f\n", 2 * PI * radius);
   printf("Area is: %.2f\n", PI * radius * radius);

} 
