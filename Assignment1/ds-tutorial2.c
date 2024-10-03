#include <stdio.h>

int main(void)
{
    // Declare variables
    int hoursWorked = 0, overTimeHours;              // 'hoursWorked' stores hours worked by the employee, 'overTimeHours' for hours worked beyond 40 hours
    double hourlyRate = 0.0, totalSalary = 0.0, overTimeSalary = 0.0;   // 'hourlyRate' for employee's pay rate, 'totalSalary' for total pay, and 'overTimeSalary' for additional pay due to overtime
    
    // Start an infinite loop to continuously accept input
    while(1) {
        // Prompt user to enter the number of hours worked
        printf("Enter # of hours worked (-1 to end): ");
        scanf("%d", &hoursWorked);  // Read user input for hours worked

        // Check if the user wants to exit the loop (input -1 to end the program)
        if(hoursWorked == -1) {
            break;  // Exit the loop if input is -1
        }

        // Prompt user to enter hourly rate
        printf("Enter hourly rate of the worker ($00.00): ");
        scanf("%lf", &hourlyRate);  // Read user input for hourly rate

        // Check if the employee worked more than 40 hours (overtime calculation)
        if(hoursWorked > 40) {
            // Calculate the number of overtime hours
            overTimeHours = hoursWorked - 40;
            
            // Calculate overtime pay (1.5 times the hourly rate for overtime hours)
            overTimeSalary = (1.5 * hourlyRate) * overTimeHours;
            
            // Calculate the total salary by adding regular pay for the first 40 hours and overtime pay
            totalSalary = overTimeSalary + (hourlyRate * (hoursWorked - overTimeHours));
        } else {
            // If no overtime, just calculate the regular salary
            totalSalary = hourlyRate * hoursWorked;
        }

        // Display the calculated salary to the user
        printf("Salary is %.2f\n\n", totalSalary);
    }
}
